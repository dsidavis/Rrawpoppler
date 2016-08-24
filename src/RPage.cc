#define R_NO_REMAP 1

#include "Rpoppler.h"

SEXP R_Page_isOk(SEXP r_tthis)
{
    Page *tthis = GET_REF(r_tthis, Page);
    GBool ans;
    ans = tthis->isOk();
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

SEXP R_Page_getNum(SEXP r_tthis)
{
    Page *tthis = GET_REF(r_tthis, Page);
    int ans;
    ans = tthis->getNum();
    SEXP r_ans = Rf_ScalarInteger(ans);
    return(r_ans);
}

SEXP R_Page_getMediaBox(SEXP r_tthis)
{
    Page *tthis = GET_REF(r_tthis, Page);
    PDFRectangle * ans;
    ans = tthis->getMediaBox();
    SEXP r_ans = R_createRef(ans, "PDFRectanglePtr");
    return(r_ans);
}

SEXP R_Page_getCropBox(SEXP r_tthis)
{
    Page *tthis = GET_REF(r_tthis, Page);
    PDFRectangle * ans;
    ans = tthis->getCropBox();
    SEXP r_ans = R_createRef(ans, "PDFRectanglePtr");
    return(r_ans);
}

SEXP R_Page_isCropped(SEXP r_tthis)
{
    Page *tthis = GET_REF(r_tthis, Page);
    GBool ans;
    ans = tthis->isCropped();
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

SEXP R_Page_getMediaWidth(SEXP r_tthis)
{
    Page *tthis = GET_REF(r_tthis, Page);
    double ans;
    ans = tthis->getMediaWidth();
    SEXP r_ans = Rf_ScalarReal(ans);
    return(r_ans);
}

SEXP R_Page_getMediaHeight(SEXP r_tthis)
{
    Page *tthis = GET_REF(r_tthis, Page);
    double ans;
    ans = tthis->getMediaHeight();
    SEXP r_ans = Rf_ScalarReal(ans);
    return(r_ans);
}

SEXP R_Page_getCropWidth(SEXP r_tthis)
{
    Page *tthis = GET_REF(r_tthis, Page);
    double ans;
    ans = tthis->getCropWidth();
    SEXP r_ans = Rf_ScalarReal(ans);
    return(r_ans);
}

SEXP R_Page_getCropHeight(SEXP r_tthis)
{
    Page *tthis = GET_REF(r_tthis, Page);
    double ans;
    ans = tthis->getCropHeight();
    SEXP r_ans = Rf_ScalarReal(ans);
    return(r_ans);
}

SEXP R_Page_getBleedBox(SEXP r_tthis)
{
    Page *tthis = GET_REF(r_tthis, Page);
    PDFRectangle * ans;
    ans = tthis->getBleedBox();
    SEXP r_ans = R_createRef(ans, "PDFRectanglePtr");
    return(r_ans);
}

SEXP R_Page_getTrimBox(SEXP r_tthis)
{
    Page *tthis = GET_REF(r_tthis, Page);
    PDFRectangle * ans;
    ans = tthis->getTrimBox();
    SEXP r_ans = R_createRef(ans, "PDFRectanglePtr");
    return(r_ans);
}

SEXP R_Page_getArtBox(SEXP r_tthis)
{
    Page *tthis = GET_REF(r_tthis, Page);
    PDFRectangle * ans;
    ans = tthis->getArtBox();
    SEXP r_ans = R_createRef(ans, "PDFRectanglePtr");
    return(r_ans);
}

SEXP R_Page_getRotate(SEXP r_tthis)
{
    Page *tthis = GET_REF(r_tthis, Page);
    int ans;
    ans = tthis->getRotate();
    SEXP r_ans = Rf_ScalarInteger(ans);
    return(r_ans);
}

SEXP R_Page_getLastModified(SEXP r_tthis)
{
    Page *tthis = GET_REF(r_tthis, Page);
    GooString * ans;
    ans = tthis->getLastModified();
    SEXP r_ans = GooStringToR(ans);
    return(r_ans);
}

SEXP R_Page_getBoxColorInfo(SEXP r_tthis)
{
    Page *tthis = GET_REF(r_tthis, Page);
    Dict * ans;
    ans = tthis->getBoxColorInfo();
    SEXP r_ans = R_createRef(ans, "DictPtr");
    return(r_ans);
}

SEXP R_Page_getGroup(SEXP r_tthis)
{
    Page *tthis = GET_REF(r_tthis, Page);
    Dict * ans;
    ans = tthis->getGroup();
    SEXP r_ans = R_createRef(ans, "DictPtr");
    return(r_ans);
}

SEXP R_Page_getMetadata(SEXP r_tthis)
{
    Page *tthis = GET_REF(r_tthis, Page);
    Stream * ans;
    ans = tthis->getMetadata();
    SEXP r_ans = R_createRef(ans, "StreamPtr");
    return(r_ans);
}

SEXP R_Page_getPieceInfo(SEXP r_tthis)
{
    Page *tthis = GET_REF(r_tthis, Page);
    Dict * ans;
    ans = tthis->getPieceInfo();
    SEXP r_ans = R_createRef(ans, "DictPtr");
    return(r_ans);
}

SEXP R_Page_getSeparationInfo(SEXP r_tthis)
{
    Page *tthis = GET_REF(r_tthis, Page);
    Dict * ans;
    ans = tthis->getSeparationInfo();
    SEXP r_ans = R_createRef(ans, "DictPtr");
    return(r_ans);
}

SEXP R_Page_getDoc(SEXP r_tthis)
{
    Page *tthis = GET_REF(r_tthis, Page);
    PDFDoc * ans;
    ans = tthis->getDoc();
    SEXP r_ans = R_createRef(ans, "PDFDocPtr");
    return(r_ans);
}

SEXP R_Page_getResourceDict(SEXP r_tthis)
{
    Page *tthis = GET_REF(r_tthis, Page);
    Dict * ans;
    ans = tthis->getResourceDict();
    SEXP r_ans = R_createRef(ans, "DictPtr");
    return(r_ans);
}

SEXP R_Page_getResourceDictCopy(SEXP r_tthis, SEXP r_xrefA)
{
    Page *tthis = GET_REF(r_tthis, Page);
    XRef * xrefA;
    xrefA = GET_REF(r_xrefA, XRef );
    Dict * ans;
    ans = tthis->getResourceDictCopy(xrefA);
    SEXP r_ans = R_createRef(ans, "DictPtr");
    return(r_ans);
}

SEXP R_Page_getAnnots(SEXP r_tthis, SEXP r_xrefA)
{
    Page *tthis = GET_REF(r_tthis, Page);
    XRef * xrefA;
    xrefA = GET_REF(r_xrefA, XRef );
    Annots * ans;
    ans = tthis->getAnnots(xrefA);
    SEXP r_ans = R_createRef(ans, "AnnotsPtr");
    return(r_ans);
}

SEXP R_Page_addAnnot(SEXP r_tthis, SEXP r_annot)
{
    Page *tthis = GET_REF(r_tthis, Page);
    Annot * annot;
    annot = GET_REF(r_annot, Annot );
    tthis->addAnnot(annot);
    return(R_NilValue);
}

SEXP R_Page_removeAnnot(SEXP r_tthis, SEXP r_annot)
{
    Page *tthis = GET_REF(r_tthis, Page);
    Annot * annot;
    annot = GET_REF(r_annot, Annot );
    tthis->removeAnnot(annot);
    return(R_NilValue);
}

SEXP R_Page_getLinks(SEXP r_tthis)
{
    Page *tthis = GET_REF(r_tthis, Page);
    Links * ans;
    ans = tthis->getLinks();
    SEXP r_ans = R_createRef(ans, "LinksPtr");
    return(r_ans);
}

SEXP R_Page_getContents(SEXP r_tthis, SEXP r_obj)
{
    Page *tthis = GET_REF(r_tthis, Page);
    Object * obj;
    obj = GET_REF(r_obj, Object );
    Object * ans;
    ans = tthis->getContents(obj);
    SEXP r_ans = R_createRef(ans, "ObjectPtr");
    return(r_ans);
}

SEXP R_Page_getThumb(SEXP r_tthis, SEXP r_obj)
{
    Page *tthis = GET_REF(r_tthis, Page);
    Object * obj;
    obj = GET_REF(r_obj, Object );
    Object * ans;
    ans = tthis->getThumb(obj);
    SEXP r_ans = R_createRef(ans, "ObjectPtr");
    return(r_ans);
}

SEXP R_Page_loadThumb(SEXP r_tthis, SEXP r_data, SEXP r_width, SEXP r_height, SEXP r_rowstride)
{
    Page *tthis = GET_REF(r_tthis, Page);
    unsigned char ** data;
    data = GET_REF(r_data, unsigned char *);
    int * width;
    width = INTEGER(r_width);
    int * height;
    height = INTEGER(r_height);
    int * rowstride;
    rowstride = INTEGER(r_rowstride);
    GBool ans;
    ans = tthis->loadThumb(data, width, height, rowstride);
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

SEXP R_Page_getTrans(SEXP r_tthis, SEXP r_obj)
{
    Page *tthis = GET_REF(r_tthis, Page);
    Object * obj;
    obj = GET_REF(r_obj, Object );
    Object * ans;
    ans = tthis->getTrans(obj);
    SEXP r_ans = R_createRef(ans, "ObjectPtr");
    return(r_ans);
}

SEXP R_Page_getFormWidgets(SEXP r_tthis)
{
    Page *tthis = GET_REF(r_tthis, Page);
    FormPageWidgets * ans;
    ans = tthis->getFormWidgets();
    SEXP r_ans = R_createRef(ans, "FormPageWidgetsPtr");
    return(r_ans);
}

SEXP R_Page_getDuration(SEXP r_tthis)
{
    Page *tthis = GET_REF(r_tthis, Page);
    double ans;
    ans = tthis->getDuration();
    SEXP r_ans = Rf_ScalarReal(ans);
    return(r_ans);
}

SEXP R_Page_getActions(SEXP r_tthis, SEXP r_obj)
{
    Page *tthis = GET_REF(r_tthis, Page);
    Object * obj;
    obj = GET_REF(r_obj, Object );
    Object * ans;
    ans = tthis->getActions(obj);
    SEXP r_ans = R_createRef(ans, "ObjectPtr");
    return(r_ans);
}

SEXP R_Page_getAdditionalAction(SEXP r_tthis, SEXP r_type)
{
    Page *tthis = GET_REF(r_tthis, Page);
    Page::PageAdditionalActionsType type;
    type = (Page::PageAdditionalActionsType) INTEGER(r_type)[0];
    LinkAction * ans;
    ans = tthis->getAdditionalAction(type);
    SEXP r_ans = R_createRef(ans, "LinkActionPtr");
    return(r_ans);
}

SEXP R_Page_display(SEXP r_tthis, SEXP r_gfx)
{
    Page *tthis = GET_REF(r_tthis, Page);
    Gfx * gfx;
    gfx = GET_REF(r_gfx, Gfx );
    tthis->display(gfx);
    return(R_NilValue);
}

SEXP R_Page_makeBox(SEXP r_tthis, SEXP r_hDPI, SEXP r_vDPI, SEXP r_rotate, SEXP r_useMediaBox, SEXP r_upsideDown, SEXP r_sliceX, SEXP r_sliceY, SEXP r_sliceW, SEXP r_sliceH, SEXP r_box, SEXP r_crop)
{
    Page *tthis = GET_REF(r_tthis, Page);
    double hDPI;
    hDPI = REAL(r_hDPI)[0];
    double vDPI;
    vDPI = REAL(r_vDPI)[0];
    int rotate;
    rotate = INTEGER(r_rotate)[0];
    GBool useMediaBox;
    useMediaBox = LOGICAL(r_useMediaBox)[0];
    GBool upsideDown;
    upsideDown = LOGICAL(r_upsideDown)[0];
    double sliceX;
    sliceX = REAL(r_sliceX)[0];
    double sliceY;
    sliceY = REAL(r_sliceY)[0];
    double sliceW;
    sliceW = REAL(r_sliceW)[0];
    double sliceH;
    sliceH = REAL(r_sliceH)[0];
    PDFRectangle * box;
    box = GET_REF(r_box, PDFRectangle );
    GBool * crop;
    crop = GET_REF(r_crop, GBool );
    tthis->makeBox(hDPI, vDPI, rotate, useMediaBox, upsideDown, sliceX, sliceY, sliceW, sliceH, box, crop);
    return(R_NilValue);
}

SEXP R_Page_processLinks(SEXP r_tthis, SEXP r_out)
{
    Page *tthis = GET_REF(r_tthis, Page);
    OutputDev * out;
    out = GET_REF(r_out, OutputDev );
    tthis->processLinks(out);
    return(R_NilValue);
}

SEXP R_Page_getDefaultCTM(SEXP r_tthis, SEXP r_ctm, SEXP r_hDPI, SEXP r_vDPI, SEXP r_rotate, SEXP r_useMediaBox, SEXP r_upsideDown)
{
    Page *tthis = GET_REF(r_tthis, Page);
    double * ctm;
    ctm = GET_REF(r_ctm, double );
    double hDPI;
    hDPI = REAL(r_hDPI)[0];
    double vDPI;
    vDPI = REAL(r_vDPI)[0];
    int rotate;
    rotate = INTEGER(r_rotate)[0];
    GBool useMediaBox;
    useMediaBox = LOGICAL(r_useMediaBox)[0];
    GBool upsideDown;
    upsideDown = LOGICAL(r_upsideDown)[0];
    tthis->getDefaultCTM(ctm, hDPI, vDPI, rotate, useMediaBox, upsideDown);
    return(R_NilValue);
}
