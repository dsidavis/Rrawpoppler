#define R_NO_REMAP 1

#include "Rpoppler.h"

SEXP R_PDFDoc_ErrorPDFDoc(SEXP r_errorCode, SEXP r_fileNameA)
{
    int errorCode;
    errorCode = INTEGER(r_errorCode)[0];
    GooString * fileNameA;
    fileNameA = GET_REF(r_fileNameA, GooString );
    PDFDoc * ans;
    ans = PDFDoc::ErrorPDFDoc(errorCode, fileNameA);
    SEXP r_ans = R_createRef(ans, "PDFDocPtr");
    return(r_ans);
}

SEXP R_PDFDoc_isOk(SEXP r_tthis)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    GBool ans;
    ans = tthis->isOk();
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

SEXP R_PDFDoc_getErrorCode(SEXP r_tthis)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    int ans;
    ans = tthis->getErrorCode();
    SEXP r_ans = Rf_ScalarInteger(ans);
    return(r_ans);
}

SEXP R_PDFDoc_getFopenErrno(SEXP r_tthis)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    int ans;
    ans = tthis->getFopenErrno();
    SEXP r_ans = Rf_ScalarInteger(ans);
    return(r_ans);
}

SEXP R_PDFDoc_getFileName(SEXP r_tthis)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    GooString * ans;
    ans = tthis->getFileName();
    SEXP r_ans = GooStringToR(ans);
    return(r_ans);
}

SEXP R_PDFDoc_getLinearization(SEXP r_tthis)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    Linearization * ans;
    ans = tthis->getLinearization();
    SEXP r_ans = R_createRef(ans, "LinearizationPtr");
    return(r_ans);
}

SEXP R_PDFDoc_checkLinearization(SEXP r_tthis)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    GBool ans;
    ans = tthis->checkLinearization();
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

SEXP R_PDFDoc_getXRef(SEXP r_tthis)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    XRef * ans;
    ans = tthis->getXRef();
    SEXP r_ans = R_createRef(ans, "XRefPtr");
    return(r_ans);
}

SEXP R_PDFDoc_getCatalog(SEXP r_tthis)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    Catalog * ans;
    ans = tthis->getCatalog();
    SEXP r_ans = R_createRef(ans, "CatalogPtr");
    return(r_ans);
}

SEXP R_PDFDoc_getOptContentConfig(SEXP r_tthis)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    OCGs * ans;
    ans = tthis->getOptContentConfig();
    SEXP r_ans = R_createRef(ans, "OCGsPtr");
    return(r_ans);
}

SEXP R_PDFDoc_getBaseStream(SEXP r_tthis)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    BaseStream * ans;
    ans = tthis->getBaseStream();
    SEXP r_ans = R_createRef(ans, "BaseStreamPtr");
    return(r_ans);
}

SEXP R_PDFDoc_getPageMediaWidth(SEXP r_tthis, SEXP r_page)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    int page;
    page = INTEGER(r_page)[0];
    double ans;
    ans = tthis->getPageMediaWidth(page);
    SEXP r_ans = Rf_ScalarReal(ans);
    return(r_ans);
}

SEXP R_PDFDoc_getPageMediaHeight(SEXP r_tthis, SEXP r_page)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    int page;
    page = INTEGER(r_page)[0];
    double ans;
    ans = tthis->getPageMediaHeight(page);
    SEXP r_ans = Rf_ScalarReal(ans);
    return(r_ans);
}

SEXP R_PDFDoc_getPageCropWidth(SEXP r_tthis, SEXP r_page)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    int page;
    page = INTEGER(r_page)[0];
    double ans;
    ans = tthis->getPageCropWidth(page);
    SEXP r_ans = Rf_ScalarReal(ans);
    return(r_ans);
}

SEXP R_PDFDoc_getPageCropHeight(SEXP r_tthis, SEXP r_page)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    int page;
    page = INTEGER(r_page)[0];
    double ans;
    ans = tthis->getPageCropHeight(page);
    SEXP r_ans = Rf_ScalarReal(ans);
    return(r_ans);
}

