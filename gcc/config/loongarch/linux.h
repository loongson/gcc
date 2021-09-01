/* Definitions for LoongArch running Linux-based GNU systems with ELF format.
   Copyright (C) 1998-2018 Free Software Foundation, Inc.

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

/* Default system library search paths. */
#if DEFAULT_ISA_INT == ABI_LP64
#define STANDARD_STARTFILE_PREFIX_1 "/lib64/"
#define STANDARD_STARTFILE_PREFIX_2 "/usr/lib64/"
#else
#define STANDARD_STARTFILE_PREFIX_1 "/lib/"
#define STANDARD_STARTFILE_PREFIX_2 "/usr/lib/"
#endif

/* Define this to be nonzero if static stack checking is supported.  */
#define STACK_CHECK_STATIC_BUILTIN 1

/* FIXME*/
/* The default value isn't sufficient in 64-bit mode.  */
#define STACK_CHECK_PROTECT (TARGET_64BIT ? 16 * 1024 : 12 * 1024)
