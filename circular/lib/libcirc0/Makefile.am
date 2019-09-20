lib_LTLIBRARIES = libcirc0.la

libcirc0_la_SOURCES = Circ0A.cpp Circ0B.cpp

# User this, and libp1.so doesn't show up as needed
# libcirc0_la_LIBADD = $(libp1_dir)/libp1.so

# Use this, and libp1.so DOES show up as needed
# (readelf -d libcirc0.so)
libcirc0_la_LIBADD = -lp1 -lcirc1 -lcirc2

libcirc0_la_LDFLAGS = -L$(libp1_dir) -L$(top_srcdir)/lib/libcirc1 -L$(top_srcdir)/lib/libcirc2

AM_CPPFLAGS = -I @libp1_dir@ -I $(top_srcdir)/lib/libcirc1 -I $(top_srcdir)/lib/libcirc2
