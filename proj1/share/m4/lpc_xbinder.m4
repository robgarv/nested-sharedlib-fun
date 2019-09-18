# BitKeeper: bhashyam@apu.gamelogic.com|share/m4/lpc_xbinder.m4|20150403123828|12602
# Copyright(C) 2004 Gamelogic Inc. All rights reserved.
# LPC_XBINDER - Sets variables for use in building/linking xbinder

AC_DEFUN([LPC_XBINDER],[
  xbinder_root=/common/lib/xbinder/xbv260
  xbinder_includes=$xbinder_root
  AC_SUBST(xbinder_includes)

  xbinder_libdir=$xbinder_root/cpp/lib

#  RCG Note:
#  Experimental: To solve linker problems, link to shared librariers.
#  The code below is commented out for historical purposes and will
#  be deleted when this has been vetted more completely. 
#  
#  xbinder_libs="$xbinder_libdir/rtXmlExpatIF_a.o $xbinder_libdir/libosysrt.a"
#  xbinder_libs="$xbinder_libs $xbinder_libdir/libosysrtxml.a"
#  xbinder_libs="$xbinder_libs $xbinder_libdir/libexpat.a"
#  xbinder_libs="$xbinder_libs $xbinder_libdir/libosysrt.a"

#  xbinder_libs="$xbinder_libdir/rtXmlExpatIF_a.o $xbinder_libdir/libosysrt.so"
#  xbinder_libs="$xbinder_libs $xbinder_libdir/libosysrtxml.so"
#  xbinder_libs="$xbinder_libs $xbinder_libdir/libexpat.so"
#  xbinder_libs="$xbinder_libs $xbinder_libdir/libosysrt.so"

  xbinder_libs="$xbinder_libdir/rtXmlExpatIF_a.o -losysrt -losysrtxml -lexpat"
  xbinder_ldflags="-Wl,-rpath=$xbinder_libdir"

  AC_SUBST(xbinder_libs)
  AC_SUBST(xbinder_libdir)
  AC_SUBST(xbinder_ldflags)
 
  xbinder_program="env OSLICDIR=$xbinder_root/bin $xbinder_root/bin/xbinder"
  AC_SUBST(xbinder_program)

  # Define __STDC_LIMIT_MACROS in order to work around a bug in
  #   /common/lib/xbinder/xbv153/rtxsrc/osSysTypes.h
  CFLAGS="$CFLAGS -D__STDC_LIMIT_MACROS"
  CXXFLAGS="$CXXFLAGS -D__STDC_LIMIT_MACROS"
])
