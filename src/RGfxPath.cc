#define R_NO_REMAP 1

#include "Rpoppler.h"

extern "C"
SEXP R_GfxPath_copy(SEXP r_tthis)
{
    GfxPath *tthis = GET_REF(r_tthis, GfxPath);
    GfxPath * ans;
    ans = tthis->copy();
    SEXP r_ans = R_createRef(ans, "GfxPathPtr", NULL);
    return(r_ans);
}

extern "C"
SEXP R_GfxPath_isCurPt(SEXP r_tthis)
{
    GfxPath *tthis = GET_REF(r_tthis, GfxPath);
    GBool ans;
    ans = tthis->isCurPt();
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

extern "C"
SEXP R_GfxPath_isPath(SEXP r_tthis)
{
    GfxPath *tthis = GET_REF(r_tthis, GfxPath);
    GBool ans;
    ans = tthis->isPath();
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

extern "C"
SEXP R_GfxPath_getNumSubpaths(SEXP r_tthis)
{
    GfxPath *tthis = GET_REF(r_tthis, GfxPath);
    int ans;
    ans = tthis->getNumSubpaths();
    SEXP r_ans = Rf_ScalarInteger(ans);
    return(r_ans);
}

extern "C"
SEXP R_GfxPath_getSubpath(SEXP r_tthis, SEXP r_i)
{
    GfxPath *tthis = GET_REF(r_tthis, GfxPath);
    int i;
    i = INTEGER(r_i)[0];
    GfxSubpath * ans;
    ans = tthis->getSubpath(i);
    SEXP r_ans = R_createRef(ans, "GfxSubpathPtr", NULL);
    return(r_ans);
}

extern "C"
SEXP R_GfxPath_getLastX(SEXP r_tthis)
{
    GfxPath *tthis = GET_REF(r_tthis, GfxPath);
    double ans;
    ans = tthis->getLastX();
    SEXP r_ans = Rf_ScalarReal(ans);
    return(r_ans);
}

extern "C"
SEXP R_GfxPath_getLastY(SEXP r_tthis)
{
    GfxPath *tthis = GET_REF(r_tthis, GfxPath);
    double ans;
    ans = tthis->getLastY();
    SEXP r_ans = Rf_ScalarReal(ans);
    return(r_ans);
}

extern "C"
SEXP R_GfxPath_moveTo(SEXP r_tthis, SEXP r_x, SEXP r_y)
{
    GfxPath *tthis = GET_REF(r_tthis, GfxPath);
    double x;
    x = REAL(r_x)[0];
    double y;
    y = REAL(r_y)[0];
    tthis->moveTo(x, y);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxPath_lineTo(SEXP r_tthis, SEXP r_x, SEXP r_y)
{
    GfxPath *tthis = GET_REF(r_tthis, GfxPath);
    double x;
    x = REAL(r_x)[0];
    double y;
    y = REAL(r_y)[0];
    tthis->lineTo(x, y);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxPath_curveTo(SEXP r_tthis, SEXP r_x1, SEXP r_y1, SEXP r_x2, SEXP r_y2, SEXP r_x3, SEXP r_y3)
{
    GfxPath *tthis = GET_REF(r_tthis, GfxPath);
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
SEXP R_GfxPath_close(SEXP r_tthis)
{
    GfxPath *tthis = GET_REF(r_tthis, GfxPath);
    tthis->close();
    return(R_NilValue);
}

extern "C"
SEXP R_GfxPath_append(SEXP r_tthis, SEXP r_path)
{
    GfxPath *tthis = GET_REF(r_tthis, GfxPath);
    GfxPath * path;
    path = GET_REF(r_path, GfxPath );
    tthis->append(path);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxPath_offset(SEXP r_tthis, SEXP r_dx, SEXP r_dy)
{
    GfxPath *tthis = GET_REF(r_tthis, GfxPath);
    double dx;
    dx = REAL(r_dx)[0];
    double dy;
    dy = REAL(r_dy)[0];
    tthis->offset(dx, dy);
    return(R_NilValue);
}
