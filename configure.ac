# Don't expend macros beginning by LIBFRAMEGRABBER_.
m4_pattern_forbid([^LIBFRAMEGRABBER_])
AC_PREREQ([2.59])

## --------------------- ##
## Package configuration ##
## --------------------- ##
AC_INIT([libframegrabber], [0.1], [thomas.moulard@gmail.com], [libframegrabber])

# Auxiliary files.
AC_CONFIG_AUX_DIR([build-aux])

# Automake.
AM_INIT_AUTOMAKE([1.9.6 dist-bzip2 no-dist-gzip -Wall nostdinc])

## ------------- ##
## C++ compiler  ##
## ------------- ##

# Search for a C++ compiler.
AC_LANG([C++])
AC_PROG_CXX

# Speed-up compilation.
if test "$GXX" = yes; then
  CXXFLAGS="$CXXFLAGS -pipe"
fi

# Customize warnings.
LIBFRAMEGRABBER_CXX_WARNINGS([[-Wall],
                   [-Werror],
                   [-Wcast-align],
                   [-Wcast-qual],
                   [-Wformat],
                   [-Wmissing-prototypes],
                   [-Wstrict-prototypes],
                   [-Wwrite-strings],
                   [-Wbad-function-cast],
                   [-Wmissing-declarations],
                   [-Wnested-externs]])

## ------------------- ##
## Additionnal tools.  ##
## ------------------- ##

# Search for Libtool.
AC_PROG_LIBTOOL

# Use ltdl.
AC_LIB_LTDL
AC_CONFIG_SUBDIRS(libltdl)

## ------------ ##
## Test-suite.  ##
## ------------ ##

AC_CONFIG_TESTDIR([tests])
AM_MISSING_PROG([AUTOM4TE], [autom4te])


## -------------- ##
## Write output.  ##
## -------------- ##

# Create config.h
AC_CONFIG_HEADERS([config.h])

# Create Makefiles.
#   packages/Makefile
AC_CONFIG_FILES([
  Makefile
   doc/Makefile
   src/Makefile
   src/null-plugin/Makefile
   tests/Makefile
    tests/package.m4
    tests/atlocal
])

# Write files.
AC_OUTPUT
