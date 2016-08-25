#define R_NO_REMAP 1

#include "Rpoppler.h"

extern "C"
SEXP R_GfxState_copy(SEXP r_tthis, SEXP r_copyPath)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    GBool copyPath;
    copyPath = LOGICAL(r_copyPath)[0];
    GfxState * ans;
    ans = tthis->copy(copyPath);
    SEXP r_ans = R_createRef(ans, "GfxStatePtr");
    return(r_ans);
}

extern "C"
SEXP R_GfxState_getHDPI(SEXP r_tthis)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    double ans;
    ans = tthis->getHDPI();
    SEXP r_ans = Rf_ScalarReal(ans);
    return(r_ans);
}

extern "C"
SEXP R_GfxState_getVDPI(SEXP r_tthis)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    double ans;
    ans = tthis->getVDPI();
    SEXP r_ans = Rf_ScalarReal(ans);
    return(r_ans);
}

extern "C"
SEXP R_GfxState_getCTM(SEXP r_tthis, SEXP r_m)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    Matrix * m;
    m = GET_REF(r_m, Matrix );
    tthis->getCTM(m);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxState_getX1(SEXP r_tthis)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    double ans;
    ans = tthis->getX1();
    SEXP r_ans = Rf_ScalarReal(ans);
    return(r_ans);
}

extern "C"
SEXP R_GfxState_getY1(SEXP r_tthis)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    double ans;
    ans = tthis->getY1();
    SEXP r_ans = Rf_ScalarReal(ans);
    return(r_ans);
}

extern "C"
SEXP R_GfxState_getX2(SEXP r_tthis)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    double ans;
    ans = tthis->getX2();
    SEXP r_ans = Rf_ScalarReal(ans);
    return(r_ans);
}

extern "C"
SEXP R_GfxState_getY2(SEXP r_tthis)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    double ans;
    ans = tthis->getY2();
    SEXP r_ans = Rf_ScalarReal(ans);
    return(r_ans);
}

extern "C"
SEXP R_GfxState_getPageWidth(SEXP r_tthis)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    double ans;
    ans = tthis->getPageWidth();
    SEXP r_ans = Rf_ScalarReal(ans);
    return(r_ans);
}

extern "C"
SEXP R_GfxState_getPageHeight(SEXP r_tthis)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    double ans;
    ans = tthis->getPageHeight();
    SEXP r_ans = Rf_ScalarReal(ans);
    return(r_ans);
}

extern "C"
SEXP R_GfxState_getRotate(SEXP r_tthis)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    int ans;
    ans = tthis->getRotate();
    SEXP r_ans = Rf_ScalarInteger(ans);
    return(r_ans);
}

extern "C"
SEXP R_GfxState_getFillColor(SEXP r_tthis)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    GfxColor * ans;
    ans = tthis->getFillColor();
    SEXP r_ans = R_createRef(ans, "GfxColorPtr");
    return(r_ans);
}

extern "C"
SEXP R_GfxState_getStrokeColor(SEXP r_tthis)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    GfxColor * ans;
    ans = tthis->getStrokeColor();
    SEXP r_ans = R_createRef(ans, "GfxColorPtr");
    return(r_ans);
}

extern "C"
SEXP R_GfxState_getFillGray(SEXP r_tthis, SEXP r_gray)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    GfxGray * gray;
    gray = GET_REF(r_gray, GfxGray );
    tthis->getFillGray(gray);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxState_getStrokeGray(SEXP r_tthis, SEXP r_gray)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    GfxGray * gray;
    gray = GET_REF(r_gray, GfxGray );
    tthis->getStrokeGray(gray);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxState_getFillRGB(SEXP r_tthis, SEXP r_rgb)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    GfxRGB * rgb;
    rgb = GET_REF(r_rgb, GfxRGB );
    tthis->getFillRGB(rgb);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxState_getStrokeRGB(SEXP r_tthis, SEXP r_rgb)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    GfxRGB * rgb;
    rgb = GET_REF(r_rgb, GfxRGB );
    tthis->getStrokeRGB(rgb);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxState_getFillCMYK(SEXP r_tthis, SEXP r_cmyk)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    GfxCMYK * cmyk;
    cmyk = GET_REF(r_cmyk, GfxCMYK );
    tthis->getFillCMYK(cmyk);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxState_getFillDeviceN(SEXP r_tthis, SEXP r_deviceN)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    GfxColor * deviceN;
    deviceN = GET_REF(r_deviceN, GfxColor );
    tthis->getFillDeviceN(deviceN);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxState_getStrokeCMYK(SEXP r_tthis, SEXP r_cmyk)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    GfxCMYK * cmyk;
    cmyk = GET_REF(r_cmyk, GfxCMYK );
    tthis->getStrokeCMYK(cmyk);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxState_getStrokeDeviceN(SEXP r_tthis, SEXP r_deviceN)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    GfxColor * deviceN;
    deviceN = GET_REF(r_deviceN, GfxColor );
    tthis->getStrokeDeviceN(deviceN);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxState_getFillColorSpace(SEXP r_tthis)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    GfxColorSpace * ans;
    ans = tthis->getFillColorSpace();
    SEXP r_ans = R_createRef(ans, "GfxColorSpacePtr");
    return(r_ans);
}

