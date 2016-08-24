#define R_NO_REMAP 1

#include "Rpoppler.h"

SEXP R_Object_zeroUnion(SEXP r_tthis)
{
    Object *tthis = GET_REF(r_tthis, Object);
    tthis->zeroUnion();
    return(R_NilValue);
}

SEXP R_Object_initBool(SEXP r_tthis, SEXP r_boolnA)
{
    Object *tthis = GET_REF(r_tthis, Object);
    GBool boolnA;
    boolnA = LOGICAL(r_boolnA)[0];
    Object * ans;
    ans = tthis->initBool(boolnA);
    SEXP r_ans = R_createRef(ans, "ObjectPtr");
    return(r_ans);
}

SEXP R_Object_initInt(SEXP r_tthis, SEXP r_intgA)
{
    Object *tthis = GET_REF(r_tthis, Object);
    int intgA;
    intgA = INTEGER(r_intgA)[0];
    Object * ans;
    ans = tthis->initInt(intgA);
    SEXP r_ans = R_createRef(ans, "ObjectPtr");
    return(r_ans);
}

SEXP R_Object_initReal(SEXP r_tthis, SEXP r_realA)
{
    Object *tthis = GET_REF(r_tthis, Object);
    double realA;
    realA = REAL(r_realA)[0];
    Object * ans;
    ans = tthis->initReal(realA);
    SEXP r_ans = R_createRef(ans, "ObjectPtr");
    return(r_ans);
}

SEXP R_Object_initString(SEXP r_tthis, SEXP r_stringA)
{
    Object *tthis = GET_REF(r_tthis, Object);
    GooString * stringA;
    stringA = GET_REF(r_stringA, GooString );
    Object * ans;
    ans = tthis->initString(stringA);
    SEXP r_ans = R_createRef(ans, "ObjectPtr");
    return(r_ans);
}

SEXP R_Object_initName(SEXP r_tthis, SEXP r_nameA)
{
    Object *tthis = GET_REF(r_tthis, Object);
    const char * nameA;
    nameA = CHAR(STRING_ELT(r_nameA, 0));
    Object * ans;
    ans = tthis->initName(nameA);
    SEXP r_ans = R_createRef(ans, "ObjectPtr");
    return(r_ans);
}

SEXP R_Object_initNull(SEXP r_tthis)
{
    Object *tthis = GET_REF(r_tthis, Object);
    Object * ans;
    ans = tthis->initNull();
    SEXP r_ans = R_createRef(ans, "ObjectPtr");
    return(r_ans);
}

SEXP R_Object_initArray(SEXP r_tthis, SEXP r_xref)
{
    Object *tthis = GET_REF(r_tthis, Object);
    XRef * xref;
    xref = GET_REF(r_xref, XRef );
    Object * ans;
    ans = tthis->initArray(xref);
    SEXP r_ans = R_createRef(ans, "ObjectPtr");
    return(r_ans);
}

SEXP R_Object_initDict(SEXP r_tthis, SEXP r_dictA)
{
    Object *tthis = GET_REF(r_tthis, Object);
    Dict * dictA;
    dictA = GET_REF(r_dictA, Dict );
    Object * ans;
    ans = tthis->initDict(dictA);
    SEXP r_ans = R_createRef(ans, "ObjectPtr");
    return(r_ans);
}

SEXP R_Object_initStream(SEXP r_tthis, SEXP r_streamA)
{
    Object *tthis = GET_REF(r_tthis, Object);
    Stream * streamA;
    streamA = GET_REF(r_streamA, Stream );
    Object * ans;
    ans = tthis->initStream(streamA);
    SEXP r_ans = R_createRef(ans, "ObjectPtr");
    return(r_ans);
}

SEXP R_Object_initRef(SEXP r_tthis, SEXP r_numA, SEXP r_genA)
{
    Object *tthis = GET_REF(r_tthis, Object);
    int numA;
    numA = INTEGER(r_numA)[0];
    int genA;
    genA = INTEGER(r_genA)[0];
    Object * ans;
    ans = tthis->initRef(numA, genA);
    SEXP r_ans = R_createRef(ans, "ObjectPtr");
    return(r_ans);
}

