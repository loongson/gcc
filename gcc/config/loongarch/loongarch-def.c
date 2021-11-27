/* LoongArch static properties.
   Copyright (C) 2021 Free Software Foundation, Inc.
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

#include "loongarch-def.h"
#include "loongarch-str.h"

/* CPU property tables.  */
const char*
loongarch_cpu_strings[N_TUNE_TYPES] = {
  [CPU_NATIVE]		  = STR_CPU_NATIVE,
  [CPU_LOONGARCH64]	  = STR_CPU_LOONGARCH64,
  [CPU_LA464]		  = STR_CPU_LA464,
};

struct loongarch_isa
loongarch_cpu_default_isa[N_ARCH_TYPES] = {
  [CPU_LOONGARCH64] = {
      .base = ISA_BASE_LA64V100,
      .fpu = ISA_EXT_FPU64,
  },
  [CPU_LA464] = {
      .base = ISA_BASE_LA64V100,
      .fpu = ISA_EXT_FPU64,
  },
};

struct loongarch_cache
loongarch_cpu_cache[N_TUNE_TYPES] = {
  [CPU_LOONGARCH64] = {
      .l1d_line_size = 64,
      .l1d_size = 64,
      .l2d_size = 256,
  },
  [CPU_LA464] = {
      .l1d_line_size = 64,
      .l1d_size = 64,
      .l2d_size = 256,
  },
};

/* The following properties cannot be looked up directly using "cpucfg".
 So it is necessary to provide a default value for "unknown native"
 tune targets (i.e. -mtune=native while PRID does not correspond to
 any known "-mtune" type).  */

struct loongarch_rtx_cost_data
loongarch_cpu_rtx_cost_data[N_TUNE_TYPES] = {
  [CPU_NATIVE] = {
      DEFAULT_COSTS
  },
  [CPU_LOONGARCH64] = {
      DEFAULT_COSTS
  },
  [CPU_LA464] = {
      DEFAULT_COSTS
  },
};

int
loongarch_cpu_issue_rate[N_TUNE_TYPES] = {
  [CPU_NATIVE]	      = 4,
  [CPU_LOONGARCH64]   = 4,
  [CPU_LA464]	      = 4,
};

int
loongarch_cpu_multipass_dfa_lookahead[N_TUNE_TYPES] = {
  [CPU_NATIVE]	      = 4,
  [CPU_LOONGARCH64]   = 4,
  [CPU_LA464]	      = 4,
};

/* Wiring string definitions from loongarch-str.h to global arrays
   with standard index values from loongarch-opts.h, so we can
   print config-related messages and do ABI self-spec filtering
   from the driver in a self-consistent manner.  */

const char*
loongarch_isa_base_strings[N_ISA_BASE_TYPES] = {
  [ISA_BASE_LA64V100] = STR_ISA_BASE_LA64V100,
};

const char*
loongarch_isa_ext_strings[N_ISA_EXT_TYPES] = {
  [ISA_EXT_FPU64] = STR_ISA_EXT_FPU64,
  [ISA_EXT_FPU32] = STR_ISA_EXT_FPU32,
  [ISA_EXT_NOFPU] = STR_ISA_EXT_NOFPU,
};

const char*
loongarch_abi_base_strings[N_ABI_BASE_TYPES] = {
  [ABI_BASE_LP64D] = STR_ABI_BASE_LP64D,
  [ABI_BASE_LP64F] = STR_ABI_BASE_LP64F,
  [ABI_BASE_LP64S] = STR_ABI_BASE_LP64S,
};

const char*
loongarch_abi_ext_strings[N_ABI_EXT_TYPES] = {
  [ABI_EXT_BASE] = STR_ABI_EXT_BASE,
};

const char*
loongarch_cmodel_strings[] = {
  [CMODEL_NORMAL]	  = STR_CMODEL_NORMAL,
  [CMODEL_TINY]		  = STR_CMODEL_TINY,
  [CMODEL_TINY_STATIC]	  = STR_CMODEL_TS,
  [CMODEL_LARGE]	  = STR_CMODEL_LARGE,
  [CMODEL_EXTREME]	  = STR_CMODEL_EXTREME,
};

const char*
loongarch_switch_strings[] = {
  [SW_SOFT_FLOAT]	  = OPTSTR_SOFT_FLOAT,
  [SW_SINGLE_FLOAT]	  = OPTSTR_SINGLE_FLOAT,
  [SW_DOUBLE_FLOAT]	  = OPTSTR_DOUBLE_FLOAT,
};


/* ABI-related definitions.  */
const struct loongarch_isa
abi_minimal_isa[N_ABI_BASE_TYPES][N_ABI_EXT_TYPES] = {
  [ABI_BASE_LP64D] = {
      [ABI_EXT_BASE] = {.base = ISA_BASE_LA64V100, .fpu = ISA_EXT_FPU64},
  },
  [ABI_BASE_LP64F] = {
      [ABI_EXT_BASE] = {.base = ISA_BASE_LA64V100, .fpu = ISA_EXT_FPU32},
  },
  [ABI_BASE_LP64S] = {
      [ABI_EXT_BASE] = {.base = ISA_BASE_LA64V100, .fpu = ISA_EXT_NOFPU},
  },
};
