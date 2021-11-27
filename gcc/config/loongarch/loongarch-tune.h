/* Definitions for microarchitecture-related data structures.
   Copyright (C) 2021-2022 Free Software Foundation, Inc.
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

#ifndef LOONGARCH_TUNE_H
#define LOONGARCH_TUNE_H

#ifdef __cplusplus
extern "C" {
#endif

/* RTX costs of various operations on the different architectures.  */
struct loongarch_rtx_cost_data
{
  unsigned short fp_add;
  unsigned short fp_mult_sf;
  unsigned short fp_mult_df;
  unsigned short fp_div_sf;
  unsigned short fp_div_df;
  unsigned short int_mult_si;
  unsigned short int_mult_di;
  unsigned short int_div_si;
  unsigned short int_div_di;
  unsigned short branch_cost;
  unsigned short memory_latency;
};

/* Default RTX cost initializer.  */
#define COSTS_N_INSNS(N) ((N) * 4)
#define DEFAULT_COSTS				\
    .fp_add		= COSTS_N_INSNS (1),	\
    .fp_mult_sf		= COSTS_N_INSNS (2),	\
    .fp_mult_df		= COSTS_N_INSNS (2),	\
    .fp_div_sf		= COSTS_N_INSNS (4),	\
    .fp_div_df		= COSTS_N_INSNS (4),	\
    .int_mult_si	= COSTS_N_INSNS (1),	\
    .int_mult_di	= COSTS_N_INSNS (1),	\
    .int_div_si		= COSTS_N_INSNS (1),	\
    .int_div_di		= COSTS_N_INSNS (1),	\
    .branch_cost	= 2,			\
    .memory_latency	= 4

/* Costs to use when optimizing for size.  */
extern const struct loongarch_rtx_cost_data loongarch_rtx_cost_optimize_size;

/* Cache size record of known processor models.  */
struct loongarch_cache {
    int l1d_line_size;  /* bytes */
    int l1d_size;       /* KiB */
    int l2d_size;       /* kiB */
};

#ifdef __cplusplus
}
#endif
#endif /* LOONGARCH_TUNE_H */