SEXP R_PDFDoc_getPageRotate(SEXP r_tthis, SEXP r_page)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    int page;
    page = INTEGER(r_page)[0];
    int ans;
    ans = tthis->getPageRotate(page);
    SEXP r_ans = Rf_ScalarInteger(ans);
    return(r_ans);
}

SEXP R_PDFDoc_getNumPages(SEXP r_tthis)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    int ans;
    ans = tthis->getNumPages();
    SEXP r_ans = Rf_ScalarInteger(ans);
    return(r_ans);
}

SEXP R_PDFDoc_readMetadata(SEXP r_tthis)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    GooString * ans;
    ans = tthis->readMetadata();
    SEXP r_ans = GooStringToR(ans);
    return(r_ans);
}

SEXP R_PDFDoc_getStructTreeRoot(SEXP r_tthis)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    StructTreeRoot * ans;
    ans = tthis->getStructTreeRoot();
    SEXP r_ans = R_createRef(ans, "StructTreeRootPtr");
    return(r_ans);
}

SEXP R_PDFDoc_getPage(SEXP r_tthis, SEXP r_page)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    int page;
    page = INTEGER(r_page)[0];
    Page * ans;
    ans = tthis->getPage(page);
    SEXP r_ans = R_createRef(ans, "PagePtr");
    return(r_ans);
}

SEXP R_PDFDoc_findPage(SEXP r_tthis, SEXP r_num, SEXP r_gen)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    int num;
    num = INTEGER(r_num)[0];
    int gen;
    gen = INTEGER(r_gen)[0];
    int ans;
    ans = tthis->findPage(num, gen);
    SEXP r_ans = Rf_ScalarInteger(ans);
    return(r_ans);
}

SEXP R_PDFDoc_getLinks(SEXP r_tthis, SEXP r_page)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    int page;
    page = INTEGER(r_page)[0];
    Links * ans;
    ans = tthis->getLinks(page);
    SEXP r_ans = R_createRef(ans, "LinksPtr");
    return(r_ans);
}

SEXP R_PDFDoc_findDest(SEXP r_tthis, SEXP r_name)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    GooString * name;
    name = GET_REF(r_name, GooString );
    LinkDest * ans;
    ans = tthis->findDest(name);
    SEXP r_ans = R_createRef(ans, "LinkDestPtr");
    return(r_ans);
}

SEXP R_PDFDoc_processLinks(SEXP r_tthis, SEXP r_out, SEXP r_page)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    OutputDev * out;
    out = GET_REF(r_out, OutputDev );
    int page;
    page = INTEGER(r_page)[0];
    tthis->processLinks(out, page);
    return(R_NilValue);
}

SEXP R_PDFDoc_getOutline(SEXP r_tthis)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    Outline * ans;
    ans = tthis->getOutline();
    SEXP r_ans = R_createRef(ans, "OutlinePtr");
    return(r_ans);
}

SEXP R_PDFDoc_isEncrypted(SEXP r_tthis)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    GBool ans;
    ans = tthis->isEncrypted();
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

SEXP R_PDFDoc_okToPrint(SEXP r_tthis, SEXP r_ignoreOwnerPW)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    GBool ignoreOwnerPW;
    ignoreOwnerPW = LOGICAL(r_ignoreOwnerPW)[0];
    GBool ans;
    ans = tthis->okToPrint(ignoreOwnerPW);
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

SEXP R_PDFDoc_okToPrintHighRes(SEXP r_tthis, SEXP r_ignoreOwnerPW)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    GBool ignoreOwnerPW;
    ignoreOwnerPW = LOGICAL(r_ignoreOwnerPW)[0];
    GBool ans;
    ans = tthis->okToPrintHighRes(ignoreOwnerPW);
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

SEXP R_PDFDoc_okToChange(SEXP r_tthis, SEXP r_ignoreOwnerPW)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    GBool ignoreOwnerPW;
    ignoreOwnerPW = LOGICAL(r_ignoreOwnerPW)[0];
    GBool ans;
    ans = tthis->okToChange(ignoreOwnerPW);
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

SEXP R_PDFDoc_okToCopy(SEXP r_tthis, SEXP r_ignoreOwnerPW)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    GBool ignoreOwnerPW;
    ignoreOwnerPW = LOGICAL(r_ignoreOwnerPW)[0];
    GBool ans;
    ans = tthis->okToCopy(ignoreOwnerPW);
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

