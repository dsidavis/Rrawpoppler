#define R_NO_REMAP 1

#include "Rpoppler.h"

extern "C"
SEXP R_Catalog_isOk(SEXP r_tthis)
{
    Catalog *tthis = GET_REF(r_tthis, Catalog);
    GBool ans;
    ans = tthis->isOk();
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

extern "C"
SEXP R_Catalog_getNumPages(SEXP r_tthis)
{
    Catalog *tthis = GET_REF(r_tthis, Catalog);
    int ans;
    ans = tthis->getNumPages();
    SEXP r_ans = Rf_ScalarInteger(ans);
    return(r_ans);
}

extern "C"
SEXP R_Catalog_getPage(SEXP r_tthis, SEXP r_i)
{
    Catalog *tthis = GET_REF(r_tthis, Catalog);
    int i;
    i = INTEGER(r_i)[0];
    Page * ans;
    ans = tthis->getPage(i);
    SEXP r_ans = R_createRef(ans, "PagePtr", NULL);
    return(r_ans);
}

extern "C"
SEXP R_Catalog_getPageRef(SEXP r_tthis, SEXP r_i)
{
    Catalog *tthis = GET_REF(r_tthis, Catalog);
    int i;
    i = INTEGER(r_i)[0];
    Ref * ans;
    ans = tthis->getPageRef(i);
    SEXP r_ans = R_createRef(ans, "RefPtr", NULL);
    return(r_ans);
}

extern "C"
SEXP R_Catalog_getBaseURI(SEXP r_tthis)
{
    Catalog *tthis = GET_REF(r_tthis, Catalog);
    GooString * ans;
    ans = tthis->getBaseURI();
    SEXP r_ans = GooStringToR(ans);
    return(r_ans);
}

extern "C"
SEXP R_Catalog_readMetadata(SEXP r_tthis)
{
    Catalog *tthis = GET_REF(r_tthis, Catalog);
    GooString * ans;
    ans = tthis->readMetadata();
    SEXP r_ans = GooStringToR(ans);
    return(r_ans);
}

extern "C"
SEXP R_Catalog_getStructTreeRoot(SEXP r_tthis)
{
    Catalog *tthis = GET_REF(r_tthis, Catalog);
    StructTreeRoot * ans;
    ans = tthis->getStructTreeRoot();
    SEXP r_ans = R_createRef(ans, "StructTreeRootPtr", NULL);
    return(r_ans);
}

extern "C"
SEXP R_Catalog_getMarkInfo(SEXP r_tthis)
{
    Catalog *tthis = GET_REF(r_tthis, Catalog);
    Guint ans;
    ans = tthis->getMarkInfo();
    SEXP r_ans = Rf_ScalarReal(ans);
    return(r_ans);
}

extern "C"
SEXP R_Catalog_findPage(SEXP r_tthis, SEXP r_num, SEXP r_gen)
{
    Catalog *tthis = GET_REF(r_tthis, Catalog);
    int num;
    num = INTEGER(r_num)[0];
    int gen;
    gen = INTEGER(r_gen)[0];
    int ans;
    ans = tthis->findPage(num, gen);
    SEXP r_ans = Rf_ScalarInteger(ans);
    return(r_ans);
}

extern "C"
SEXP R_Catalog_findDest(SEXP r_tthis, SEXP r_name)
{
    Catalog *tthis = GET_REF(r_tthis, Catalog);
    GooString * name;
    name = GooStringFromR(r_name);
    LinkDest * ans;
    ans = tthis->findDest(name);
    SEXP r_ans = R_createRef(ans, "LinkDestPtr", NULL);
    return(r_ans);
}

extern "C"
SEXP R_Catalog_getDests(SEXP r_tthis)
{
    Catalog *tthis = GET_REF(r_tthis, Catalog);
    Object * ans;
    ans = tthis->getDests();
    SEXP r_ans = R_createRef(ans, "ObjectPtr", NULL);
    return(r_ans);
}

extern "C"
SEXP R_Catalog_numEmbeddedFiles(SEXP r_tthis)
{
    Catalog *tthis = GET_REF(r_tthis, Catalog);
    int ans;
    ans = tthis->numEmbeddedFiles();
    SEXP r_ans = Rf_ScalarInteger(ans);
    return(r_ans);
}

extern "C"
SEXP R_Catalog_embeddedFile(SEXP r_tthis, SEXP r_i)
{
    Catalog *tthis = GET_REF(r_tthis, Catalog);
    int i;
    i = INTEGER(r_i)[0];
    FileSpec * ans;
    ans = tthis->embeddedFile(i);
    SEXP r_ans = R_createRef(ans, "FileSpecPtr", NULL);
    return(r_ans);
}

extern "C"
SEXP R_Catalog_numJS(SEXP r_tthis)
{
    Catalog *tthis = GET_REF(r_tthis, Catalog);
    int ans;
    ans = tthis->numJS();
    SEXP r_ans = Rf_ScalarInteger(ans);
    return(r_ans);
}

extern "C"
SEXP R_Catalog_getJSName(SEXP r_tthis, SEXP r_i)
{
    Catalog *tthis = GET_REF(r_tthis, Catalog);
    int i;
    i = INTEGER(r_i)[0];
    GooString * ans;
    ans = tthis->getJSName(i);
    SEXP r_ans = GooStringToR(ans);
    return(r_ans);
}

extern "C"
SEXP R_Catalog_getJS(SEXP r_tthis, SEXP r_i)
{
    Catalog *tthis = GET_REF(r_tthis, Catalog);
    int i;
    i = INTEGER(r_i)[0];
    GooString * ans;
    ans = tthis->getJS(i);
    SEXP r_ans = GooStringToR(ans);
    return(r_ans);
}

extern "C"
SEXP R_Catalog_labelToIndex(SEXP r_tthis, SEXP r_label, SEXP r_index)
{
    Catalog *tthis = GET_REF(r_tthis, Catalog);
    GooString * label;
    label = GooStringFromR(r_label);
    int * index;
    index = INTEGER(r_index);
    GBool ans;
    ans = tthis->labelToIndex(label, index);
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

extern "C"
SEXP R_Catalog_indexToLabel(SEXP r_tthis, SEXP r_index, SEXP r_label)
{
    Catalog *tthis = GET_REF(r_tthis, Catalog);
    int index;
    index = INTEGER(r_index)[0];
    GooString * label;
    label = GooStringFromR(r_label);
    GBool ans;
    ans = tthis->indexToLabel(index, label);
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

extern "C"
SEXP R_Catalog_getOutline(SEXP r_tthis)
{
    Catalog *tthis = GET_REF(r_tthis, Catalog);
    Object * ans;
    ans = tthis->getOutline();
    SEXP r_ans = R_createRef(ans, "ObjectPtr", NULL);
    return(r_ans);
}

extern "C"
SEXP R_Catalog_getAcroForm(SEXP r_tthis)
{
    Catalog *tthis = GET_REF(r_tthis, Catalog);
    Object * ans;
    ans = tthis->getAcroForm();
    SEXP r_ans = R_createRef(ans, "ObjectPtr", NULL);
    return(r_ans);
}

extern "C"
SEXP R_Catalog_getOptContentConfig(SEXP r_tthis)
{
    Catalog *tthis = GET_REF(r_tthis, Catalog);
    OCGs * ans;
    ans = tthis->getOptContentConfig();
    SEXP r_ans = R_createRef(ans, "OCGsPtr", NULL);
    return(r_ans);
}

extern "C"
SEXP R_Catalog_getForm(SEXP r_tthis)
{
    Catalog *tthis = GET_REF(r_tthis, Catalog);
    Form * ans;
    ans = tthis->getForm();
    SEXP r_ans = R_createRef(ans, "FormPtr", NULL);
    return(r_ans);
}

extern "C"
SEXP R_Catalog_getViewerPreferences(SEXP r_tthis)
{
    Catalog *tthis = GET_REF(r_tthis, Catalog);
    ViewerPreferences * ans;
    ans = tthis->getViewerPreferences();
    SEXP r_ans = R_createRef(ans, "ViewerPreferencesPtr", NULL);
    return(r_ans);
}

extern "C"
SEXP R_Catalog_getAdditionalAction(SEXP r_tthis, SEXP r_type)
{
    Catalog *tthis = GET_REF(r_tthis, Catalog);
    Catalog::DocumentAdditionalActionsType type;
    type = (Catalog::DocumentAdditionalActionsType) INTEGER(r_type)[0];
    LinkAction * ans;
    ans = tthis->getAdditionalAction(type);
    SEXP r_ans = R_createRef(ans, "LinkActionPtr", NULL);
    return(r_ans);
}
