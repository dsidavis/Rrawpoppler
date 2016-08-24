#define R_NO_REMAP 1

#include "Rpoppler.h"

SEXP R_GfxColorSpace_copy(SEXP r_tthis)
{
    GfxColorSpace *tthis = GET_REF(r_tthis, GfxColorSpace);
    GfxColorSpace * ans;
    ans = tthis->copy();
    SEXP r_ans = R_createRef(ans, "GfxColorSpacePtr");
    return(r_ans);
}

SEXP R_GfxColorSpace_parse(SEXP r_res, SEXP r_csObj, SEXP r_out, SEXP r_state, SEXP r_recursion)
{
    GfxResources * res;
    res = GET_REF(r_res, GfxResources );
    Object * csObj;
    csObj = GET_REF(r_csObj, Object );
    OutputDev * out;
    out = GET_REF(r_out, OutputDev );
    GfxState * state;
    state = GET_REF(r_state, GfxState );
    int recursion;
    recursion = INTEGER(r_recursion)[0];
    GfxColorSpace * ans;
    ans = GfxColorSpace::parse(res, csObj, out, state, recursion);
    SEXP r_ans = R_createRef(ans, "GfxColorSpacePtr");
    return(r_ans);
}

SEXP R_GfxColorSpace_getGray(SEXP r_tthis, SEXP r_color, SEXP r_gray)
{
    GfxColorSpace *tthis = GET_REF(r_tthis, GfxColorSpace);
    GfxColor * color;
    color = GET_REF(r_color, GfxColor );
    GfxGray * gray;
    gray = GET_REF(r_gray, GfxGray );
    tthis->getGray(color, gray);
    return(R_NilValue);
}

SEXP R_GfxColorSpace_getRGB(SEXP r_tthis, SEXP r_color, SEXP r_rgb)
{
    GfxColorSpace *tthis = GET_REF(r_tthis, GfxColorSpace);
    GfxColor * color;
    color = GET_REF(r_color, GfxColor );
    GfxRGB * rgb;
    rgb = GET_REF(r_rgb, GfxRGB );
    tthis->getRGB(color, rgb);
    return(R_NilValue);
}

SEXP R_GfxColorSpace_getCMYK(SEXP r_tthis, SEXP r_color, SEXP r_cmyk)
{
    GfxColorSpace *tthis = GET_REF(r_tthis, GfxColorSpace);
    GfxColor * color;
    color = GET_REF(r_color, GfxColor );
    GfxCMYK * cmyk;
    cmyk = GET_REF(r_cmyk, GfxCMYK );
    tthis->getCMYK(color, cmyk);
    return(R_NilValue);
}

SEXP R_GfxColorSpace_getDeviceN(SEXP r_tthis, SEXP r_color, SEXP r_deviceN)
{
    GfxColorSpace *tthis = GET_REF(r_tthis, GfxColorSpace);
    GfxColor * color;
    color = GET_REF(r_color, GfxColor );
    GfxColor * deviceN;
    deviceN = GET_REF(r_deviceN, GfxColor );
    tthis->getDeviceN(color, deviceN);
    return(R_NilValue);
}

SEXP R_GfxColorSpace_createMapping(SEXP r_tthis, SEXP r_separationList, SEXP r_maxSepComps)
{
    GfxColorSpace *tthis = GET_REF(r_tthis, GfxColorSpace);
    GooList * separationList;
    separationList = GET_REF(r_separationList, GooList );
    int maxSepComps;
    maxSepComps = INTEGER(r_maxSepComps)[0];
    tthis->createMapping(separationList, maxSepComps);
    return(R_NilValue);
}

