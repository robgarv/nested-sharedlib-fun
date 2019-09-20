lib_LTLIBRARIES = libcirc2.la

libcirc2_la_SOURCES = Circ2A.cpp


AM_CPPFLAGS = -I @libp1_dir@ -I $(top_srcdir)/lib/libcirc0

.PHONY: all libpost

all: libpost

libpost:
	$(top_srcdir)/sh/fixup-sharedlibs.sh libcirc0 libcirc0.so libcirc2.so