SEXP R_PDFDoc_okToAddNotes(SEXP r_tthis, SEXP r_ignoreOwnerPW)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    GBool ignoreOwnerPW;
    ignoreOwnerPW = LOGICAL(r_ignoreOwnerPW)[0];
    GBool ans;
    ans = tthis->okToAddNotes(ignoreOwnerPW);
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

SEXP R_PDFDoc_okToFillForm(SEXP r_tthis, SEXP r_ignoreOwnerPW)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    GBool ignoreOwnerPW;
    ignoreOwnerPW = LOGICAL(r_ignoreOwnerPW)[0];
    GBool ans;
    ans = tthis->okToFillForm(ignoreOwnerPW);
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

SEXP R_PDFDoc_okToAccessibility(SEXP r_tthis, SEXP r_ignoreOwnerPW)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    GBool ignoreOwnerPW;
    ignoreOwnerPW = LOGICAL(r_ignoreOwnerPW)[0];
    GBool ans;
    ans = tthis->okToAccessibility(ignoreOwnerPW);
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

SEXP R_PDFDoc_okToAssemble(SEXP r_tthis, SEXP r_ignoreOwnerPW)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    GBool ignoreOwnerPW;
    ignoreOwnerPW = LOGICAL(r_ignoreOwnerPW)[0];
    GBool ans;
    ans = tthis->okToAssemble(ignoreOwnerPW);
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

SEXP R_PDFDoc_isLinearized(SEXP r_tthis, SEXP r_tryingToReconstruct)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    GBool tryingToReconstruct;
    tryingToReconstruct = LOGICAL(r_tryingToReconstruct)[0];
    GBool ans;
    ans = tthis->isLinearized(tryingToReconstruct);
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

SEXP R_PDFDoc_getDocInfo(SEXP r_tthis, SEXP r_obj)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    Object * obj;
    obj = GET_REF(r_obj, Object );
    Object * ans;
    ans = tthis->getDocInfo(obj);
    SEXP r_ans = R_createRef(ans, "ObjectPtr");
    return(r_ans);
}

SEXP R_PDFDoc_getDocInfoNF(SEXP r_tthis, SEXP r_obj)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    Object * obj;
    obj = GET_REF(r_obj, Object );
    Object * ans;
    ans = tthis->getDocInfoNF(obj);
    SEXP r_ans = R_createRef(ans, "ObjectPtr");
    return(r_ans);
}

SEXP R_PDFDoc_createDocInfoIfNoneExists(SEXP r_tthis, SEXP r_obj)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    Object * obj;
    obj = GET_REF(r_obj, Object );
    Object * ans;
    ans = tthis->createDocInfoIfNoneExists(obj);
    SEXP r_ans = R_createRef(ans, "ObjectPtr");
    return(r_ans);
}

SEXP R_PDFDoc_removeDocInfo(SEXP r_tthis)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    tthis->removeDocInfo();
    return(R_NilValue);
}

SEXP R_PDFDoc_setDocInfoStringEntry(SEXP r_tthis, SEXP r_key, SEXP r_value)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    const char * key;
    key = CHAR(STRING_ELT(r_key, 0));
    GooString * value;
    value = GET_REF(r_value, GooString );
    tthis->setDocInfoStringEntry(key, value);
    return(R_NilValue);
}

SEXP R_PDFDoc_setDocInfoTitle(SEXP r_tthis, SEXP r_title)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    GooString * title;
    title = GET_REF(r_title, GooString );
    tthis->setDocInfoTitle(title);
    return(R_NilValue);
}

SEXP R_PDFDoc_setDocInfoAuthor(SEXP r_tthis, SEXP r_author)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    GooString * author;
    author = GET_REF(r_author, GooString );
    tthis->setDocInfoAuthor(author);
    return(R_NilValue);
}

SEXP R_PDFDoc_setDocInfoSubject(SEXP r_tthis, SEXP r_subject)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    GooString * subject;
    subject = GET_REF(r_subject, GooString );
    tthis->setDocInfoSubject(subject);
    return(R_NilValue);
}