extern "C"
SEXP R_GfxState_getStrokeColorSpace(SEXP r_tthis)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    GfxColorSpace * ans;
    ans = tthis->getStrokeColorSpace();
    SEXP r_ans = R_createRef(ans, "GfxColorSpacePtr");
    return(r_ans);
}

extern "C"
SEXP R_GfxState_getFillPattern(SEXP r_tthis)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    GfxPattern * ans;
    ans = tthis->getFillPattern();
    SEXP r_ans = R_createRef(ans, "GfxPatternPtr");
    return(r_ans);
}

extern "C"
SEXP R_GfxState_getStrokePattern(SEXP r_tthis)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    GfxPattern * ans;
    ans = tthis->getStrokePattern();
    SEXP r_ans = R_createRef(ans, "GfxPatternPtr");
    return(r_ans);
}

extern "C"
SEXP R_GfxState_getFillOpacity(SEXP r_tthis)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    double ans;
    ans = tthis->getFillOpacity();
    SEXP r_ans = Rf_ScalarReal(ans);
    return(r_ans);
}

extern "C"
SEXP R_GfxState_getStrokeOpacity(SEXP r_tthis)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    double ans;
    ans = tthis->getStrokeOpacity();
    SEXP r_ans = Rf_ScalarReal(ans);
    return(r_ans);
}

extern "C"
SEXP R_GfxState_getFillOverprint(SEXP r_tthis)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    GBool ans;
    ans = tthis->getFillOverprint();
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

extern "C"
SEXP R_GfxState_getStrokeOverprint(SEXP r_tthis)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    GBool ans;
    ans = tthis->getStrokeOverprint();
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

extern "C"
SEXP R_GfxState_getOverprintMode(SEXP r_tthis)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    int ans;
    ans = tthis->getOverprintMode();
    SEXP r_ans = Rf_ScalarInteger(ans);
    return(r_ans);
}

extern "C"
SEXP R_GfxState_getTransfer(SEXP r_tthis)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    Function ** ans;
    ans = tthis->getTransfer();
    SEXP r_ans = R_createRef(ans, "FunctionPtrPtr");
    return(r_ans);
}

extern "C"
SEXP R_GfxState_getLineWidth(SEXP r_tthis)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    double ans;
    ans = tthis->getLineWidth();
    SEXP r_ans = Rf_ScalarReal(ans);
    return(r_ans);
}

extern "C"
SEXP R_GfxState_getLineDash(SEXP r_tthis, SEXP r_dash, SEXP r_length, SEXP r_start)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    double ** dash;
    dash = GET_REF(r_dash, double *);
    int * length;
    length = INTEGER(r_length);
    double * start;
    start = GET_REF(r_start, double );
    tthis->getLineDash(dash, length, start);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxState_getFlatness(SEXP r_tthis)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    int ans;
    ans = tthis->getFlatness();
    SEXP r_ans = Rf_ScalarInteger(ans);
    return(r_ans);
}

extern "C"
SEXP R_GfxState_getLineJoin(SEXP r_tthis)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    int ans;
    ans = tthis->getLineJoin();
    SEXP r_ans = Rf_ScalarInteger(ans);
    return(r_ans);
}

extern "C"
SEXP R_GfxState_getLineCap(SEXP r_tthis)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    int ans;
    ans = tthis->getLineCap();
    SEXP r_ans = Rf_ScalarInteger(ans);
    return(r_ans);
}

