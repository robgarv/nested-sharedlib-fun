#!/bin/bash

if [ $# -ne 3 ]; then
  echo "ERROR: fixup-sharedlibs.sh args are NEEDED library path, NEEDED library, and TARGET library"
  echo "fixup-sharedlibs.sh needed target"
  exit 1
fi

echo "Current dir: $PWD"
# Check to determine if DT_NEEDED is truly missing. If not, bail out
libroot=$(dirname $PWD);
echo "libroot: "$libroot;
libpath=$libroot/$1/.libs
echo "libpath: $libpath"

# Check to determine if DT_NEEDED is truly missing. If not, skip --add-needed
ncount=$(readelf -d .libs/$3 | grep NEEDED | grep $2 | wc -l)
if [ $ncount -ge 1 ]; then
  echo "WARNING: fixup_sharedlibs sees DT_NEEDED for $2"
else
  patchelf --add-needed $2 .libs/$3  
fi

# rcount should be 0 or 1. Multiple rpaths can be expressed, delimited by colons
rcount=$(readelf -d .libs/$3 | fgrep RPATH | wc -l)
if [ $rcount -eq 1 ]; then
  rpath=$(readelf -d .libs/$3 | fgrep RPATH | awk  'BEGIN { FS = "[" };{ print $2 }' | sed -e 's/]//')
  if [ -z "$rpath##*$1*" ]; then
    # Needed library is not in path so add it
    echo "Adding rpath"
    rpath="$rpath:$libpath"
    echo "$rpath"
  else
    echo "rpath already contains $1"
  fi
elif [ $rcount -eq 0 ]; then
  echo "Adding to empty rpath $libpath"
  rpath="$libpath"
else
  echo "WARNING: fixup_sharedlibs sees unexpected rpath count: $rcount";
fi
patchelf --remove-rpath .libs/$3
patchelf --force-rpath --set-rpath $rpath .libs/$3;
exit 0