SEXP R_PDFDoc_setDocInfoKeywords(SEXP r_tthis, SEXP r_keywords)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    GooString * keywords;
    keywords = GET_REF(r_keywords, GooString );
    tthis->setDocInfoKeywords(keywords);
    return(R_NilValue);
}

SEXP R_PDFDoc_setDocInfoCreator(SEXP r_tthis, SEXP r_creator)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    GooString * creator;
    creator = GET_REF(r_creator, GooString );
    tthis->setDocInfoCreator(creator);
    return(R_NilValue);
}

SEXP R_PDFDoc_setDocInfoProducer(SEXP r_tthis, SEXP r_producer)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    GooString * producer;
    producer = GET_REF(r_producer, GooString );
    tthis->setDocInfoProducer(producer);
    return(R_NilValue);
}

SEXP R_PDFDoc_setDocInfoCreatDate(SEXP r_tthis, SEXP r_creatDate)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    GooString * creatDate;
    creatDate = GET_REF(r_creatDate, GooString );
    tthis->setDocInfoCreatDate(creatDate);
    return(R_NilValue);
}

SEXP R_PDFDoc_setDocInfoModDate(SEXP r_tthis, SEXP r_modDate)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    GooString * modDate;
    modDate = GET_REF(r_modDate, GooString );
    tthis->setDocInfoModDate(modDate);
    return(R_NilValue);
}

SEXP R_PDFDoc_getDocInfoStringEntry(SEXP r_tthis, SEXP r_key)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    const char * key;
    key = CHAR(STRING_ELT(r_key, 0));
    GooString * ans;
    ans = tthis->getDocInfoStringEntry(key);
    SEXP r_ans = GooStringToR(ans);
    return(r_ans);
}

SEXP R_PDFDoc_getDocInfoTitle(SEXP r_tthis)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    GooString * ans;
    ans = tthis->getDocInfoTitle();
    SEXP r_ans = GooStringToR(ans);
    return(r_ans);
}

SEXP R_PDFDoc_getDocInfoAuthor(SEXP r_tthis)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    GooString * ans;
    ans = tthis->getDocInfoAuthor();
    SEXP r_ans = GooStringToR(ans);
    return(r_ans);
}

SEXP R_PDFDoc_getDocInfoSubject(SEXP r_tthis)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    GooString * ans;
    ans = tthis->getDocInfoSubject();
    SEXP r_ans = GooStringToR(ans);
    return(r_ans);
}

SEXP R_PDFDoc_getDocInfoKeywords(SEXP r_tthis)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    GooString * ans;
    ans = tthis->getDocInfoKeywords();
    SEXP r_ans = GooStringToR(ans);
    return(r_ans);
}

SEXP R_PDFDoc_getDocInfoCreator(SEXP r_tthis)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    GooString * ans;
    ans = tthis->getDocInfoCreator();
    SEXP r_ans = GooStringToR(ans);
    return(r_ans);
}

SEXP R_PDFDoc_getDocInfoProducer(SEXP r_tthis)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    GooString * ans;
    ans = tthis->getDocInfoProducer();
    SEXP r_ans = GooStringToR(ans);
    return(r_ans);
}

SEXP R_PDFDoc_getDocInfoCreatDate(SEXP r_tthis)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    GooString * ans;
    ans = tthis->getDocInfoCreatDate();
    SEXP r_ans = GooStringToR(ans);
    return(r_ans);
}

SEXP R_PDFDoc_getDocInfoModDate(SEXP r_tthis)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    GooString * ans;
    ans = tthis->getDocInfoModDate();
    SEXP r_ans = GooStringToR(ans);
    return(r_ans);
}

SEXP R_PDFDoc_getPDFMajorVersion(SEXP r_tthis)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    int ans;
    ans = tthis->getPDFMajorVersion();
    SEXP r_ans = Rf_ScalarInteger(ans);
    return(r_ans);
}

SEXP R_PDFDoc_getPDFMinorVersion(SEXP r_tthis)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    int ans;
    ans = tthis->getPDFMinorVersion();
    SEXP r_ans = Rf_ScalarInteger(ans);
    return(r_ans);
}