extern "C"
SEXP R_GfxState_getMiterLimit(SEXP r_tthis)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    double ans;
    ans = tthis->getMiterLimit();
    SEXP r_ans = Rf_ScalarReal(ans);
    return(r_ans);
}

extern "C"
SEXP R_GfxState_getStrokeAdjust(SEXP r_tthis)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    GBool ans;
    ans = tthis->getStrokeAdjust();
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

extern "C"
SEXP R_GfxState_getAlphaIsShape(SEXP r_tthis)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    GBool ans;
    ans = tthis->getAlphaIsShape();
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

extern "C"
SEXP R_GfxState_getTextKnockout(SEXP r_tthis)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    GBool ans;
    ans = tthis->getTextKnockout();
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

extern "C"
SEXP R_GfxState_getFont(SEXP r_tthis)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    GfxFont * ans;
    ans = tthis->getFont();
    SEXP r_ans = R_createRef(ans, "GfxFontPtr");
    return(r_ans);
}

extern "C"
SEXP R_GfxState_getFontSize(SEXP r_tthis)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    double ans;
    ans = tthis->getFontSize();
    SEXP r_ans = Rf_ScalarReal(ans);
    return(r_ans);
}

extern "C"
SEXP R_GfxState_getTextMat(SEXP r_tthis)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    double * ans;
    ans = tthis->getTextMat();
    SEXP r_ans = R_createRef(ans, "doublePtr");
    return(r_ans);
}

extern "C"
SEXP R_GfxState_getCharSpace(SEXP r_tthis)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    double ans;
    ans = tthis->getCharSpace();
    SEXP r_ans = Rf_ScalarReal(ans);
    return(r_ans);
}

extern "C"
SEXP R_GfxState_getWordSpace(SEXP r_tthis)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    double ans;
    ans = tthis->getWordSpace();
    SEXP r_ans = Rf_ScalarReal(ans);
    return(r_ans);
}

extern "C"
SEXP R_GfxState_getHorizScaling(SEXP r_tthis)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    double ans;
    ans = tthis->getHorizScaling();
    SEXP r_ans = Rf_ScalarReal(ans);
    return(r_ans);
}

extern "C"
SEXP R_GfxState_getLeading(SEXP r_tthis)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    double ans;
    ans = tthis->getLeading();
    SEXP r_ans = Rf_ScalarReal(ans);
    return(r_ans);
}

extern "C"
SEXP R_GfxState_getRise(SEXP r_tthis)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    double ans;
    ans = tthis->getRise();
    SEXP r_ans = Rf_ScalarReal(ans);
    return(r_ans);
}

extern "C"
SEXP R_GfxState_getRender(SEXP r_tthis)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    int ans;
    ans = tthis->getRender();
    SEXP r_ans = Rf_ScalarInteger(ans);
    return(r_ans);
}

extern "C"
SEXP R_GfxState_getRenderingIntent(SEXP r_tthis)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    char * ans;
    ans = tthis->getRenderingIntent();
    SEXP r_ans = Rf_mkString(ans);
    return(r_ans);
}

extern "C"
SEXP R_GfxState_getPath(SEXP r_tthis)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    GfxPath * ans;
    ans = tthis->getPath();
    SEXP r_ans = R_createRef(ans, "GfxPathPtr");
    return(r_ans);
}

extern "C"
SEXP R_GfxState_setPath(SEXP r_tthis, SEXP r_pathA)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    GfxPath * pathA;
    pathA = GET_REF(r_pathA, GfxPath );
    tthis->setPath(pathA);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxState_getCurX(SEXP r_tthis)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    double ans;
    ans = tthis->getCurX();
    SEXP r_ans = Rf_ScalarReal(ans);
    return(r_ans);
}

extern "C"
SEXP R_GfxState_getCurY(SEXP r_tthis)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    double ans;
    ans = tthis->getCurY();
    SEXP r_ans = Rf_ScalarReal(ans);
    return(r_ans);
}

