bin_PROGRAMS = prog1

AM_CPPFLAGS = -I @libp1_dir@ -I $(top_srcdir)/lib/libpa -I $(top_srcdir)/lib/libpb

prog1_SOURCES = prog1.cpp
prog1_LDADD = -lpa -lpb

# lpc_xbinder.m4 was modified to include definition of xbinder_ldflags to emit the -rpath
#prog1_LDFLAGS = -L$(top_srcdir)/lib/libpa -L$(top_srcdir)/lib/libpb -Wl,-rpath=$(libp1_dir) -Wl,-rpath=$(xbinder_libdir)
prog1_LDFLAGS = -L$(top_srcdir)/lib/libpa -L$(top_srcdir)/lib/libpb -Wl,-rpath=$(libp1_dir) @xbinder_ldflags@