SEXP R_PDFDoc_getID(SEXP r_tthis, SEXP r_permanent_id, SEXP r_update_id)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    GooString * permanent_id;
    permanent_id = GET_REF(r_permanent_id, GooString );
    GooString * update_id;
    update_id = GET_REF(r_update_id, GooString );
    GBool ans;
    ans = tthis->getID(permanent_id, update_id);
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

SEXP R_PDFDoc_savePageAs(SEXP r_tthis, SEXP r_name, SEXP r_pageNo)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    GooString * name;
    name = GET_REF(r_name, GooString );
    int pageNo;
    pageNo = INTEGER(r_pageNo)[0];
    int ans;
    ans = tthis->savePageAs(name, pageNo);
    SEXP r_ans = Rf_ScalarInteger(ans);
    return(r_ans);
}

SEXP R_PDFDoc_saveAs(SEXP r_tthis, SEXP r_outStr, SEXP r_mode)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    OutStream * outStr;
    outStr = GET_REF(r_outStr, OutStream );
    PDFWriteMode mode;
    mode = (PDFWriteMode) INTEGER(r_mode)[0];
    int ans;
    ans = tthis->saveAs(outStr, mode);
    SEXP r_ans = Rf_ScalarInteger(ans);
    return(r_ans);
}

SEXP R_PDFDoc_saveWithoutChangesAs(SEXP r_tthis, SEXP r_outStr)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    OutStream * outStr;
    outStr = GET_REF(r_outStr, OutStream );
    int ans;
    ans = tthis->saveWithoutChangesAs(outStr);
    SEXP r_ans = Rf_ScalarInteger(ans);
    return(r_ans);
}

SEXP R_PDFDoc_getGUIData(SEXP r_tthis)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    void * ans;
    ans = tthis->getGUIData();
    SEXP r_ans = R_createRef(ans, "voidPtr");
    return(r_ans);
}

SEXP R_PDFDoc_replacePageDict(SEXP r_tthis, SEXP r_pageNo, SEXP r_rotate, SEXP r_mediaBox, SEXP r_cropBox)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    int pageNo;
    pageNo = INTEGER(r_pageNo)[0];
    int rotate;
    rotate = INTEGER(r_rotate)[0];
    PDFRectangle * mediaBox;
    mediaBox = GET_REF(r_mediaBox, PDFRectangle );
    PDFRectangle * cropBox;
    cropBox = GET_REF(r_cropBox, PDFRectangle );
    tthis->replacePageDict(pageNo, rotate, mediaBox, cropBox);
    return(R_NilValue);
}

SEXP R_PDFDoc_markPageObjects(SEXP r_tthis, SEXP r_pageDict, SEXP r_xRef, SEXP r_countRef, SEXP r_numOffset, SEXP r_oldRefNum, SEXP r_newRefNum)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    Dict * pageDict;
    pageDict = GET_REF(r_pageDict, Dict );
    XRef * xRef;
    xRef = GET_REF(r_xRef, XRef );
    XRef * countRef;
    countRef = GET_REF(r_countRef, XRef );
    Guint numOffset;
    numOffset = REAL(r_numOffset)[0];
    int oldRefNum;
    oldRefNum = INTEGER(r_oldRefNum)[0];
    int newRefNum;
    newRefNum = INTEGER(r_newRefNum)[0];
    tthis->markPageObjects(pageDict, xRef, countRef, numOffset, oldRefNum, newRefNum);
    return(R_NilValue);
}

SEXP R_PDFDoc_markAnnotations(SEXP r_tthis, SEXP r_annots, SEXP r_xRef, SEXP r_countRef, SEXP r_numOffset, SEXP r_oldPageNum, SEXP r_newPageNum)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    Object * annots;
    annots = GET_REF(r_annots, Object );
    XRef * xRef;
    xRef = GET_REF(r_xRef, XRef );
    XRef * countRef;
    countRef = GET_REF(r_countRef, XRef );
    Guint numOffset;
    numOffset = REAL(r_numOffset)[0];
    int oldPageNum;
    oldPageNum = INTEGER(r_oldPageNum)[0];
    int newPageNum;
    newPageNum = INTEGER(r_newPageNum)[0];
    GBool ans;
    ans = tthis->markAnnotations(annots, xRef, countRef, numOffset, oldPageNum, newPageNum);
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

