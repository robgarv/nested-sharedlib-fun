bin_PROGRAMS = app2

AM_CPPFLAGS = -I @libp1_dir@ -I $(top_srcdir)/lib/libcirc2

app2_SOURCES = app2.cpp
app2_LDADD = -lcirc2

# lpc_xbinder.m4 was modified to include definition of xbinder_ldflags to emit the -rpath
#prog1_LDFLAGS = -L$(top_srcdir)/lib/libpa -L$(top_srcdir)/lib/libpb -Wl,-rpath=$(libp1_dir) -Wl,-rpath=$(xbinder_libdir)
app2_LDFLAGS = -L$(top_srcdir)/lib/libcirc2 -Wl,-rpath=$(libp1_dir) 
