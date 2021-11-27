/* Common hooks for LoongArch.
   Copyright (C) 2021-2022 Free Software Foundation, Inc.

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

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "common/common-target.h"
#include "common/common-target-def.h"
#include "opts.h"
#include "flags.h"
#include "diagnostic-core.h"

#undef	TARGET_OPTION_OPTIMIZATION_TABLE
#define TARGET_OPTION_OPTIMIZATION_TABLE loongarch_option_optimization_table

/* Set default optimization options.  */
static const struct default_options loongarch_option_optimization_table[] =
{
  { OPT_LEVELS_ALL, OPT_fasynchronous_unwind_tables, NULL, 1 },
  { OPT_LEVELS_NONE, 0, NULL, 0 }
};

/* Implement TARGET_HANDLE_OPTION.  */

static bool
loongarch_handle_option (struct gcc_options *opts,
			 struct gcc_options *opts_set ATTRIBUTE_UNUSED,
			 const struct cl_decoded_option *decoded,
			 location_t loc ATTRIBUTE_UNUSED)
{
  size_t code = decoded->opt_index;
  int value = decoded->value;

  switch (code)
    {
    case OPT_mmemcpy:
      if (value)
	{
	  if (opts->x_optimize_size)
	    opts->x_target_flags |= MASK_MEMCPY;
	}
      else
	opts->x_target_flags &= ~MASK_MEMCPY;
      return true;

    default:
      return true;
    }
}

#undef TARGET_DEFAULT_TARGET_FLAGS
#define TARGET_DEFAULT_TARGET_FLAGS	MASK_CHECK_ZERO_DIV
#undef TARGET_HANDLE_OPTION
#define TARGET_HANDLE_OPTION loongarch_handle_option

struct gcc_targetm_common targetm_common = TARGETM_COMMON_INITIALIZER;