SEXP R_PDFDoc_markAcroForm(SEXP r_tthis, SEXP r_acrpForm, SEXP r_xRef, SEXP r_countRef, SEXP r_numOffset, SEXP r_oldPageNum, SEXP r_newPageNum)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    Object * acrpForm;
    acrpForm = GET_REF(r_acrpForm, Object );
    XRef * xRef;
    xRef = GET_REF(r_xRef, XRef );
    XRef * countRef;
    countRef = GET_REF(r_countRef, XRef );
    Guint numOffset;
    numOffset = REAL(r_numOffset)[0];
    int oldPageNum;
    oldPageNum = INTEGER(r_oldPageNum)[0];
    int newPageNum;
    newPageNum = INTEGER(r_newPageNum)[0];
    tthis->markAcroForm(acrpForm, xRef, countRef, numOffset, oldPageNum, newPageNum);
    return(R_NilValue);
}

SEXP R_PDFDoc_writePageObjects(SEXP r_tthis, SEXP r_outStr, SEXP r_xRef, SEXP r_numOffset, SEXP r_combine)
{
    PDFDoc *tthis = GET_REF(r_tthis, PDFDoc);
    OutStream * outStr;
    outStr = GET_REF(r_outStr, OutStream );
    XRef * xRef;
    xRef = GET_REF(r_xRef, XRef );
    Guint numOffset;
    numOffset = REAL(r_numOffset)[0];
    GBool combine;
    combine = LOGICAL(r_combine)[0];
    Guint ans;
    ans = tthis->writePageObjects(outStr, xRef, numOffset, combine);
    SEXP r_ans = Rf_ScalarReal(ans);
    return(r_ans);
}

SEXP R_PDFDoc_writeHeader(SEXP r_outStr, SEXP r_major, SEXP r_minor)
{
    OutStream * outStr;
    outStr = GET_REF(r_outStr, OutStream );
    int major;
    major = INTEGER(r_major)[0];
    int minor;
    minor = INTEGER(r_minor)[0];
    PDFDoc::writeHeader(outStr, major, minor);
    return(R_NilValue);
}

SEXP R_PDFDoc_createTrailerDict(SEXP r_uxrefSize, SEXP r_incrUpdate, SEXP r_startxRef, SEXP r_root, SEXP r_xRef, SEXP r_fileName, SEXP r_fileSize)
{
    int uxrefSize;
    uxrefSize = INTEGER(r_uxrefSize)[0];
    GBool incrUpdate;
    incrUpdate = LOGICAL(r_incrUpdate)[0];
    Goffset startxRef;
    startxRef = REAL(r_startxRef)[0];
    Ref * root;
    root = GET_REF(r_root, Ref );
    XRef * xRef;
    xRef = GET_REF(r_xRef, XRef );
    const char * fileName;
    fileName = CHAR(STRING_ELT(r_fileName, 0));
    Goffset fileSize;
    fileSize = REAL(r_fileSize)[0];
    Dict * ans;
    ans = PDFDoc::createTrailerDict(uxrefSize, incrUpdate, startxRef, root, xRef, fileName, fileSize);
    SEXP r_ans = R_createRef(ans, "DictPtr");
    return(r_ans);
}

SEXP R_PDFDoc_writeXRefStreamTrailer(SEXP r_trailerDict, SEXP r_uxref, SEXP r_uxrefStreamRef, SEXP r_uxrefOffset, SEXP r_outStr, SEXP r_xRef)
{
    Dict * trailerDict;
    trailerDict = GET_REF(r_trailerDict, Dict );
    XRef * uxref;
    uxref = GET_REF(r_uxref, XRef );
    Ref * uxrefStreamRef;
    uxrefStreamRef = GET_REF(r_uxrefStreamRef, Ref );
    Goffset uxrefOffset;
    uxrefOffset = REAL(r_uxrefOffset)[0];
    OutStream * outStr;
    outStr = GET_REF(r_outStr, OutStream );
    XRef * xRef;
    xRef = GET_REF(r_xRef, XRef );
    PDFDoc::writeXRefStreamTrailer(trailerDict, uxref, uxrefStreamRef, uxrefOffset, outStr, xRef);
    return(R_NilValue);
}
