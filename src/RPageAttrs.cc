#define R_NO_REMAP 1

#include "Rpoppler.h"

SEXP R_PageAttrs_getMediaBox(SEXP r_tthis)
{
    PageAttrs *tthis = GET_REF(r_tthis, PageAttrs);
    PDFRectangle * ans;
    ans = tthis->getMediaBox();
    SEXP r_ans = R_createRef(ans, "PDFRectanglePtr");
    return(r_ans);
}

SEXP R_PageAttrs_getCropBox(SEXP r_tthis)
{
    PageAttrs *tthis = GET_REF(r_tthis, PageAttrs);
    PDFRectangle * ans;
    ans = tthis->getCropBox();
    SEXP r_ans = R_createRef(ans, "PDFRectanglePtr");
    return(r_ans);
}

SEXP R_PageAttrs_isCropped(SEXP r_tthis)
{
    PageAttrs *tthis = GET_REF(r_tthis, PageAttrs);
    GBool ans;
    ans = tthis->isCropped();
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

SEXP R_PageAttrs_getBleedBox(SEXP r_tthis)
{
    PageAttrs *tthis = GET_REF(r_tthis, PageAttrs);
    PDFRectangle * ans;
    ans = tthis->getBleedBox();
    SEXP r_ans = R_createRef(ans, "PDFRectanglePtr");
    return(r_ans);
}

SEXP R_PageAttrs_getTrimBox(SEXP r_tthis)
{
    PageAttrs *tthis = GET_REF(r_tthis, PageAttrs);
    PDFRectangle * ans;
    ans = tthis->getTrimBox();
    SEXP r_ans = R_createRef(ans, "PDFRectanglePtr");
    return(r_ans);
}

SEXP R_PageAttrs_getArtBox(SEXP r_tthis)
{
    PageAttrs *tthis = GET_REF(r_tthis, PageAttrs);
    PDFRectangle * ans;
    ans = tthis->getArtBox();
    SEXP r_ans = R_createRef(ans, "PDFRectanglePtr");
    return(r_ans);
}

SEXP R_PageAttrs_getRotate(SEXP r_tthis)
{
    PageAttrs *tthis = GET_REF(r_tthis, PageAttrs);
    int ans;
    ans = tthis->getRotate();
    SEXP r_ans = Rf_ScalarInteger(ans);
    return(r_ans);
}

SEXP R_PageAttrs_getLastModified(SEXP r_tthis)
{
    PageAttrs *tthis = GET_REF(r_tthis, PageAttrs);
    GooString * ans;
    ans = tthis->getLastModified();
    SEXP r_ans = GooStringToR(ans);
    return(r_ans);
}

SEXP R_PageAttrs_getBoxColorInfo(SEXP r_tthis)
{
    PageAttrs *tthis = GET_REF(r_tthis, PageAttrs);
    Dict * ans;
    ans = tthis->getBoxColorInfo();
    SEXP r_ans = R_createRef(ans, "DictPtr");
    return(r_ans);
}

SEXP R_PageAttrs_getGroup(SEXP r_tthis)
{
    PageAttrs *tthis = GET_REF(r_tthis, PageAttrs);
    Dict * ans;
    ans = tthis->getGroup();
    SEXP r_ans = R_createRef(ans, "DictPtr");
    return(r_ans);
}

SEXP R_PageAttrs_getMetadata(SEXP r_tthis)
{
    PageAttrs *tthis = GET_REF(r_tthis, PageAttrs);
    Stream * ans;
    ans = tthis->getMetadata();
    SEXP r_ans = R_createRef(ans, "StreamPtr");
    return(r_ans);
}

SEXP R_PageAttrs_getPieceInfo(SEXP r_tthis)
{
    PageAttrs *tthis = GET_REF(r_tthis, PageAttrs);
    Dict * ans;
    ans = tthis->getPieceInfo();
    SEXP r_ans = R_createRef(ans, "DictPtr");
    return(r_ans);
}

SEXP R_PageAttrs_getSeparationInfo(SEXP r_tthis)
{
    PageAttrs *tthis = GET_REF(r_tthis, PageAttrs);
    Dict * ans;
    ans = tthis->getSeparationInfo();
    SEXP r_ans = R_createRef(ans, "DictPtr");
    return(r_ans);
}

SEXP R_PageAttrs_getResourceDict(SEXP r_tthis)
{
    PageAttrs *tthis = GET_REF(r_tthis, PageAttrs);
    Dict * ans;
    ans = tthis->getResourceDict();
    SEXP r_ans = R_createRef(ans, "DictPtr");
    return(r_ans);
}

SEXP R_PageAttrs_replaceResource(SEXP r_tthis, SEXP r_obj1)
{
    PageAttrs *tthis = GET_REF(r_tthis, PageAttrs);
    Object obj1;
    obj1 = * GET_REF(r_obj1, Object);
    tthis->replaceResource(obj1);
    return(R_NilValue);
}

SEXP R_PageAttrs_clipBoxes(SEXP r_tthis)
{
    PageAttrs *tthis = GET_REF(r_tthis, PageAttrs);
    tthis->clipBoxes();
    return(R_NilValue);
}
