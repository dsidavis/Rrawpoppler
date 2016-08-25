#define R_NO_REMAP 1

#include "Rpoppler.h"

extern "C"
SEXP R_XRef_copy(SEXP r_tthis)
{
    XRef *tthis = GET_REF(r_tthis, XRef);
    XRef * ans;
    ans = tthis->copy();
    SEXP r_ans = R_createRef(ans, "XRefPtr");
    return(r_ans);
}

extern "C"
SEXP R_XRef_isOk(SEXP r_tthis)
{
    XRef *tthis = GET_REF(r_tthis, XRef);
    GBool ans;
    ans = tthis->isOk();
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

extern "C"
SEXP R_XRef_isXRefStream(SEXP r_tthis)
{
    XRef *tthis = GET_REF(r_tthis, XRef);
    GBool ans;
    ans = tthis->isXRefStream();
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

extern "C"
SEXP R_XRef_getErrorCode(SEXP r_tthis)
{
    XRef *tthis = GET_REF(r_tthis, XRef);
    int ans;
    ans = tthis->getErrorCode();
    SEXP r_ans = Rf_ScalarInteger(ans);
    return(r_ans);
}

extern "C"
SEXP R_XRef_setEncryption(SEXP r_tthis, SEXP r_permFlagsA, SEXP r_ownerPasswordOkA, SEXP r_fileKeyA, SEXP r_keyLengthA, SEXP r_encVersionA, SEXP r_encRevisionA, SEXP r_encAlgorithmA)
{
    XRef *tthis = GET_REF(r_tthis, XRef);
    int permFlagsA;
    permFlagsA = INTEGER(r_permFlagsA)[0];
    GBool ownerPasswordOkA;
    ownerPasswordOkA = LOGICAL(r_ownerPasswordOkA)[0];
    Guchar * fileKeyA;
    fileKeyA = (Guchar *) RAW(r_fileKeyA);
    int keyLengthA;
    keyLengthA = INTEGER(r_keyLengthA)[0];
    int encVersionA;
    encVersionA = INTEGER(r_encVersionA)[0];
    int encRevisionA;
    encRevisionA = INTEGER(r_encRevisionA)[0];
    CryptAlgorithm encAlgorithmA;
    encAlgorithmA = (CryptAlgorithm) INTEGER(r_encAlgorithmA)[0];
    tthis->setEncryption(permFlagsA, ownerPasswordOkA, fileKeyA, keyLengthA, encVersionA, encRevisionA, encAlgorithmA);
    return(R_NilValue);
}

extern "C"
SEXP R_XRef_getEncryptionParameters(SEXP r_tthis, SEXP r_fileKeyA, SEXP r_encAlgorithmA, SEXP r_keyLengthA)
{
    XRef *tthis = GET_REF(r_tthis, XRef);
    Guchar ** fileKeyA;
    fileKeyA = GET_REF(r_fileKeyA, Guchar *);
    CryptAlgorithm * encAlgorithmA;
    encAlgorithmA = GET_REF(r_encAlgorithmA, CryptAlgorithm );
    int * keyLengthA;
    keyLengthA = INTEGER(r_keyLengthA);
    tthis->getEncryptionParameters(fileKeyA, encAlgorithmA, keyLengthA);
    return(R_NilValue);
}

extern "C"
SEXP R_XRef_isEncrypted(SEXP r_tthis)
{
    XRef *tthis = GET_REF(r_tthis, XRef);
    GBool ans;
    ans = tthis->isEncrypted();
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

extern "C"
SEXP R_XRef_okToPrint(SEXP r_tthis, SEXP r_ignoreOwnerPW)
{
    XRef *tthis = GET_REF(r_tthis, XRef);
    GBool ignoreOwnerPW;
    ignoreOwnerPW = LOGICAL(r_ignoreOwnerPW)[0];
    GBool ans;
    ans = tthis->okToPrint(ignoreOwnerPW);
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

extern "C"
SEXP R_XRef_okToPrintHighRes(SEXP r_tthis, SEXP r_ignoreOwnerPW)
{
    XRef *tthis = GET_REF(r_tthis, XRef);
    GBool ignoreOwnerPW;
    ignoreOwnerPW = LOGICAL(r_ignoreOwnerPW)[0];
    GBool ans;
    ans = tthis->okToPrintHighRes(ignoreOwnerPW);
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

extern "C"
SEXP R_XRef_okToChange(SEXP r_tthis, SEXP r_ignoreOwnerPW)
{
    XRef *tthis = GET_REF(r_tthis, XRef);
    GBool ignoreOwnerPW;
    ignoreOwnerPW = LOGICAL(r_ignoreOwnerPW)[0];
    GBool ans;
    ans = tthis->okToChange(ignoreOwnerPW);
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

extern "C"
SEXP R_XRef_okToCopy(SEXP r_tthis, SEXP r_ignoreOwnerPW)
{
    XRef *tthis = GET_REF(r_tthis, XRef);
    GBool ignoreOwnerPW;
    ignoreOwnerPW = LOGICAL(r_ignoreOwnerPW)[0];
    GBool ans;
    ans = tthis->okToCopy(ignoreOwnerPW);
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

extern "C"
SEXP R_XRef_okToAddNotes(SEXP r_tthis, SEXP r_ignoreOwnerPW)
{
    XRef *tthis = GET_REF(r_tthis, XRef);
    GBool ignoreOwnerPW;
    ignoreOwnerPW = LOGICAL(r_ignoreOwnerPW)[0];
    GBool ans;
    ans = tthis->okToAddNotes(ignoreOwnerPW);
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

extern "C"
SEXP R_XRef_okToFillForm(SEXP r_tthis, SEXP r_ignoreOwnerPW)
{
    XRef *tthis = GET_REF(r_tthis, XRef);
    GBool ignoreOwnerPW;
    ignoreOwnerPW = LOGICAL(r_ignoreOwnerPW)[0];
    GBool ans;
    ans = tthis->okToFillForm(ignoreOwnerPW);
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

extern "C"
SEXP R_XRef_okToAccessibility(SEXP r_tthis, SEXP r_ignoreOwnerPW)
{
    XRef *tthis = GET_REF(r_tthis, XRef);
    GBool ignoreOwnerPW;
    ignoreOwnerPW = LOGICAL(r_ignoreOwnerPW)[0];
    GBool ans;
    ans = tthis->okToAccessibility(ignoreOwnerPW);
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

extern "C"
SEXP R_XRef_okToAssemble(SEXP r_tthis, SEXP r_ignoreOwnerPW)
{
    XRef *tthis = GET_REF(r_tthis, XRef);
    GBool ignoreOwnerPW;
    ignoreOwnerPW = LOGICAL(r_ignoreOwnerPW)[0];
    GBool ans;
    ans = tthis->okToAssemble(ignoreOwnerPW);
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

extern "C"
SEXP R_XRef_getPermFlags(SEXP r_tthis)
{
    XRef *tthis = GET_REF(r_tthis, XRef);
    int ans;
    ans = tthis->getPermFlags();
    SEXP r_ans = Rf_ScalarInteger(ans);
    return(r_ans);
}

extern "C"
SEXP R_XRef_getCatalog(SEXP r_tthis, SEXP r_obj)
{
    XRef *tthis = GET_REF(r_tthis, XRef);
    Object * obj;
    obj = GET_REF(r_obj, Object );
    Object * ans;
    ans = tthis->getCatalog(obj);
    SEXP r_ans = R_createRef(ans, "ObjectPtr");
    return(r_ans);
}

extern "C"
SEXP R_XRef_fetch(SEXP r_tthis, SEXP r_num, SEXP r_gen, SEXP r_obj, SEXP r_recursion)
{
    XRef *tthis = GET_REF(r_tthis, XRef);
    int num;
    num = INTEGER(r_num)[0];
    int gen;
    gen = INTEGER(r_gen)[0];
    Object * obj;
    obj = GET_REF(r_obj, Object );
    int recursion;
    recursion = INTEGER(r_recursion)[0];
    Object * ans;
    ans = tthis->fetch(num, gen, obj, recursion);
    SEXP r_ans = R_createRef(ans, "ObjectPtr");
    return(r_ans);
}

extern "C"
SEXP R_XRef_getDocInfo(SEXP r_tthis, SEXP r_obj)
{
    XRef *tthis = GET_REF(r_tthis, XRef);
    Object * obj;
    obj = GET_REF(r_obj, Object );
    Object * ans;
    ans = tthis->getDocInfo(obj);
    SEXP r_ans = R_createRef(ans, "ObjectPtr");
    return(r_ans);
}

extern "C"
SEXP R_XRef_getDocInfoNF(SEXP r_tthis, SEXP r_obj)
{
    XRef *tthis = GET_REF(r_tthis, XRef);
    Object * obj;
    obj = GET_REF(r_obj, Object );
    Object * ans;
    ans = tthis->getDocInfoNF(obj);
    SEXP r_ans = R_createRef(ans, "ObjectPtr");
    return(r_ans);
}

extern "C"
SEXP R_XRef_createDocInfoIfNoneExists(SEXP r_tthis, SEXP r_obj)
{
    XRef *tthis = GET_REF(r_tthis, XRef);
    Object * obj;
    obj = GET_REF(r_obj, Object );
    Object * ans;
    ans = tthis->createDocInfoIfNoneExists(obj);
    SEXP r_ans = R_createRef(ans, "ObjectPtr");
    return(r_ans);
}

extern "C"
SEXP R_XRef_removeDocInfo(SEXP r_tthis)
{
    XRef *tthis = GET_REF(r_tthis, XRef);
    tthis->removeDocInfo();
    return(R_NilValue);
}

extern "C"
SEXP R_XRef_getNumObjects(SEXP r_tthis)
{
    XRef *tthis = GET_REF(r_tthis, XRef);
    int ans;
    ans = tthis->getNumObjects();
    SEXP r_ans = Rf_ScalarInteger(ans);
    return(r_ans);
}

extern "C"
SEXP R_XRef_getRootNum(SEXP r_tthis)
{
    XRef *tthis = GET_REF(r_tthis, XRef);
    int ans;
    ans = tthis->getRootNum();
    SEXP r_ans = Rf_ScalarInteger(ans);
    return(r_ans);
}

extern "C"
SEXP R_XRef_getRootGen(SEXP r_tthis)
{
    XRef *tthis = GET_REF(r_tthis, XRef);
    int ans;
    ans = tthis->getRootGen();
    SEXP r_ans = Rf_ScalarInteger(ans);
    return(r_ans);
}

extern "C"
SEXP R_XRef_getStreamEnd(SEXP r_tthis, SEXP r_streamStart, SEXP r_streamEnd)
{
    XRef *tthis = GET_REF(r_tthis, XRef);
    Goffset streamStart;
    streamStart = REAL(r_streamStart)[0];
    Goffset * streamEnd;
    streamEnd = GET_REF(r_streamEnd, Goffset );
    GBool ans;
    ans = tthis->getStreamEnd(streamStart, streamEnd);
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

extern "C"
SEXP R_XRef_getNumEntry(SEXP r_tthis, SEXP r_offset)
{
    XRef *tthis = GET_REF(r_tthis, XRef);
    Goffset offset;
    offset = REAL(r_offset)[0];
    int ans;
    ans = tthis->getNumEntry(offset);
    SEXP r_ans = Rf_ScalarInteger(ans);
    return(r_ans);
}

extern "C"
SEXP R_XRef_scanSpecialFlags(SEXP r_tthis)
{
    XRef *tthis = GET_REF(r_tthis, XRef);
    tthis->scanSpecialFlags();
    return(R_NilValue);
}

extern "C"
SEXP R_XRef_getEntry(SEXP r_tthis, SEXP r_i, SEXP r_complainIfMissing)
{
    XRef *tthis = GET_REF(r_tthis, XRef);
    int i;
    i = INTEGER(r_i)[0];
    GBool complainIfMissing;
    complainIfMissing = LOGICAL(r_complainIfMissing)[0];
    XRefEntry * ans;
    ans = tthis->getEntry(i, complainIfMissing);
    SEXP r_ans = R_createRef(ans, "XRefEntryPtr");
    return(r_ans);
}

extern "C"
SEXP R_XRef_getTrailerDict(SEXP r_tthis)
{
    XRef *tthis = GET_REF(r_tthis, XRef);
    Object * ans;
    ans = tthis->getTrailerDict();
    SEXP r_ans = R_createRef(ans, "ObjectPtr");
    return(r_ans);
}

extern "C"
SEXP R_XRef_isModified(SEXP r_tthis)
{
    XRef *tthis = GET_REF(r_tthis, XRef);
    GBool ans;
    ans = tthis->isModified();
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

extern "C"
SEXP R_XRef_setModified(SEXP r_tthis)
{
    XRef *tthis = GET_REF(r_tthis, XRef);
    tthis->setModified();
    return(R_NilValue);
}

extern "C"
SEXP R_XRef_setModifiedObject(SEXP r_tthis, SEXP r_o, SEXP r_r)
{
    XRef *tthis = GET_REF(r_tthis, XRef);
    Object * o;
    o = GET_REF(r_o, Object );
    Ref r;
    r = * GET_REF(r_r, Ref);
    tthis->setModifiedObject(o, r);
    return(R_NilValue);
}

extern "C"
SEXP R_XRef_removeIndirectObject(SEXP r_tthis, SEXP r_r)
{
    XRef *tthis = GET_REF(r_tthis, XRef);
    Ref r;
    r = * GET_REF(r_r, Ref);
    tthis->removeIndirectObject(r);
    return(R_NilValue);
}

extern "C"
SEXP R_XRef_add(SEXP r_tthis, SEXP r_num, SEXP r_gen, SEXP r_offs, SEXP r_used)
{
    XRef *tthis = GET_REF(r_tthis, XRef);
    int num;
    num = INTEGER(r_num)[0];
    int gen;
    gen = INTEGER(r_gen)[0];
    Goffset offs;
    offs = REAL(r_offs)[0];
    GBool used;
    used = LOGICAL(r_used)[0];
    tthis->add(num, gen, offs, used);
    return(R_NilValue);
}

extern "C"
SEXP R_XRef_writeTableToFile(SEXP r_tthis, SEXP r_outStr, SEXP r_writeAllEntries)
{
    XRef *tthis = GET_REF(r_tthis, XRef);
    OutStream * outStr;
    outStr = GET_REF(r_outStr, OutStream );
    GBool writeAllEntries;
    writeAllEntries = LOGICAL(r_writeAllEntries)[0];
    tthis->writeTableToFile(outStr, writeAllEntries);
    return(R_NilValue);
}

extern "C"
SEXP R_XRef_writeStreamToBuffer(SEXP r_tthis, SEXP r_stmBuf, SEXP r_xrefDict, SEXP r_xref)
{
    XRef *tthis = GET_REF(r_tthis, XRef);
    GooString * stmBuf;
    stmBuf = GooStringFromR(r_stmBuf);
    Dict * xrefDict;
    xrefDict = GET_REF(r_xrefDict, Dict );
    XRef * xref;
    xref = GET_REF(r_xref, XRef );
    tthis->writeStreamToBuffer(stmBuf, xrefDict, xref);
    return(R_NilValue);
}

extern "C"
SEXP R_XRef_lock(SEXP r_tthis)
{
    XRef *tthis = GET_REF(r_tthis, XRef);
    tthis->lock();
    return(R_NilValue);
}

extern "C"
SEXP R_XRef_unlock(SEXP r_tthis)
{
    XRef *tthis = GET_REF(r_tthis, XRef);
    tthis->unlock();
    return(R_NilValue);
}
