bin_PROGRAMS = app1

AM_CPPFLAGS = -I @libp1_dir@ -I $(top_srcdir)/lib/libcirc1

app1_SOURCES = app1.cpp
app1_LDADD = -lcirc1 -lcirc2

app1_LDFLAGS = -L$(top_srcdir)/lib/libcirc1 -L$(top_srcdir)/lib/libcirc2 -Wl,-rpath=$(libp1_dir) 
