/* Subroutine headers for the gcc driver.
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

#ifndef LOONGARCH_DRIVER_H
#define LOONGARCH_DRIVER_H

extern const char*
driver_set_m_flag (int argc, const char **argv);

extern const char*
driver_get_normalized_m_opts (int argc, const char **argv);

#define EXTRA_SPEC_FUNCTIONS \
  { "set_m_flag", driver_set_m_flag  }, \
  { "get_normalized_m_opts", driver_get_normalized_m_opts  },

/* Pre-process ABI-related options.  */
#define DRIVER_HANDLE_MACHINE_OPTIONS \
  " %{c|S|E|nostdlib: %:set_m_flag(no_link)}" \
  " %{nostartfiles: %{nodefaultlibs: %:set_m_flag(no_link)}}" \
  " %{mabi=*: %:set_m_flag(abi=%*)}" \
  " %{march=*: %:set_m_flag(arch=%*)}" \
  " %{mtune=*: %:set_m_flag(tune=%*)}" \
  " %{mfpu=*: %:set_m_flag(fpu=%*)}" \
  " %{msoft-float: %:set_m_flag(soft-float)}" \
  " %{msingle-float: %:set_m_flag(single-float)}" \
  " %{mdouble-float: %:set_m_flag(double-float)}" \
  " %:get_normalized_m_opts()"

#define DRIVER_SELF_SPECS \
  DRIVER_HANDLE_MACHINE_OPTIONS

/* ABI spec strings.  */
#define ABI_GRLEN_SPEC \
  "%{mabi=lp64*:64}"   \

#define ABI_SPEC \
  "%{mabi=lp64d:lp64d}" \
  "%{mabi=lp64f:lp64f}" \
  "%{mabi=lp64s:lp64s}" \

#endif /* LOONGARCH_DRIVER_H */

