#define R_NO_REMAP 1

#include "Rpoppler.h"

extern "C"
SEXP R_Dict_copy(SEXP r_tthis, SEXP r_xrefA)
{
    Dict *tthis = GET_REF(r_tthis, Dict);
    XRef * xrefA;
    xrefA = GET_REF(r_xrefA, XRef );
    Dict * ans;
    ans = tthis->copy(xrefA);
    SEXP r_ans = R_createRef(ans, "DictPtr");
    return(r_ans);
}

extern "C"
SEXP R_Dict_incRef(SEXP r_tthis)
{
    Dict *tthis = GET_REF(r_tthis, Dict);
    int ans;
    ans = tthis->incRef();
    SEXP r_ans = Rf_ScalarInteger(ans);
    return(r_ans);
}

extern "C"
SEXP R_Dict_decRef(SEXP r_tthis)
{
    Dict *tthis = GET_REF(r_tthis, Dict);
    int ans;
    ans = tthis->decRef();
    SEXP r_ans = Rf_ScalarInteger(ans);
    return(r_ans);
}

extern "C"
SEXP R_Dict_getLength(SEXP r_tthis)
{
    Dict *tthis = GET_REF(r_tthis, Dict);
    int ans;
    ans = tthis->getLength();
    SEXP r_ans = Rf_ScalarInteger(ans);
    return(r_ans);
}

extern "C"
SEXP R_Dict_add(SEXP r_tthis, SEXP r_key, SEXP r_val)
{
    Dict *tthis = GET_REF(r_tthis, Dict);
    char * key;
    key = (char *)CHAR(STRING_ELT(r_key, 0));
    Object * val;
    val = GET_REF(r_val, Object );
    tthis->add(key, val);
    return(R_NilValue);
}

extern "C"
SEXP R_Dict_set(SEXP r_tthis, SEXP r_key, SEXP r_val)
{
    Dict *tthis = GET_REF(r_tthis, Dict);
    const char * key;
    key = CHAR(STRING_ELT(r_key, 0));
    Object * val;
    val = GET_REF(r_val, Object );
    tthis->set(key, val);
    return(R_NilValue);
}

extern "C"
SEXP R_Dict_remove(SEXP r_tthis, SEXP r_key)
{
    Dict *tthis = GET_REF(r_tthis, Dict);
    const char * key;
    key = CHAR(STRING_ELT(r_key, 0));
    tthis->remove(key);
    return(R_NilValue);
}

extern "C"
SEXP R_Dict_is(SEXP r_tthis, SEXP r_type)
{
    Dict *tthis = GET_REF(r_tthis, Dict);
    const char * type;
    type = CHAR(STRING_ELT(r_type, 0));
    GBool ans;
    ans = tthis->is(type);
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

extern "C"
SEXP R_Dict_lookup(SEXP r_tthis, SEXP r_key, SEXP r_obj, SEXP r_recursion)
{
    Dict *tthis = GET_REF(r_tthis, Dict);
    const char * key;
    key = CHAR(STRING_ELT(r_key, 0));
    Object * obj;
    obj = GET_REF(r_obj, Object );
    int recursion;
    recursion = INTEGER(r_recursion)[0];
    Object * ans;
    ans = tthis->lookup(key, obj, recursion);
    SEXP r_ans = R_createRef(ans, "ObjectPtr");
    return(r_ans);
}

extern "C"
SEXP R_Dict_lookupNF(SEXP r_tthis, SEXP r_key, SEXP r_obj)
{
    Dict *tthis = GET_REF(r_tthis, Dict);
    const char * key;
    key = CHAR(STRING_ELT(r_key, 0));
    Object * obj;
    obj = GET_REF(r_obj, Object );
    Object * ans;
    ans = tthis->lookupNF(key, obj);
    SEXP r_ans = R_createRef(ans, "ObjectPtr");
    return(r_ans);
}

extern "C"
SEXP R_Dict_lookupInt(SEXP r_tthis, SEXP r_key, SEXP r_alt_key, SEXP r_value)
{
    Dict *tthis = GET_REF(r_tthis, Dict);
    const char * key;
    key = CHAR(STRING_ELT(r_key, 0));
    const char * alt_key;
    alt_key = CHAR(STRING_ELT(r_alt_key, 0));
    int * value;
    value = INTEGER(r_value);
    GBool ans;
    ans = tthis->lookupInt(key, alt_key, value);
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

extern "C"
SEXP R_Dict_getKey(SEXP r_tthis, SEXP r_i)
{
    Dict *tthis = GET_REF(r_tthis, Dict);
    int i;
    i = INTEGER(r_i)[0];
    char * ans;
    ans = tthis->getKey(i);
    SEXP r_ans = Rf_mkString(ans);
    return(r_ans);
}

extern "C"
SEXP R_Dict_getVal(SEXP r_tthis, SEXP r_i, SEXP r_obj)
{
    Dict *tthis = GET_REF(r_tthis, Dict);
    int i;
    i = INTEGER(r_i)[0];
    Object * obj;
    obj = GET_REF(r_obj, Object );
    Object * ans;
    ans = tthis->getVal(i, obj);
    SEXP r_ans = R_createRef(ans, "ObjectPtr");
    return(r_ans);
}

extern "C"
SEXP R_Dict_getValNF(SEXP r_tthis, SEXP r_i, SEXP r_obj)
{
    Dict *tthis = GET_REF(r_tthis, Dict);
    int i;
    i = INTEGER(r_i)[0];
    Object * obj;
    obj = GET_REF(r_obj, Object );
    Object * ans;
    ans = tthis->getValNF(i, obj);
    SEXP r_ans = R_createRef(ans, "ObjectPtr");
    return(r_ans);
}

extern "C"
SEXP R_Dict_setXRef(SEXP r_tthis, SEXP r_xrefA)
{
    Dict *tthis = GET_REF(r_tthis, Dict);
    XRef * xrefA;
    xrefA = GET_REF(r_xrefA, XRef );
    tthis->setXRef(xrefA);
    return(R_NilValue);
}

extern "C"
SEXP R_Dict_getXRef(SEXP r_tthis)
{
    Dict *tthis = GET_REF(r_tthis, Dict);
    XRef * ans;
    ans = tthis->getXRef();
    SEXP r_ans = R_createRef(ans, "XRefPtr");
    return(r_ans);
}

extern "C"
SEXP R_Dict_hasKey(SEXP r_tthis, SEXP r_key)
{
    Dict *tthis = GET_REF(r_tthis, Dict);
    const char * key;
    key = CHAR(STRING_ELT(r_key, 0));
    GBool ans;
    ans = tthis->hasKey(key);
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}