extern "C"
SEXP R_GfxState_getClipBBox(SEXP r_tthis, SEXP r_xMin, SEXP r_yMin, SEXP r_xMax, SEXP r_yMax)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    double * xMin;
    xMin = GET_REF(r_xMin, double );
    double * yMin;
    yMin = GET_REF(r_yMin, double );
    double * xMax;
    xMax = GET_REF(r_xMax, double );
    double * yMax;
    yMax = GET_REF(r_yMax, double );
    tthis->getClipBBox(xMin, yMin, xMax, yMax);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxState_getUserClipBBox(SEXP r_tthis, SEXP r_xMin, SEXP r_yMin, SEXP r_xMax, SEXP r_yMax)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    double * xMin;
    xMin = GET_REF(r_xMin, double );
    double * yMin;
    yMin = GET_REF(r_yMin, double );
    double * xMax;
    xMax = GET_REF(r_xMax, double );
    double * yMax;
    yMax = GET_REF(r_yMax, double );
    tthis->getUserClipBBox(xMin, yMin, xMax, yMax);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxState_getLineX(SEXP r_tthis)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    double ans;
    ans = tthis->getLineX();
    SEXP r_ans = Rf_ScalarReal(ans);
    return(r_ans);
}

extern "C"
SEXP R_GfxState_getLineY(SEXP r_tthis)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    double ans;
    ans = tthis->getLineY();
    SEXP r_ans = Rf_ScalarReal(ans);
    return(r_ans);
}

extern "C"
SEXP R_GfxState_isCurPt(SEXP r_tthis)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    GBool ans;
    ans = tthis->isCurPt();
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

extern "C"
SEXP R_GfxState_isPath(SEXP r_tthis)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    GBool ans;
    ans = tthis->isPath();
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

extern "C"
SEXP R_GfxState_transform(SEXP r_tthis, SEXP r_x1, SEXP r_y1, SEXP r_x2, SEXP r_y2)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    double x1;
    x1 = REAL(r_x1)[0];
    double y1;
    y1 = REAL(r_y1)[0];
    double * x2;
    x2 = GET_REF(r_x2, double );
    double * y2;
    y2 = GET_REF(r_y2, double );
    tthis->transform(x1, y1, x2, y2);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxState_transformDelta(SEXP r_tthis, SEXP r_x1, SEXP r_y1, SEXP r_x2, SEXP r_y2)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    double x1;
    x1 = REAL(r_x1)[0];
    double y1;
    y1 = REAL(r_y1)[0];
    double * x2;
    x2 = GET_REF(r_x2, double );
    double * y2;
    y2 = GET_REF(r_y2, double );
    tthis->transformDelta(x1, y1, x2, y2);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxState_textTransform(SEXP r_tthis, SEXP r_x1, SEXP r_y1, SEXP r_x2, SEXP r_y2)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    double x1;
    x1 = REAL(r_x1)[0];
    double y1;
    y1 = REAL(r_y1)[0];
    double * x2;
    x2 = GET_REF(r_x2, double );
    double * y2;
    y2 = GET_REF(r_y2, double );
    tthis->textTransform(x1, y1, x2, y2);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxState_textTransformDelta(SEXP r_tthis, SEXP r_x1, SEXP r_y1, SEXP r_x2, SEXP r_y2)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    double x1;
    x1 = REAL(r_x1)[0];
    double y1;
    y1 = REAL(r_y1)[0];
    double * x2;
    x2 = GET_REF(r_x2, double );
    double * y2;
    y2 = GET_REF(r_y2, double );
    tthis->textTransformDelta(x1, y1, x2, y2);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxState_transformWidth(SEXP r_tthis, SEXP r_w)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    double w;
    w = REAL(r_w)[0];
    double ans;
    ans = tthis->transformWidth(w);
    SEXP r_ans = Rf_ScalarReal(ans);
    return(r_ans);
}

extern "C"
SEXP R_GfxState_getTransformedLineWidth(SEXP r_tthis)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    double ans;
    ans = tthis->getTransformedLineWidth();
    SEXP r_ans = Rf_ScalarReal(ans);
    return(r_ans);
}

extern "C"
SEXP R_GfxState_getTransformedFontSize(SEXP r_tthis)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    double ans;
    ans = tthis->getTransformedFontSize();
    SEXP r_ans = Rf_ScalarReal(ans);
    return(r_ans);
}

