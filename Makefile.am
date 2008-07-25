# Search for autoconf macros in build-aux.
ACLOCAL_AMFLAGS = -I build-aux

SUBDIRS = 		\
	doc		\
	libltdl		\
	src		\
	tests

# Provide bootstrap with the generated package.
EXTRA_DIST = bootstrap

# Nothing to do in this directory.
all:

# -- Generate documentation
.PHONY: doc html
doc html:
	cd doc && $(MAKE) $(AM_MAKEFLAGS) $@
