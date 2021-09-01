/* Subroutines for the gcc driver.
   Copyright (C) 2020-2021 Free Software Foundation, Inc.

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

#include "loongarch-opts.h"
#include "loongarch-driver.h"

int 
  loongarch_isa_int_driver = M_OPTION_NOT_SEEN,
  loongarch_isa_float_driver = M_OPTION_NOT_SEEN,
  loongarch_abi_int_driver = M_OPTION_NOT_SEEN,
  loongarch_abi_float_driver = M_OPTION_NOT_SEEN,
  loongarch_arch_driver = M_OPTION_NOT_SEEN,
  loongarch_tune_driver = M_OPTION_NOT_SEEN,
  loongarch_isa_ext_flags_driver = 0;



#define LARCH_DRIVER_SET_M_FLAG(OPTS_ARRAY, N_OPTS, FLAG, STR)  \
  for (int i = 0; i < (N_OPTS); i++)                            \
  {                                                             \
    if ((OPTS_ARRAY)[i] != 0)                                   \
       if (strcmp ((STR), (OPTS_ARRAY)[i]) == 0)                \
         (FLAG) = i;                                            \
  }

const char*
driver_set_m_flag (int argc, const char **argv)
{
  if (argc != 2)
    return "%eset_m_flag requires exactly 2 arguments.";

  if (strcmp (argv[0], "abi") == 0)
    {
      LARCH_DRIVER_SET_M_FLAG (
        loongarch_abi_int_strings, N_INT_ABI_TYPES, 
        loongarch_abi_int_driver, argv[1]
      )
    }

  else if (strcmp (argv[0], "fpu") == 0)
    {
      LARCH_DRIVER_SET_M_FLAG (
        loongarch_isa_float_strings, N_FLOAT_ISA_TYPES,
        loongarch_isa_float_driver, argv[1]
      )
    }

  else if (strcmp (argv[0], "float-abi") == 0)
    {
      LARCH_DRIVER_SET_M_FLAG (
        loongarch_abi_float_strings, N_FLOAT_ABI_TYPES,
        loongarch_abi_float_driver, argv[1]
      )
    }

  else if (strcmp (argv[0], "arch") == 0)
    {
      LARCH_DRIVER_SET_M_FLAG (
        loongarch_cpu_strings, N_CPU_TYPES,
        loongarch_arch_driver, argv[1]
      )
    }

  else if (strcmp (argv[0], "tune") == 0)
    {
      LARCH_DRIVER_SET_M_FLAG (
        loongarch_cpu_strings, N_CPU_TYPES,
        loongarch_tune_driver, argv[1]
      )
    }

  else 
    return "%eUnknown flag type to set_m_flag.";
  
  return "";
}

/* Use the public obstack from gcc driver (defined in gcc.c).
   This is for the allocation of returned strings. */
extern struct obstack opts_obstack;

const char*
driver_get_normalized_m_opts (int argc, const char **argv)
{
  if (argc != 0)
    return "%eget_normalized_m_opts requires no argument.";

  const char* retval = loongarch_handle_m_option_combinations (
    & loongarch_arch_driver,
    & loongarch_tune_driver,
    & loongarch_isa_int_driver,
    & loongarch_isa_float_driver,
    & loongarch_isa_ext_flags_driver,
    & loongarch_abi_int_driver,
    & loongarch_abi_float_driver
  );

  if (retval == 0)
     return "%einternal error";

  else if (retval[0] == '%')
     return retval;

  /* Output normalized option string */
  obstack_blank (&opts_obstack, 0);

  #define APPEND_LTR(S)   obstack_grow (&opts_obstack, (const void*) (S), sizeof((S))/sizeof(char) -1)
  #define APPEND_VAL(S)   obstack_grow (&opts_obstack, (const void*) (S), strlen((S)))

  /* We cannot prevent the user from changing abi-related options
     even if multilib is disabled by default,
     because we cannot assume the ABI of available libraries. */

  #ifdef __DISABLE_MULTILIB 
     if ((DEFAULT_ABI_INT != M_OPTION_NOT_SEEN 
          && loongarch_abi_int_driver != DEFAULT_ABI_INT)
      || (DEFAULT_ABI_FLOAT != M_OPTION_NOT_SEEN
          && loongarch_abi_float_driver != DEFAULT_ABI_FLOAT))
        APPEND_LTR (" %nABI change detected, you may end up linking to incompatible libraries.\n");
  #endif

  APPEND_LTR (" -mabi=");
  APPEND_VAL (loongarch_abi_int_strings[loongarch_abi_int_driver]);
  APPEND_LTR (" -march=");
  APPEND_VAL (loongarch_cpu_strings[loongarch_arch_driver]);
  APPEND_LTR (" -mtune=");
  APPEND_VAL (loongarch_cpu_strings[loongarch_tune_driver]);
  APPEND_LTR (" -mfloat-abi=");
  APPEND_VAL (loongarch_abi_float_strings[loongarch_abi_float_driver]);
  APPEND_LTR (" -mfpu=");
  APPEND_VAL (loongarch_isa_float_strings[loongarch_isa_float_driver]);

  obstack_1grow (&opts_obstack, '\0');

  char* normalized_opts = (char*) obstack_finish (&opts_obstack);
  return normalized_opts;

}
