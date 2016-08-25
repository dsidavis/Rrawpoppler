#define R_NO_REMAP 1

#include "Rpoppler.h"

extern "C"
SEXP R_GfxSubpath_copy(SEXP r_tthis)
{
    GfxSubpath *tthis = GET_REF(r_tthis, GfxSubpath);
    GfxSubpath * ans;
    ans = tthis->copy();
    SEXP r_ans = R_createRef(ans, "GfxSubpathPtr");
    return(r_ans);
}

extern "C"
SEXP R_GfxSubpath_getNumPoints(SEXP r_tthis)
{
    GfxSubpath *tthis = GET_REF(r_tthis, GfxSubpath);
    int ans;
    ans = tthis->getNumPoints();
    SEXP r_ans = Rf_ScalarInteger(ans);
    return(r_ans);
}

extern "C"
SEXP R_GfxSubpath_getX(SEXP r_tthis, SEXP r_i)
{
    GfxSubpath *tthis = GET_REF(r_tthis, GfxSubpath);
    int i;
    i = INTEGER(r_i)[0];
    double ans;
    ans = tthis->getX(i);
    SEXP r_ans = Rf_ScalarReal(ans);
    return(r_ans);
}

extern "C"
SEXP R_GfxSubpath_getY(SEXP r_tthis, SEXP r_i)
{
    GfxSubpath *tthis = GET_REF(r_tthis, GfxSubpath);
    int i;
    i = INTEGER(r_i)[0];
    double ans;
    ans = tthis->getY(i);
    SEXP r_ans = Rf_ScalarReal(ans);
    return(r_ans);
}

extern "C"
SEXP R_GfxSubpath_getCurve(SEXP r_tthis, SEXP r_i)
{
    GfxSubpath *tthis = GET_REF(r_tthis, GfxSubpath);
    int i;
    i = INTEGER(r_i)[0];
    GBool ans;
    ans = tthis->getCurve(i);
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

extern "C"
SEXP R_GfxSubpath_setX(SEXP r_tthis, SEXP r_i, SEXP r_a)
{
    GfxSubpath *tthis = GET_REF(r_tthis, GfxSubpath);
    int i;
    i = INTEGER(r_i)[0];
    double a;
    a = REAL(r_a)[0];
    tthis->setX(i, a);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxSubpath_setY(SEXP r_tthis, SEXP r_i, SEXP r_a)
{
    GfxSubpath *tthis = GET_REF(r_tthis, GfxSubpath);
    int i;
    i = INTEGER(r_i)[0];
    double a;
    a = REAL(r_a)[0];
    tthis->setY(i, a);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxSubpath_getLastX(SEXP r_tthis)
{
    GfxSubpath *tthis = GET_REF(r_tthis, GfxSubpath);
    double ans;
    ans = tthis->getLastX();
    SEXP r_ans = Rf_ScalarReal(ans);
    return(r_ans);
}

extern "C"
SEXP R_GfxSubpath_getLastY(SEXP r_tthis)
{
    GfxSubpath *tthis = GET_REF(r_tthis, GfxSubpath);
    double ans;
    ans = tthis->getLastY();
    SEXP r_ans = Rf_ScalarReal(ans);
    return(r_ans);
}

extern "C"
SEXP R_GfxSubpath_lineTo(SEXP r_tthis, SEXP r_x1, SEXP r_y1)
{
    GfxSubpath *tthis = GET_REF(r_tthis, GfxSubpath);
    double x1;
    x1 = REAL(r_x1)[0];
    double y1;
    y1 = REAL(r_y1)[0];
    tthis->lineTo(x1, y1);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxSubpath_curveTo(SEXP r_tthis, SEXP r_x1, SEXP r_y1, SEXP r_x2, SEXP r_y2, SEXP r_x3, SEXP r_y3)
{
    GfxSubpath *tthis = GET_REF(r_tthis, GfxSubpath);
    double x1;
    x1 = REAL(r_x1)[0];
    double y1;
    y1 = REAL(r_y1)[0];
    double x2;
    x2 = REAL(r_x2)[0];
    double y2;
    y2 = REAL(r_y2)[0];
    double x3;
    x3 = REAL(r_x3)[0];
    double y3;
    y3 = REAL(r_y3)[0];
    tthis->curveTo(x1, y1, x2, y2, x3, y3);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxSubpath_close(SEXP r_tthis)
{
    GfxSubpath *tthis = GET_REF(r_tthis, GfxSubpath);
    tthis->close();
    return(R_NilValue);
}

extern "C"
SEXP R_GfxSubpath_isClosed(SEXP r_tthis)
{
    GfxSubpath *tthis = GET_REF(r_tthis, GfxSubpath);
    GBool ans;
    ans = tthis->isClosed();
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

extern "C"
SEXP R_GfxSubpath_offset(SEXP r_tthis, SEXP r_dx, SEXP r_dy)
{
    GfxSubpath *tthis = GET_REF(r_tthis, GfxSubpath);
    double dx;
    dx = REAL(r_dx)[0];
    double dy;
    dy = REAL(r_dy)[0];
    tthis->offset(dx, dy);
    return(R_NilValue);
}
