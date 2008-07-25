include $(top_srcdir)/build-aux/init.mk
include $(top_srcdir)/build-aux/autotest.mk

# Package the following files.
EXTRA_DIST += package.m4.in

# Clean atconfig (do not distribute it).
CLEANFILES += atconfig

# null-plugin
check_PROGRAMS = null-plugin
null_plugin_SOURCES = null-plugin.cc
null_plugin_LDADD = $(top_builddir)/src/libframegrabber.la


# ------------ #
# Test suite.  #
# ------------ #

TESTSUITE_AT = null-plugin.at