extern "C"
SEXP R_GfxState_getFontTransMat(SEXP r_tthis, SEXP r_m11, SEXP r_m12, SEXP r_m21, SEXP r_m22)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    double * m11;
    m11 = GET_REF(r_m11, double );
    double * m12;
    m12 = GET_REF(r_m12, double );
    double * m21;
    m21 = GET_REF(r_m21, double );
    double * m22;
    m22 = GET_REF(r_m22, double );
    tthis->getFontTransMat(m11, m12, m21, m22);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxState_setCTM(SEXP r_tthis, SEXP r_a, SEXP r_b, SEXP r_c, SEXP r_d, SEXP r_e, SEXP r_f)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    double a;
    a = REAL(r_a)[0];
    double b;
    b = REAL(r_b)[0];
    double c;
    c = REAL(r_c)[0];
    double d;
    d = REAL(r_d)[0];
    double e;
    e = REAL(r_e)[0];
    double f;
    f = REAL(r_f)[0];
    tthis->setCTM(a, b, c, d, e, f);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxState_concatCTM(SEXP r_tthis, SEXP r_a, SEXP r_b, SEXP r_c, SEXP r_d, SEXP r_e, SEXP r_f)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    double a;
    a = REAL(r_a)[0];
    double b;
    b = REAL(r_b)[0];
    double c;
    c = REAL(r_c)[0];
    double d;
    d = REAL(r_d)[0];
    double e;
    e = REAL(r_e)[0];
    double f;
    f = REAL(r_f)[0];
    tthis->concatCTM(a, b, c, d, e, f);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxState_shiftCTMAndClip(SEXP r_tthis, SEXP r_tx, SEXP r_ty)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    double tx;
    tx = REAL(r_tx)[0];
    double ty;
    ty = REAL(r_ty)[0];
    tthis->shiftCTMAndClip(tx, ty);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxState_setFillColorSpace(SEXP r_tthis, SEXP r_colorSpace)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    GfxColorSpace * colorSpace;
    colorSpace = GET_REF(r_colorSpace, GfxColorSpace );
    tthis->setFillColorSpace(colorSpace);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxState_setStrokeColorSpace(SEXP r_tthis, SEXP r_colorSpace)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    GfxColorSpace * colorSpace;
    colorSpace = GET_REF(r_colorSpace, GfxColorSpace );
    tthis->setStrokeColorSpace(colorSpace);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxState_setFillColor(SEXP r_tthis, SEXP r_color)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    GfxColor * color;
    color = GET_REF(r_color, GfxColor );
    tthis->setFillColor(color);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxState_setStrokeColor(SEXP r_tthis, SEXP r_color)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    GfxColor * color;
    color = GET_REF(r_color, GfxColor );
    tthis->setStrokeColor(color);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxState_setFillPattern(SEXP r_tthis, SEXP r_pattern)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    GfxPattern * pattern;
    pattern = GET_REF(r_pattern, GfxPattern );
    tthis->setFillPattern(pattern);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxState_setStrokePattern(SEXP r_tthis, SEXP r_pattern)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    GfxPattern * pattern;
    pattern = GET_REF(r_pattern, GfxPattern );
    tthis->setStrokePattern(pattern);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxState_setBlendMode(SEXP r_tthis, SEXP r_mode)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    GfxBlendMode mode;
    mode = (GfxBlendMode) INTEGER(r_mode)[0];
    tthis->setBlendMode(mode);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxState_setFillOpacity(SEXP r_tthis, SEXP r_opac)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    double opac;
    opac = REAL(r_opac)[0];
    tthis->setFillOpacity(opac);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxState_setStrokeOpacity(SEXP r_tthis, SEXP r_opac)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    double opac;
    opac = REAL(r_opac)[0];
    tthis->setStrokeOpacity(opac);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxState_setFillOverprint(SEXP r_tthis, SEXP r_op)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    GBool op;
    op = LOGICAL(r_op)[0];
    tthis->setFillOverprint(op);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxState_setStrokeOverprint(SEXP r_tthis, SEXP r_op)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    GBool op;
    op = LOGICAL(r_op)[0];
    tthis->setStrokeOverprint(op);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxState_setOverprintMode(SEXP r_tthis, SEXP r_op)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    int op;
    op = INTEGER(r_op)[0];
    tthis->setOverprintMode(op);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxState_setTransfer(SEXP r_tthis, SEXP r_funcs)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    Function ** funcs;
    funcs = GET_REF(r_funcs, Function *);
    tthis->setTransfer(funcs);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxState_setLineWidth(SEXP r_tthis, SEXP r_width)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    double width;
    width = REAL(r_width)[0];
    tthis->setLineWidth(width);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxState_setLineDash(SEXP r_tthis, SEXP r_dash, SEXP r_length, SEXP r_start)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    double * dash;
    dash = GET_REF(r_dash, double );
    int length;
    length = INTEGER(r_length)[0];
    double start;
    start = REAL(r_start)[0];
    tthis->setLineDash(dash, length, start);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxState_setFlatness(SEXP r_tthis, SEXP r_flatness1)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    int flatness1;
    flatness1 = INTEGER(r_flatness1)[0];
    tthis->setFlatness(flatness1);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxState_setLineJoin(SEXP r_tthis, SEXP r_lineJoin1)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    int lineJoin1;
    lineJoin1 = INTEGER(r_lineJoin1)[0];
    tthis->setLineJoin(lineJoin1);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxState_setLineCap(SEXP r_tthis, SEXP r_lineCap1)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    int lineCap1;
    lineCap1 = INTEGER(r_lineCap1)[0];
    tthis->setLineCap(lineCap1);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxState_setMiterLimit(SEXP r_tthis, SEXP r_limit)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    double limit;
    limit = REAL(r_limit)[0];
    tthis->setMiterLimit(limit);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxState_setStrokeAdjust(SEXP r_tthis, SEXP r_sa)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    GBool sa;
    sa = LOGICAL(r_sa)[0];
    tthis->setStrokeAdjust(sa);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxState_setAlphaIsShape(SEXP r_tthis, SEXP r_ais)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    GBool ais;
    ais = LOGICAL(r_ais)[0];
    tthis->setAlphaIsShape(ais);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxState_setTextKnockout(SEXP r_tthis, SEXP r_tk)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    GBool tk;
    tk = LOGICAL(r_tk)[0];
    tthis->setTextKnockout(tk);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxState_setFont(SEXP r_tthis, SEXP r_fontA, SEXP r_fontSizeA)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    GfxFont * fontA;
    fontA = GET_REF(r_fontA, GfxFont );
    double fontSizeA;
    fontSizeA = REAL(r_fontSizeA)[0];
    tthis->setFont(fontA, fontSizeA);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxState_setTextMat(SEXP r_tthis, SEXP r_a, SEXP r_b, SEXP r_c, SEXP r_d, SEXP r_e, SEXP r_f)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    double a;
    a = REAL(r_a)[0];
    double b;
    b = REAL(r_b)[0];
    double c;
    c = REAL(r_c)[0];
    double d;
    d = REAL(r_d)[0];
    double e;
    e = REAL(r_e)[0];
    double f;
    f = REAL(r_f)[0];
    tthis->setTextMat(a, b, c, d, e, f);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxState_setCharSpace(SEXP r_tthis, SEXP r_space)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    double space;
    space = REAL(r_space)[0];
    tthis->setCharSpace(space);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxState_setWordSpace(SEXP r_tthis, SEXP r_space)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    double space;
    space = REAL(r_space)[0];
    tthis->setWordSpace(space);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxState_setHorizScaling(SEXP r_tthis, SEXP r_scale)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    double scale;
    scale = REAL(r_scale)[0];
    tthis->setHorizScaling(scale);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxState_setLeading(SEXP r_tthis, SEXP r_leadingA)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    double leadingA;
    leadingA = REAL(r_leadingA)[0];
    tthis->setLeading(leadingA);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxState_setRise(SEXP r_tthis, SEXP r_riseA)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    double riseA;
    riseA = REAL(r_riseA)[0];
    tthis->setRise(riseA);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxState_setRender(SEXP r_tthis, SEXP r_renderA)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    int renderA;
    renderA = INTEGER(r_renderA)[0];
    tthis->setRender(renderA);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxState_setRenderingIntent(SEXP r_tthis, SEXP r_intent)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    const char * intent;
    intent = CHAR(STRING_ELT(r_intent, 0));
    tthis->setRenderingIntent(intent);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxState_setDisplayProfile(SEXP r_tthis, SEXP r_localDisplayProfileA)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    void * localDisplayProfileA;
    localDisplayProfileA = GET_REF(r_localDisplayProfileA, void );
    tthis->setDisplayProfile(localDisplayProfileA);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxState_getDisplayProfile(SEXP r_tthis)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    void * ans;
    ans = tthis->getDisplayProfile();
    SEXP r_ans = R_createRef(ans, "voidPtr");
    return(r_ans);
}

