/* Subroutines for the gcc driver.
   Copyright (C) 2021-2023 Free Software Foundation, Inc.
   Contributed by Loongson Ltd.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>.  */

#define IN_TARGET_CODE 1

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "obstack.h"
#include "diagnostic-core.h"

#include "loongarch-opts.h"
#include "loongarch-driver.h"

static int
  opt_arch_driver = M_OPTION_NOT_SEEN,
  opt_tune_driver = M_OPTION_NOT_SEEN,
  opt_fpu_driver = M_OPTION_NOT_SEEN,
  opt_abi_base_driver = M_OPTION_NOT_SEEN,
  opt_abi_ext_driver = M_OPTION_NOT_SEEN,
  opt_cmodel_driver = M_OPTION_NOT_SEEN;

int opt_switches, opt_switches_set = 0;

/* This flag is set to 1 if we believe that the user might be avoiding
   linking (implicitly) against something from the startfile search paths.  */
static int no_link = 0;


/* Use the public obstack from the gcc driver (defined in gcc.c).
   This is for allocating space for the returned string.  */
extern struct obstack opts_obstack;

#define APPEND_LTR(S)				      \
  obstack_grow (&opts_obstack, (const void*) (S),     \
		sizeof ((S)) / sizeof (char) -1)

#define APPEND_VAL(S) \
  obstack_grow (&opts_obstack, (const void*) (S), strlen ((S)))

#define LARCH_DRIVER_SET_M_FLAG(IDX, STR, OPTS_ARRAY, N_OPTS)	\
  for (int i = 0; i < (N_OPTS); i++)				\
  {								\
    if ((OPTS_ARRAY)[i] != 0)					\
      if (strcmp ((STR), (OPTS_ARRAY)[i]) == 0)                 \
	(IDX) = i;						\
  }

const char*
driver_set_m_flag (int argc, const char **argv)
{
  gcc_assert (argc == 1);

  if (strcmp (argv[0], "no_link") == 0)
    {
      no_link = 1;
    }
  else
    {
      int switch_idx = M_OPTION_NOT_SEEN;

      LARCH_DRIVER_SET_M_FLAG (switch_idx, argv[0],
			       loongarch_switch_strings, N_SWITCH_TYPES);

      gcc_assert (switch_idx != M_OPTION_NOT_SEEN);
      opt_switches |= loongarch_switch_mask[switch_idx];
      opt_switches_set |= loongarch_switch_mask[switch_idx];
    }
  return "";
}

const char*
driver_unset_m_flag (int argc, const char **argv)
{
  gcc_assert (argc == 1);

  if (strcmp (argv[0], "no_link") == 0)
    {
      no_link = 1;
    }
  else
    {
      int switch_idx = M_OPTION_NOT_SEEN;

      LARCH_DRIVER_SET_M_FLAG (switch_idx, argv[0],
			       loongarch_switch_strings, N_SWITCH_TYPES);

      gcc_assert (switch_idx != M_OPTION_NOT_SEEN);
      opt_switches &= ~loongarch_switch_mask[switch_idx];
      opt_switches_set |= loongarch_switch_mask[switch_idx];
    }
  return "";
}

const char*
driver_set_m_parm (int argc, const char **argv)
{
  gcc_assert (argc == 2);

#undef MATCH_OPT
#define MATCH_OPT(NAME) \
  (strcmp (argv[0], OPTSTR_##NAME) == 0)

  if (MATCH_OPT (ABI_BASE))
    {
      LARCH_DRIVER_SET_M_FLAG (opt_abi_base_driver, argv[1],
			       loongarch_abi_base_strings, N_ABI_BASE_OPTS)
    }
  else if (MATCH_OPT (ISA_EXT_FPU))
    {
      LARCH_DRIVER_SET_M_FLAG (opt_fpu_driver, argv[1],
			       loongarch_isa_ext_strings, N_ISA_EXT_FPU_TYPES)
    }
  else if (MATCH_OPT (ARCH))
    {
      LARCH_DRIVER_SET_M_FLAG (opt_arch_driver, argv[1],
			       loongarch.ccpu_strings, N_ARCH_TYPES)
    }
  else if (MATCH_OPT (TUNE))
    {
      LARCH_DRIVER_SET_M_FLAG (opt_tune_driver, argv[1],
			       loongarch.ccpu_strings, N_TUNE_TYPES)
    }
  else if (MATCH_OPT (CMODEL))
    {
      LARCH_DRIVER_SET_M_FLAG (opt_cmodel_driver, argv[1],
			       loongarch.ccmodel_strings, N_CMODEL_TYPES)
    }
  else
    gcc_unreachable ();

  return 0;
}

const char*
driver_get_normalized_m_opts (int argc, const char **argv)
{
  if (argc != 0)
    {
      (void) argv;  /* To make compiler shut up about unused argument.  */
      return " %eget_normalized_m_opts requires no argument.\n";
    }

  loongarch_config_target (& la_target,
			   opt_switches,
                           opt_switches_set,
			   opt_arch_driver,
			   opt_tune_driver,
			   opt_fpu_driver,
			   opt_abi_base_driver,
			   opt_abi_ext_driver,
			   opt_cmodel_driver,
			   !no_link /* follow_multilib_list */);

  /* Output normalized option strings.  */
  obstack_blank (&opts_obstack, 0);

#undef APPEND_LTR
#define APPEND_LTR(S) \
  obstack_grow (&opts_obstack, (const void*) (S), \
		sizeof ((S)) / sizeof (char) -1)

#undef APPEND_VAL
#define APPEND_VAL(S) \
  obstack_grow (&opts_obstack, (const void*) (S), strlen ((S)))

#undef APPEND_OPT
#define APPEND_OPT(NAME) \
   APPEND_LTR (" %<m" OPTSTR_##NAME "=* " \
	       " -m" OPTSTR_##NAME "=")

#undef APPEND_SWITCH
#define APPEND_SWITCH(S) \
   APPEND_LTR (" %<m" S " -m" S)

  for (int i = 0; i < N_SWITCH_TYPES; i++)
    {
      APPEND_LTR (" %<m");
      APPEND_VAL (loongarch_switch_strings[i]);
    }

  APPEND_OPT (ABI_BASE);
  APPEND_VAL (loongarch_abi_base_strings[la_target.abi.base]);

  APPEND_OPT (ARCH);
  APPEND_VAL (loongarch_cpu_strings[la_target.cpu_arch]);

  APPEND_OPT (ISA_EXT_FPU);
  APPEND_VAL (loongarch_isa_ext_strings[la_target.isa.fpu]);

  if (la_target.isa.simd)
    {
      APPEND_LTR (" %<m" OPTSTR_LSX " %<m" OPTSTR_LASX " -m");
      APPEND_VAL (loongarch_isa_ext_strings[la_target.isa.simd]);
    }

  APPEND_OPT (CMODEL);
  APPEND_VAL (loongarch_cmodel_strings[la_target.cmodel]);

  APPEND_OPT (TUNE);
  APPEND_VAL (loongarch_cpu_strings[la_target.cpu_tune]);

  obstack_1grow (&opts_obstack, '\0');

  return XOBFINISH (&opts_obstack, const char *);
}
