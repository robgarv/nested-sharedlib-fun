#!/bin/bash

if [ $# -ne 3 ]; then
  echo "ERROR: fixup-sharedlibs.sh args are NEEDED library path, NEEDED library, and TARGET library"
  echo "fixup-sharedlibs.sh needed target"
  exit 1
fi

libroot=$(dirname $PWD);
echo "libroot: "$libroot;
libpath=$libroot/$1/.libs
echo "libpath: $libpath"
patchelf --remove-rpath .libs/$3
patchelf --add-needed $2 .libs/$3
patchelf --force-rpath --set-rpath $libpath .libs/$3;
exit 0