extern "C"
SEXP R_GfxState_getXYZ2DisplayTransform(SEXP r_tthis)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    GfxColorTransform * ans;
    ans = tthis->getXYZ2DisplayTransform();
    SEXP r_ans = R_createRef(ans, "GfxColorTransformPtr");
    return(r_ans);
}

extern "C"
SEXP R_GfxState_moveTo(SEXP r_tthis, SEXP r_x, SEXP r_y)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    double x;
    x = REAL(r_x)[0];
    double y;
    y = REAL(r_y)[0];
    tthis->moveTo(x, y);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxState_lineTo(SEXP r_tthis, SEXP r_x, SEXP r_y)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    double x;
    x = REAL(r_x)[0];
    double y;
    y = REAL(r_y)[0];
    tthis->lineTo(x, y);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxState_curveTo(SEXP r_tthis, SEXP r_x1, SEXP r_y1, SEXP r_x2, SEXP r_y2, SEXP r_x3, SEXP r_y3)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
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
SEXP R_GfxState_closePath(SEXP r_tthis)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    tthis->closePath();
    return(R_NilValue);
}

extern "C"
SEXP R_GfxState_clearPath(SEXP r_tthis)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    tthis->clearPath();
    return(R_NilValue);
}

extern "C"
SEXP R_GfxState_clip(SEXP r_tthis)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    tthis->clip();
    return(R_NilValue);
}

