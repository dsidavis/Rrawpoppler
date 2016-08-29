#include "Rpoppler.h"

SEXP
R_makeEnumValue(int val, const char *elName, const char *className)
{
    SEXP ans, klass;
    #if defined(USE_S4_ENUMS)
    
    SEXP tmp;
    PROTECT(klass = MAKE_CLASS(className));
    PROTECT(ans = NEW(klass));
    PROTECT(tmp = ScalarInteger(val));
    SET_NAMES(tmp, mkString(elName));
    ans = SET_SLOT(ans, Rf_install(".Data"), tmp);
    UNPROTECT(3);
    
    #else
    
    PROTECT(ans = ScalarInteger(val));
    SET_NAMES(ans, mkString(elName));
    PROTECT(klass = NEW_CHARACTER(2));
    SET_STRING_ELT(klass, 0, mkChar(className));
    SET_STRING_ELT(klass, 1, mkChar("EnumValue"));
    SET_CLASS(ans, klass);
    UNPROTECT(2);
    
    #endif
    
    return(ans);
}
