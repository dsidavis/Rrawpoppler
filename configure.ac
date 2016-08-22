AC_INIT(src/PDFDoc.cc)

AC_PATH_PROG(PKG_CONFIG, pkg-config, [echo "Cannot find pkg-config"])


PKG_CPPFLAGS=`$PKG_CONFIG --cflags poppler`
PKG_LIBS=`$PKG_CONFIG --cflags poppler`

AC_SUBST(PKG_CPPFLAGS)
AC_SUBST(PKG_LIBS)

AC_OUTPUT(src/Makevars)