extern "C"
SEXP R_GfxState_clipToStrokePath(SEXP r_tthis)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    tthis->clipToStrokePath();
    return(R_NilValue);
}

extern "C"
SEXP R_GfxState_clipToRect(SEXP r_tthis, SEXP r_xMin, SEXP r_yMin, SEXP r_xMax, SEXP r_yMax)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    double xMin;
    xMin = REAL(r_xMin)[0];
    double yMin;
    yMin = REAL(r_yMin)[0];
    double xMax;
    xMax = REAL(r_xMax)[0];
    double yMax;
    yMax = REAL(r_yMax)[0];
    tthis->clipToRect(xMin, yMin, xMax, yMax);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxState_textSetPos(SEXP r_tthis, SEXP r_tx, SEXP r_ty)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    double tx;
    tx = REAL(r_tx)[0];
    double ty;
    ty = REAL(r_ty)[0];
    tthis->textSetPos(tx, ty);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxState_textMoveTo(SEXP r_tthis, SEXP r_tx, SEXP r_ty)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    double tx;
    tx = REAL(r_tx)[0];
    double ty;
    ty = REAL(r_ty)[0];
    tthis->textMoveTo(tx, ty);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxState_textShift(SEXP r_tthis, SEXP r_tx, SEXP r_ty)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    double tx;
    tx = REAL(r_tx)[0];
    double ty;
    ty = REAL(r_ty)[0];
    tthis->textShift(tx, ty);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxState_shift(SEXP r_tthis, SEXP r_dx, SEXP r_dy)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    double dx;
    dx = REAL(r_dx)[0];
    double dy;
    dy = REAL(r_dy)[0];
    tthis->shift(dx, dy);
    return(R_NilValue);
}

extern "C"
SEXP R_GfxState_save(SEXP r_tthis)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    GfxState * ans;
    ans = tthis->save();
    SEXP r_ans = R_createRef(ans, "GfxStatePtr");
    return(r_ans);
}

extern "C"
SEXP R_GfxState_restore(SEXP r_tthis)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    GfxState * ans;
    ans = tthis->restore();
    SEXP r_ans = R_createRef(ans, "GfxStatePtr");
    return(r_ans);
}

extern "C"
SEXP R_GfxState_hasSaves(SEXP r_tthis)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    GBool ans;
    ans = tthis->hasSaves();
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

extern "C"
SEXP R_GfxState_isParentState(SEXP r_tthis, SEXP r_state)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    GfxState * state;
    state = GET_REF(r_state, GfxState );
    GBool ans;
    ans = tthis->isParentState(state);
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

extern "C"
SEXP R_GfxState_parseBlendMode(SEXP r_tthis, SEXP r_obj, SEXP r_mode)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    Object * obj;
    obj = GET_REF(r_obj, Object );
    GfxBlendMode * mode;
    mode = GET_REF(r_mode, GfxBlendMode );
    GBool ans;
    ans = tthis->parseBlendMode(obj, mode);
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

extern "C"
SEXP R_GfxState_getReusablePath(SEXP r_tthis)
{
    GfxState *tthis = GET_REF(r_tthis, GfxState);
    GfxState::ReusablePathIterator * ans;
    ans = tthis->getReusablePath();
    SEXP r_ans = R_createRef(ans, "GfxState::ReusablePathIteratorPtr");
    return(r_ans);
}
