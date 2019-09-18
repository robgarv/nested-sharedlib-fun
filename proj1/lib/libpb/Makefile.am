lib_LTLIBRARIES = libpb.la

libpb_la_SOURCES = \
	reader.cpp \
	writer.cpp \
	simpleArray.cpp \
	simpleArray.h \
	simpleArrayEnc.cpp \
	simpleArrayDec.cpp \
	simpleArrayPrint.cpp \
	simpleArrayTest.cpp

BUILT_SOURCES = $(SCHEMAGENERATED)

SCHEMAGENERATED= \
	simpleArray.cpp \
	simpleArray.h \
	simpleArrayEnc.cpp \
	simpleArrayDec.cpp \
	simpleArrayPrint.cpp \
	simpleArrayTest.cpp

CLEANFILES = $(SCHEMAGENERATED)

# Listing the libraries by path and full name
# causes DT_NEEDED records to be omitted from the built
# shared library. This will cause undefined reference
# errors at application link time. 

libpb_la_LIBADD = @xbinder_libs@

# Using the -l options results in a library equipped
# with the necessary DT_NEEDED records. xbinder_libs
# has been redefined so the outcome is like this:
#libpb_la_LIBADD = $(xbinder_libdir)/rtXmlExpatIF_a.o \
#		-losysrt -losysrtxml -lexpat -losysrt 

libpb_la_LDFLAGS = -L$(xbinder_libdir)

AM_CPPFLAGS = -I @xbinder_includes@

$(SCHEMAGENERATED): $(srcdir)/simpleArray.xsd
	@xbinder_program@ $(srcdir)/simpleArray.xsd -cpp -x64 -xml -print -gentest -trace -o . 