SEXP R_GfxColorSpace_useGetRGBLine(SEXP r_tthis)
{
    GfxColorSpace *tthis = GET_REF(r_tthis, GfxColorSpace);
    GBool ans;
    ans = tthis->useGetRGBLine();
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

SEXP R_GfxColorSpace_useGetGrayLine(SEXP r_tthis)
{
    GfxColorSpace *tthis = GET_REF(r_tthis, GfxColorSpace);
    GBool ans;
    ans = tthis->useGetGrayLine();
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

SEXP R_GfxColorSpace_useGetCMYKLine(SEXP r_tthis)
{
    GfxColorSpace *tthis = GET_REF(r_tthis, GfxColorSpace);
    GBool ans;
    ans = tthis->useGetCMYKLine();
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

SEXP R_GfxColorSpace_useGetDeviceNLine(SEXP r_tthis)
{
    GfxColorSpace *tthis = GET_REF(r_tthis, GfxColorSpace);
    GBool ans;
    ans = tthis->useGetDeviceNLine();
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

SEXP R_GfxColorSpace_getNComps(SEXP r_tthis)
{
    GfxColorSpace *tthis = GET_REF(r_tthis, GfxColorSpace);
    int ans;
    ans = tthis->getNComps();
    SEXP r_ans = Rf_ScalarInteger(ans);
    return(r_ans);
}

SEXP R_GfxColorSpace_getDefaultColor(SEXP r_tthis, SEXP r_color)
{
    GfxColorSpace *tthis = GET_REF(r_tthis, GfxColorSpace);
    GfxColor * color;
    color = GET_REF(r_color, GfxColor );
    tthis->getDefaultColor(color);
    return(R_NilValue);
}

SEXP R_GfxColorSpace_getDefaultRanges(SEXP r_tthis, SEXP r_decodeLow, SEXP r_decodeRange, SEXP r_maxImgPixel)
{
    GfxColorSpace *tthis = GET_REF(r_tthis, GfxColorSpace);
    double * decodeLow;
    decodeLow = GET_REF(r_decodeLow, double );
    double * decodeRange;
    decodeRange = GET_REF(r_decodeRange, double );
    int maxImgPixel;
    maxImgPixel = INTEGER(r_maxImgPixel)[0];
    tthis->getDefaultRanges(decodeLow, decodeRange, maxImgPixel);
    return(R_NilValue);
}

SEXP R_GfxColorSpace_isNonMarking(SEXP r_tthis)
{
    GfxColorSpace *tthis = GET_REF(r_tthis, GfxColorSpace);
    GBool ans;
    ans = tthis->isNonMarking();
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

SEXP R_GfxColorSpace_getOverprintMask(SEXP r_tthis)
{
    GfxColorSpace *tthis = GET_REF(r_tthis, GfxColorSpace);
    Guint ans;
    ans = tthis->getOverprintMask();
    SEXP r_ans = Rf_ScalarReal(ans);
    return(r_ans);
}

SEXP R_GfxColorSpace_getNumColorSpaceModes()
{
    int ans;
    ans = GfxColorSpace::getNumColorSpaceModes();
    SEXP r_ans = Rf_ScalarInteger(ans);
    return(r_ans);
}

SEXP R_GfxColorSpace_getColorSpaceModeName(SEXP r_idx)
{
    int idx;
    idx = INTEGER(r_idx)[0];
    const char * ans;
    ans = GfxColorSpace::getColorSpaceModeName(idx);
    SEXP r_ans = Rf_mkString(ans);
    return(r_ans);
}

SEXP R_GfxColorSpace_setupColorProfiles()
{
    int ans;
    ans = GfxColorSpace::setupColorProfiles();
    SEXP r_ans = Rf_ScalarInteger(ans);
    return(r_ans);
}

SEXP R_GfxColorSpace_setDisplayProfile(SEXP r_displayProfileA)
{
    void * displayProfileA;
    displayProfileA = GET_REF(r_displayProfileA, void );
    GfxColorSpace::setDisplayProfile(displayProfileA);
    return(R_NilValue);
}

SEXP R_GfxColorSpace_setDisplayProfileName(SEXP r_name)
{
    GooString * name;
    name = GET_REF(r_name, GooString );
    GfxColorSpace::setDisplayProfileName(name);
    return(R_NilValue);
}

SEXP R_GfxColorSpace_getRGBProfile()
{
    void * ans;
    ans = GfxColorSpace::getRGBProfile();
    SEXP r_ans = R_createRef(ans, "voidPtr");
    return(r_ans);
}
