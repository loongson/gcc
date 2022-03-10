/* Test for LoongArch intrinsics. */

/* { dg-do compile } */

/* { dg-final { scan-assembler-times "test_rdtime_d:.*rdtime\\.d.*\\.size	test_rdtime_d" 1 } } */
/* { dg-final { scan-assembler-times "test_rdtimeh_w:.*rdtimeh\\.w.*\\.size	test_rdtimeh_w" 1 } } */
/* { dg-final { scan-assembler-times "test_rdtimel_w:.*rdtimel\\.w.*\\.size	test_rdtimel_w" 1 } } */
/* { dg-final { scan-assembler-times "test_movfcsr2gr:.*movfcsr2gr.*\\.size	test_movfcsr2gr" 1 } } */
/* { dg-final { scan-assembler-times "test_movgr2fcsr:.*movgr2fcsr.*\\.size	test_movgr2fcsr" 1 } } */
/* { dg-final { scan-assembler-times "test_dcacop:.*cacop.*\\.size	test_dcacop" 1 } } */
/* { dg-final { scan-assembler-times "test_cpucfg:.*cpucfg.*\\.size	test_cpucfg" 1 } } */
/* { dg-final { scan-assembler-times "test_asrtle_d:.*asrtle\\.d.*\\.size	test_asrtle_d" 1 } } */
/* { dg-final { scan-assembler-times "test_asrtgt_d:.*asrtgt\\.d.*\\.size	test_asrtgt_d" 1 } } */
/* { dg-final { scan-assembler-times "test_dlddir:.*lddir.*\\.size	test_dlddir" 1 } } */
/* { dg-final { scan-assembler-times "test_dldpte:.*ldpte.*\\.size	test_dldpte" 1 } } */
/* { dg-final { scan-assembler-times "test_crc_w_b_w:.*crc\\.w\\.b\\.w.*\\.size	test_crc_w_b_w" 1 } } */
/* { dg-final { scan-assembler-times "test_crc_w_h_w:.*crc\\.w\\.h\\.w.*\\.size	test_crc_w_h_w" 1 } } */
/* { dg-final { scan-assembler-times "test_crc_w_w_w:.*crc\\.w\\.w\\.w.*\\.size	test_crc_w_w_w" 1 } } */
/* { dg-final { scan-assembler-times "test_crc_w_d_w:.*crc\\.w\\.d\\.w.*\\.size	test_crc_w_d_w" 1 } } */
/* { dg-final { scan-assembler-times "test_crcc_w_b_w:.*crcc\\.w\\.b\\.w.*\\.size	test_crcc_w_b_w" 1 } } */
/* { dg-final { scan-assembler-times "test_crcc_w_h_w:.*crcc\\.w\\.h\\.w.*\\.size	test_crcc_w_h_w" 1 } } */
/* { dg-final { scan-assembler-times "test_crcc_w_w_w:.*crcc\\.w\\.w\\.w.*\\.size	test_crcc_w_w_w" 1 } } */
/* { dg-final { scan-assembler-times "test_crcc_w_d_w:.*crcc\\.w\\.d\\.w.*\\.size	test_crcc_w_d_w" 1 } } */
/* { dg-final { scan-assembler-times "test_csrrd:.*csrrd.*\\.size	test_csrrd" 1 } } */
/* { dg-final { scan-assembler-times "test_csrwr:.*csrwr.*\\.size	test_csrwr" 1 } } */
/* { dg-final { scan-assembler-times "test_csrxchg:.*csrxchg.*\\.size	test_csrxchg" 1 } } */
/* { dg-final { scan-assembler-times "test_dcsrrd:.*csrrd.*\\.size	test_dcsrrd" 1 } } */
/* { dg-final { scan-assembler-times "test_dcsrwr:.*csrwr.*\\.size	test_dcsrwr" 1 } } */
/* { dg-final { scan-assembler-times "test_dcsrxchg:.*csrxchg.*\\.size	test_dcsrxchg" 1 } } */
/* { dg-final { scan-assembler-times "test_iocsrrd_b:.*iocsrrd\\.b.*\\.size	test_iocsrrd_b" 1 } } */
/* { dg-final { scan-assembler-times "test_iocsrrd_h:.*iocsrrd\\.h.*\\.size	test_iocsrrd_h" 1 } } */
/* { dg-final { scan-assembler-times "test_iocsrrd_w:.*iocsrrd\\.w.*\\.size	test_iocsrrd_w" 1 } } */
/* { dg-final { scan-assembler-times "test_iocsrrd_d:.*iocsrrd\\.d.*\\.size	test_iocsrrd_d" 1 } } */
/* { dg-final { scan-assembler-times "test_iocsrwr_b:.*iocsrwr\\.b.*\\.size	test_iocsrwr_b" 1 } } */
/* { dg-final { scan-assembler-times "test_iocsrwr_h:.*iocsrwr\\.h.*\\.size	test_iocsrwr_h" 1 } } */
/* { dg-final { scan-assembler-times "test_iocsrwr_w:.*iocsrwr\\.w.*\\.size	test_iocsrwr_w" 1 } } */
/* { dg-final { scan-assembler-times "test_iocsrwr_d:.*iocsrwr\\.d.*\\.size	test_iocsrwr_d" 1 } } */
/* { dg-final { scan-assembler-times "test_dbar:.*dbar.*\\.size	test_dbar" 1 } } */
/* { dg-final { scan-assembler-times "test_ibar:.*ibar.*\\.size	test_ibar" 1 } } */
/* { dg-final { scan-assembler-times "test_syscall:.*syscall.*\\.size	test_syscall" 1 } } */
/* { dg-final { scan-assembler-times "test_break:.*break.*\\.size	test_break" 1 } } */
/* { dg-final { scan-assembler-times "test_tlbsrch:.*tlbsrch.*\\.size	test_tlbsrch" 1 } } */
/* { dg-final { scan-assembler-times "test_tlbrd:.*tlbrd.*\\.size	test_tlbrd" 1 } } */
/* { dg-final { scan-assembler-times "test_tlbwr:.*tlbwr.*\\.size	test_tlbwr" 1 } } */
/* { dg-final { scan-assembler-times "test_tlbfill:.*tlbfill.*\\.size	test_tlbfill" 1 } } */
/* { dg-final { scan-assembler-times "test_tlbclr:.*tlbclr.*\\.size	test_tlbclr" 1 } } */
/* { dg-final { scan-assembler-times "test_tlbflush:.*tlbflush.*\\.size	test_tlbflush" 1 } } */

