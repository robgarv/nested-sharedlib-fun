AC_CONFIG_MACRO_DIR([share/m4])
AC_INIT( [circular], [1.0.0] )


LT_INIT

# The compiler must be set early or some standard tests fail
AC_PROG_CXX( g++ )

PACKAGE=circular
VERSION=0.1.0

NSFUN_ROOTDIR
libp1_dir=$nsfun_root/libp1
AC_SUBST(libp1_dir)
AC_MSG_NOTICE([Nested Sharedlib Fun Directory: $nsfun_root])
AM_INIT_AUTOMAKE

AC_PROG_CXX

AC_CONFIG_FILES([
  Makefile
  src/Makefile
  src/app1/Makefile
  src/app2/Makefile
  lib/Makefile
  lib/libcirc0/Makefile
  lib/libcirc1/Makefile
  lib/libcirc2/Makefile
], [echo timestamp >stamp-h])

AC_OUTPUT