SEXP R_Object_initCmd(SEXP r_tthis, SEXP r_cmdA)
{
    Object *tthis = GET_REF(r_tthis, Object);
    char * cmdA;
    cmdA = (char *)CHAR(STRING_ELT(r_cmdA, 0));
    Object * ans;
    ans = tthis->initCmd(cmdA);
    SEXP r_ans = R_createRef(ans, "ObjectPtr");
    return(r_ans);
}

SEXP R_Object_initError(SEXP r_tthis)
{
    Object *tthis = GET_REF(r_tthis, Object);
    Object * ans;
    ans = tthis->initError();
    SEXP r_ans = R_createRef(ans, "ObjectPtr");
    return(r_ans);
}

SEXP R_Object_initEOF(SEXP r_tthis)
{
    Object *tthis = GET_REF(r_tthis, Object);
    Object * ans;
    ans = tthis->initEOF();
    SEXP r_ans = R_createRef(ans, "ObjectPtr");
    return(r_ans);
}

SEXP R_Object_initInt64(SEXP r_tthis, SEXP r_int64gA)
{
    Object *tthis = GET_REF(r_tthis, Object);
    long long int64gA;
    int64gA = REAL(r_int64gA)[0];
    Object * ans;
    ans = tthis->initInt64(int64gA);
    SEXP r_ans = R_createRef(ans, "ObjectPtr");
    return(r_ans);
}

SEXP R_Object_copy(SEXP r_tthis, SEXP r_obj)
{
    Object *tthis = GET_REF(r_tthis, Object);
    Object * obj;
    obj = GET_REF(r_obj, Object );
    Object * ans;
    ans = tthis->copy(obj);
    SEXP r_ans = R_createRef(ans, "ObjectPtr");
    return(r_ans);
}

SEXP R_Object_shallowCopy(SEXP r_tthis, SEXP r_obj)
{
    Object *tthis = GET_REF(r_tthis, Object);
    Object * obj;
    obj = GET_REF(r_obj, Object );
    Object * ans;
    ans = tthis->shallowCopy(obj);
    SEXP r_ans = R_createRef(ans, "ObjectPtr");
    return(r_ans);
}

SEXP R_Object_fetch(SEXP r_tthis, SEXP r_xref, SEXP r_obj, SEXP r_recursion)
{
    Object *tthis = GET_REF(r_tthis, Object);
    XRef * xref;
    xref = GET_REF(r_xref, XRef );
    Object * obj;
    obj = GET_REF(r_obj, Object );
    int recursion;
    recursion = INTEGER(r_recursion)[0];
    Object * ans;
    ans = tthis->fetch(xref, obj, recursion);
    SEXP r_ans = R_createRef(ans, "ObjectPtr");
    return(r_ans);
}

SEXP R_Object_free(SEXP r_tthis)
{
    Object *tthis = GET_REF(r_tthis, Object);
    tthis->free();
    return(R_NilValue);
}