#include<larchintrin.h>

__drdtime_t
test_rdtime_d ()
{
  return __rdtime_d ();
}

__rdtime_t
test_rdtimeh_w ()
{
  return __rdtimeh_w ();
}

__rdtime_t
test_rdtimel_w ()
{
  return __rdtimel_w ();
}

unsigned int
test_movfcsr2gr ()
{
  return __movfcsr2gr (1);
}

void
test_movgr2fcsr (unsigned int _1)
{
  __movgr2fcsr (1, _1);
}

void
test_dcacop (unsigned long int _1)
{
  __dcacop (1, _1, 1);
}

unsigned int
test_cpucfg (unsigned int _1)
{
  return __cpucfg (_1);
}

void
test_asrtle_d (long int _1, long int _2)
{
  __asrtle_d (_1, _2);
}

void
test_asrtgt_d (long int _1, long int _2)
{
  __asrtgt_d (_1, _2);
}

long int
test_dlddir (long int _1)
{
  return __dlddir (_1, 1);
}

void
test_dldpte (long int _1)
{
  __dldpte (_1, 1);
}

int
test_crc_w_b_w (char _1, int _2)
{
  return __crc_w_b_w (_1, _2);
}

int
test_crc_w_h_w (short _1, int _2)
{
  return __crc_w_h_w (_1, _2);
}

int
test_crc_w_w_w (int _1, int _2)
{
  return __crc_w_w_w (_1, _2);
}

int
test_crc_w_d_w (long int _1, int _2)
{
  return __crc_w_d_w (_1, _2);
}

int
test_crcc_w_b_w (char _1, int _2)
{
  return __crcc_w_b_w (_1, _2);
}

int
test_crcc_w_h_w (short _1, int _2)
{
  return __crcc_w_h_w (_1, _2);
}

int
test_crcc_w_w_w (int _1, int _2)
{
  return __crcc_w_w_w (_1, _2);
}

int
test_crcc_w_d_w (long int _1, int _2)
{
  return __crcc_w_d_w (_1, _2);
}

unsigned int
test_csrrd ()
{
  return __csrrd (1);
}

unsigned int
test_csrwr (unsigned int _1)
{
  return __csrwr (_1, 1);
}

unsigned int
test_csrxchg (unsigned int _1, unsigned int _2)
{
  return __csrxchg (_1, _2, 1);
}

unsigned long int
test_dcsrrd ()
{
  return __dcsrrd (1);
}

unsigned long int
test_dcsrwr (unsigned long int _1)
{
  return __dcsrwr (_1, 1);
}

unsigned long int
test_dcsrxchg (unsigned long int _1, unsigned long int _2)
{
  return __dcsrxchg (_1, _2, 1);
}

unsigned char
test_iocsrrd_b (unsigned int _1)
{
  return __iocsrrd_b (_1);
}

unsigned char
test_iocsrrd_h (unsigned int _1)
{
  return __iocsrrd_h (_1);
}

unsigned int
test_iocsrrd_w (unsigned int _1)
{
  return __iocsrrd_w (_1);
}

unsigned long int
test_iocsrrd_d (unsigned int _1)
{
  return __iocsrrd_d (_1);
}

void
test_iocsrwr_b (unsigned char _1, unsigned int _2)
{
  __iocsrwr_b (_1, _2);
}

void
test_iocsrwr_h (unsigned short _1, unsigned int _2)
{
  __iocsrwr_h (_1, _2);
}

void
test_iocsrwr_w (unsigned int _1, unsigned int _2)
{
  __iocsrwr_w (_1, _2);
}

void
test_iocsrwr_d (unsigned long int _1, unsigned int _2)
{
  __iocsrwr_d (_1, _2);
}

void
test_dbar ()
{
  __dbar (1);
}

void
test_ibar ()
{
  __ibar (1);
}

void
test_syscall ()
{
  __syscall (1);
}

void
test_break ()
{
  __break (1);
}

void
test_tlbsrch ()
{
  __tlbsrch ();
}

void
test_tlbrd ()
{
  __tlbrd ();
}

void
test_tlbwr ()
{
  __tlbwr ();
}

void
test_tlbfill ()
{
  __tlbfill ();
}

void
test_tlbclr ()
{
  __tlbclr ();
}

void
test_tlbflush ()
{
  __tlbflush ();
}
