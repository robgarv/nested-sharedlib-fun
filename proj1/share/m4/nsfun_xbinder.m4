AC_DEFUN([NSFUN_XBINDER],[
  xbinder_root=/common/lib/xbinder/xbv260
  xbinder_includes=$xbinder_root
  AC_SUBST(xbinder_includes)

  xbinder_libdir=$xbinder_root/cpp/lib

#  Linking in this manner results in DT_NEEDED records not being
#  included in built shared library ELF files. 

#  xbinder_libs="$xbinder_libdir/rtXmlExpatIF_a.o $xbinder_libdir/libosysrt.so"
#  xbinder_libs="$xbinder_libs $xbinder_libdir/libosysrtxml.so"
#  xbinder_libs="$xbinder_libs $xbinder_libdir/libexpat.so"
#  xbinder_libs="$xbinder_libs $xbinder_libdir/libosysrt.so"

# Linking in this way results in DT_NEEDED records being properly included
# in build shared library ELF files.

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