SEXP R_Object_isBool(SEXP r_tthis)
{
    Object *tthis = GET_REF(r_tthis, Object);
    GBool ans;
    ans = tthis->isBool();
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

SEXP R_Object_isInt(SEXP r_tthis)
{
    Object *tthis = GET_REF(r_tthis, Object);
    GBool ans;
    ans = tthis->isInt();
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

SEXP R_Object_isReal(SEXP r_tthis)
{
    Object *tthis = GET_REF(r_tthis, Object);
    GBool ans;
    ans = tthis->isReal();
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

SEXP R_Object_isNum(SEXP r_tthis)
{
    Object *tthis = GET_REF(r_tthis, Object);
    GBool ans;
    ans = tthis->isNum();
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

SEXP R_Object_isString(SEXP r_tthis)
{
    Object *tthis = GET_REF(r_tthis, Object);
    GBool ans;
    ans = tthis->isString();
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

SEXP R_Object_isName(SEXP r_tthis, SEXP r_nameA)
{
    Object *tthis = GET_REF(r_tthis, Object);
    const char * nameA;
    nameA = CHAR(STRING_ELT(r_nameA, 0));
    GBool ans;
    ans = tthis->isName(nameA);
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

SEXP R_Object_isNull(SEXP r_tthis)
{
    Object *tthis = GET_REF(r_tthis, Object);
    GBool ans;
    ans = tthis->isNull();
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

SEXP R_Object_isArray(SEXP r_tthis)
{
    Object *tthis = GET_REF(r_tthis, Object);
    GBool ans;
    ans = tthis->isArray();
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

SEXP R_Object_isDict(SEXP r_tthis, SEXP r_dictType)
{
    Object *tthis = GET_REF(r_tthis, Object);
    const char * dictType;
    dictType = CHAR(STRING_ELT(r_dictType, 0));
    GBool ans;
    ans = tthis->isDict(dictType);
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

SEXP R_Object_isStream(SEXP r_tthis, SEXP r_dictType)
{
    Object *tthis = GET_REF(r_tthis, Object);
    char * dictType;
    dictType = (char *)CHAR(STRING_ELT(r_dictType, 0));
    GBool ans;
    ans = tthis->isStream(dictType);
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

SEXP R_Object_isRef(SEXP r_tthis)
{
    Object *tthis = GET_REF(r_tthis, Object);
    GBool ans;
    ans = tthis->isRef();
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

SEXP R_Object_isCmd(SEXP r_tthis, SEXP r_cmdA)
{
    Object *tthis = GET_REF(r_tthis, Object);
    const char * cmdA;
    cmdA = CHAR(STRING_ELT(r_cmdA, 0));
    GBool ans;
    ans = tthis->isCmd(cmdA);
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

SEXP R_Object_isError(SEXP r_tthis)
{
    Object *tthis = GET_REF(r_tthis, Object);
    GBool ans;
    ans = tthis->isError();
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

SEXP R_Object_isEOF(SEXP r_tthis)
{
    Object *tthis = GET_REF(r_tthis, Object);
    GBool ans;
    ans = tthis->isEOF();
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

SEXP R_Object_isNone(SEXP r_tthis)
{
    Object *tthis = GET_REF(r_tthis, Object);
    GBool ans;
    ans = tthis->isNone();
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

SEXP R_Object_isInt64(SEXP r_tthis)
{
    Object *tthis = GET_REF(r_tthis, Object);
    GBool ans;
    ans = tthis->isInt64();
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

SEXP R_Object_isIntOrInt64(SEXP r_tthis)
{
    Object *tthis = GET_REF(r_tthis, Object);
    GBool ans;
    ans = tthis->isIntOrInt64();
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

SEXP R_Object_getBool(SEXP r_tthis)
{
    Object *tthis = GET_REF(r_tthis, Object);
    GBool ans;
    ans = tthis->getBool();
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

SEXP R_Object_getInt(SEXP r_tthis)
{
    Object *tthis = GET_REF(r_tthis, Object);
    int ans;
    ans = tthis->getInt();
    SEXP r_ans = Rf_ScalarInteger(ans);
    return(r_ans);
}

SEXP R_Object_getReal(SEXP r_tthis)
{
    Object *tthis = GET_REF(r_tthis, Object);
    double ans;
    ans = tthis->getReal();
    SEXP r_ans = Rf_ScalarReal(ans);
    return(r_ans);
}

SEXP R_Object_getNum(SEXP r_tthis)
{
    Object *tthis = GET_REF(r_tthis, Object);
    double ans;
    ans = tthis->getNum();
    SEXP r_ans = Rf_ScalarReal(ans);
    return(r_ans);
}

SEXP R_Object_getString(SEXP r_tthis)
{
    Object *tthis = GET_REF(r_tthis, Object);
    GooString * ans;
    ans = tthis->getString();
    SEXP r_ans = GooStringToR(ans);
    return(r_ans);
}

SEXP R_Object_takeString(SEXP r_tthis)
{
    Object *tthis = GET_REF(r_tthis, Object);
    GooString * ans;
    ans = tthis->takeString();
    SEXP r_ans = GooStringToR(ans);
    return(r_ans);
}

SEXP R_Object_getName(SEXP r_tthis)
{
    Object *tthis = GET_REF(r_tthis, Object);
    char * ans;
    ans = tthis->getName();
    SEXP r_ans = Rf_mkString(ans);
    return(r_ans);
}

SEXP R_Object_getArray(SEXP r_tthis)
{
    Object *tthis = GET_REF(r_tthis, Object);
    Array * ans;
    ans = tthis->getArray();
    SEXP r_ans = R_createRef(ans, "ArrayPtr");
    return(r_ans);
}

SEXP R_Object_getDict(SEXP r_tthis)
{
    Object *tthis = GET_REF(r_tthis, Object);
    Dict * ans;
    ans = tthis->getDict();
    SEXP r_ans = R_createRef(ans, "DictPtr");
    return(r_ans);
}

SEXP R_Object_getStream(SEXP r_tthis)
{
    Object *tthis = GET_REF(r_tthis, Object);
    Stream * ans;
    ans = tthis->getStream();
    SEXP r_ans = R_createRef(ans, "StreamPtr");
    return(r_ans);
}

SEXP R_Object_getRefNum(SEXP r_tthis)
{
    Object *tthis = GET_REF(r_tthis, Object);
    int ans;
    ans = tthis->getRefNum();
    SEXP r_ans = Rf_ScalarInteger(ans);
    return(r_ans);
}

SEXP R_Object_getRefGen(SEXP r_tthis)
{
    Object *tthis = GET_REF(r_tthis, Object);
    int ans;
    ans = tthis->getRefGen();
    SEXP r_ans = Rf_ScalarInteger(ans);
    return(r_ans);
}

SEXP R_Object_getCmd(SEXP r_tthis)
{
    Object *tthis = GET_REF(r_tthis, Object);
    char * ans;
    ans = tthis->getCmd();
    SEXP r_ans = Rf_mkString(ans);
    return(r_ans);
}

SEXP R_Object_getInt64(SEXP r_tthis)
{
    Object *tthis = GET_REF(r_tthis, Object);
    long long ans;
    ans = tthis->getInt64();
    SEXP r_ans = Rf_ScalarReal(ans);
    return(r_ans);
}

SEXP R_Object_getIntOrInt64(SEXP r_tthis)
{
    Object *tthis = GET_REF(r_tthis, Object);
    long long ans;
    ans = tthis->getIntOrInt64();
    SEXP r_ans = Rf_ScalarReal(ans);
    return(r_ans);
}

SEXP R_Object_arrayGetLength(SEXP r_tthis)
{
    Object *tthis = GET_REF(r_tthis, Object);
    int ans;
    ans = tthis->arrayGetLength();
    SEXP r_ans = Rf_ScalarInteger(ans);
    return(r_ans);
}

SEXP R_Object_arrayAdd(SEXP r_tthis, SEXP r_elem)
{
    Object *tthis = GET_REF(r_tthis, Object);
    Object * elem;
    elem = GET_REF(r_elem, Object );
    tthis->arrayAdd(elem);
    return(R_NilValue);
}

SEXP R_Object_arrayRemove(SEXP r_tthis, SEXP r_i)
{
    Object *tthis = GET_REF(r_tthis, Object);
    int i;
    i = INTEGER(r_i)[0];
    tthis->arrayRemove(i);
    return(R_NilValue);
}

SEXP R_Object_arrayGet(SEXP r_tthis, SEXP r_i, SEXP r_obj, SEXP r_recursion)
{
    Object *tthis = GET_REF(r_tthis, Object);
    int i;
    i = INTEGER(r_i)[0];
    Object * obj;
    obj = GET_REF(r_obj, Object );
    int recursion;
    recursion = INTEGER(r_recursion)[0];
    Object * ans;
    ans = tthis->arrayGet(i, obj, recursion);
    SEXP r_ans = R_createRef(ans, "ObjectPtr");
    return(r_ans);
}

SEXP R_Object_arrayGetNF(SEXP r_tthis, SEXP r_i, SEXP r_obj)
{
    Object *tthis = GET_REF(r_tthis, Object);
    int i;
    i = INTEGER(r_i)[0];
    Object * obj;
    obj = GET_REF(r_obj, Object );
    Object * ans;
    ans = tthis->arrayGetNF(i, obj);
    SEXP r_ans = R_createRef(ans, "ObjectPtr");
    return(r_ans);
}

SEXP R_Object_dictGetLength(SEXP r_tthis)
{
    Object *tthis = GET_REF(r_tthis, Object);
    int ans;
    ans = tthis->dictGetLength();
    SEXP r_ans = Rf_ScalarInteger(ans);
    return(r_ans);
}

SEXP R_Object_dictAdd(SEXP r_tthis, SEXP r_key, SEXP r_val)
{
    Object *tthis = GET_REF(r_tthis, Object);
    char * key;
    key = (char *)CHAR(STRING_ELT(r_key, 0));
    Object * val;
    val = GET_REF(r_val, Object );
    tthis->dictAdd(key, val);
    return(R_NilValue);
}

SEXP R_Object_dictSet(SEXP r_tthis, SEXP r_key, SEXP r_val)
{
    Object *tthis = GET_REF(r_tthis, Object);
    const char * key;
    key = CHAR(STRING_ELT(r_key, 0));
    Object * val;
    val = GET_REF(r_val, Object );
    tthis->dictSet(key, val);
    return(R_NilValue);
}

SEXP R_Object_dictRemove(SEXP r_tthis, SEXP r_key)
{
    Object *tthis = GET_REF(r_tthis, Object);
    const char * key;
    key = CHAR(STRING_ELT(r_key, 0));
    tthis->dictRemove(key);
    return(R_NilValue);
}

SEXP R_Object_dictIs(SEXP r_tthis, SEXP r_dictType)
{
    Object *tthis = GET_REF(r_tthis, Object);
    const char * dictType;
    dictType = CHAR(STRING_ELT(r_dictType, 0));
    GBool ans;
    ans = tthis->dictIs(dictType);
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

SEXP R_Object_dictLookup(SEXP r_tthis, SEXP r_key, SEXP r_obj, SEXP r_recursion)
{
    Object *tthis = GET_REF(r_tthis, Object);
    const char * key;
    key = CHAR(STRING_ELT(r_key, 0));
    Object * obj;
    obj = GET_REF(r_obj, Object );
    int recursion;
    recursion = INTEGER(r_recursion)[0];
    Object * ans;
    ans = tthis->dictLookup(key, obj, recursion);
    SEXP r_ans = R_createRef(ans, "ObjectPtr");
    return(r_ans);
}

SEXP R_Object_dictLookupNF(SEXP r_tthis, SEXP r_key, SEXP r_obj)
{
    Object *tthis = GET_REF(r_tthis, Object);
    const char * key;
    key = CHAR(STRING_ELT(r_key, 0));
    Object * obj;
    obj = GET_REF(r_obj, Object );
    Object * ans;
    ans = tthis->dictLookupNF(key, obj);
    SEXP r_ans = R_createRef(ans, "ObjectPtr");
    return(r_ans);
}

SEXP R_Object_dictGetKey(SEXP r_tthis, SEXP r_i)
{
    Object *tthis = GET_REF(r_tthis, Object);
    int i;
    i = INTEGER(r_i)[0];
    char * ans;
    ans = tthis->dictGetKey(i);
    SEXP r_ans = Rf_mkString(ans);
    return(r_ans);
}

SEXP R_Object_dictGetVal(SEXP r_tthis, SEXP r_i, SEXP r_obj)
{
    Object *tthis = GET_REF(r_tthis, Object);
    int i;
    i = INTEGER(r_i)[0];
    Object * obj;
    obj = GET_REF(r_obj, Object );
    Object * ans;
    ans = tthis->dictGetVal(i, obj);
    SEXP r_ans = R_createRef(ans, "ObjectPtr");
    return(r_ans);
}

SEXP R_Object_dictGetValNF(SEXP r_tthis, SEXP r_i, SEXP r_obj)
{
    Object *tthis = GET_REF(r_tthis, Object);
    int i;
    i = INTEGER(r_i)[0];
    Object * obj;
    obj = GET_REF(r_obj, Object );
    Object * ans;
    ans = tthis->dictGetValNF(i, obj);
    SEXP r_ans = R_createRef(ans, "ObjectPtr");
    return(r_ans);
}

SEXP R_Object_streamIs(SEXP r_tthis, SEXP r_dictType)
{
    Object *tthis = GET_REF(r_tthis, Object);
    char * dictType;
    dictType = (char *)CHAR(STRING_ELT(r_dictType, 0));
    GBool ans;
    ans = tthis->streamIs(dictType);
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

SEXP R_Object_streamReset(SEXP r_tthis)
{
    Object *tthis = GET_REF(r_tthis, Object);
    tthis->streamReset();
    return(R_NilValue);
}

SEXP R_Object_streamClose(SEXP r_tthis)
{
    Object *tthis = GET_REF(r_tthis, Object);
    tthis->streamClose();
    return(R_NilValue);
}

SEXP R_Object_streamGetChar(SEXP r_tthis)
{
    Object *tthis = GET_REF(r_tthis, Object);
    int ans;
    ans = tthis->streamGetChar();
    SEXP r_ans = Rf_ScalarInteger(ans);
    return(r_ans);
}

SEXP R_Object_streamGetChars(SEXP r_tthis, SEXP r_nChars, SEXP r_buffer)
{
    Object *tthis = GET_REF(r_tthis, Object);
    int nChars;
    nChars = INTEGER(r_nChars)[0];
    Guchar * buffer;
    buffer = (Guchar *) RAW(r_buffer);
    int ans;
    ans = tthis->streamGetChars(nChars, buffer);
    SEXP r_ans = Rf_ScalarInteger(ans);
    return(r_ans);
}

SEXP R_Object_streamLookChar(SEXP r_tthis)
{
    Object *tthis = GET_REF(r_tthis, Object);
    int ans;
    ans = tthis->streamLookChar();
    SEXP r_ans = Rf_ScalarInteger(ans);
    return(r_ans);
}

SEXP R_Object_streamGetLine(SEXP r_tthis, SEXP r_buf, SEXP r_size)
{
    Object *tthis = GET_REF(r_tthis, Object);
    char * buf;
    buf = (char *)CHAR(STRING_ELT(r_buf, 0));
    int size;
    size = INTEGER(r_size)[0];
    char * ans;
    ans = tthis->streamGetLine(buf, size);
    SEXP r_ans = Rf_mkString(ans);
    return(r_ans);
}

SEXP R_Object_streamGetPos(SEXP r_tthis)
{
    Object *tthis = GET_REF(r_tthis, Object);
    Goffset ans;
    ans = tthis->streamGetPos();
    SEXP r_ans = Rf_ScalarReal(ans);
    return(r_ans);
}

SEXP R_Object_streamSetPos(SEXP r_tthis, SEXP r_pos, SEXP r_dir)
{
    Object *tthis = GET_REF(r_tthis, Object);
    Goffset pos;
    pos = REAL(r_pos)[0];
    int dir;
    dir = INTEGER(r_dir)[0];
    tthis->streamSetPos(pos, dir);
    return(R_NilValue);
}

SEXP R_Object_streamGetDict(SEXP r_tthis)
{
    Object *tthis = GET_REF(r_tthis, Object);
    Dict * ans;
    ans = tthis->streamGetDict();
    SEXP r_ans = R_createRef(ans, "DictPtr");
    return(r_ans);
}

SEXP R_Object_getTypeName(SEXP r_tthis)
{
    Object *tthis = GET_REF(r_tthis, Object);
    const char * ans;
    ans = tthis->getTypeName();
    SEXP r_ans = Rf_mkString(ans);
    return(r_ans);
}

SEXP R_Object_print(SEXP r_tthis, SEXP r_f)
{
    Object *tthis = GET_REF(r_tthis, Object);
    FILE * f;
    f = GET_REF(r_f, FILE );
    tthis->print(f);
    return(R_NilValue);
}

SEXP R_Object_memCheck(SEXP r_f)
{
    FILE * f;
    f = GET_REF(r_f, FILE );
    Object::memCheck(f);
    return(R_NilValue);
}
