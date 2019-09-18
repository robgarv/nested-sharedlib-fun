AC_CONFIG_MACRO_DIR([share/m4])
AC_INIT( [prog1], [1.0.0] )


LT_INIT

# The compiler must be set early or some standard tests fail
AC_PROG_CXX( g++ )

PACKAGE=prog1
VERSION=0.1.0

libp1_dir=/home/rgarvey/code/sotest2/libp1
AC_SUBST(libp1_dir)
LPC_XBINDER
AM_INIT_AUTOMAKE

# INTI_REQUIRED_VERSION=1.0.7
# PKG_CHECK_MODULES(INTI, inti-1.0 >= $INTI_REQUIRED_VERSION)
# AC_SUBST(INTI_CFLAGS)
# AC_SUBST(INTI_LIBS)

AC_PROG_CXX

AC_CONFIG_FILES([
  Makefile
  src/Makefile
  src/prog1/Makefile
  lib/Makefile
  lib/libpa/Makefile
  lib/libpb/Makefile
], [echo timestamp >stamp-h])

AC_OUTPUT
