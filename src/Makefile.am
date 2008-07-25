include $(top_srcdir)/build-aux/init.mk

SUBDIRS = null-plugin

lib_LTLIBRARIES = libframegrabber.la

HEADERS_include = framegrabber.hh

libframegrabber_la_SOURCES =  	doc.hh			\
				framegrabber.cc
libframegrabber_la_LIBADD = $(top_builddir)/libltdl/libltdl.la
