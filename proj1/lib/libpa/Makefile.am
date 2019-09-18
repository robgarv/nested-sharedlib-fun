lib_LTLIBRARIES = libpa.la

libpa_la_SOURCES = CPA.cpp

# User this, and libp1.so doesn't show up as needed
# libpa_la_LIBADD = $(libp1_dir)/libp1.so

# Use this, and libp1.so DOES show up as needed
# (readelf -d libpa.so)
libpa_la_LIBADD = -lp1

libpa_la_LDFLAGS = -L$(libp1_dir)

AM_CPPFLAGS = -I @libp1_dir@
