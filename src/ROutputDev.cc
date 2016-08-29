#include "Rpoppler.h"
#include "ROutputDev.h"


SEXP 
//ROutputDev::lookupRMethod(const char *name)
RFunctionsNativeMethods::lookupRMethod(const char *name)
{
    SEXP names = GET_NAMES(r_method_funcs);
    int n = Rf_length(r_method_funcs);
    for(int i = 0; i < n; i++) {
        if(strcmp(CHAR(STRING_ELT(names, i)), name) == 0) {
#ifdef R_DEBUG_DEVICE
            Rprintf("Found R function for method %s in %p\n", name, this);
            Rf_PrintValue(VECTOR_ELT(r_method_funcs, i));
#endif
            return(VECTOR_ELT(r_method_funcs, i));
        }
    }
    return(R_NilValue);
}


#if 1
extern "C"
SEXP
R_ROutputDev_setFunctions(SEXP r_dev, SEXP r_funs, SEXP r_preserve)
{
    ROutputDev *dev = GET_REF(r_dev, ROutputDev);
    return(dev->setFunctions(r_funs, LOGICAL(r_preserve)[0]));
}

extern "C"
SEXP
R_ROutputDev_getFunctions(SEXP r_dev)
{
    ROutputDev *dev = GET_REF(r_dev, ROutputDev);
    return(dev->getFunctions());
}

#else

extern "C"
SEXP
R_RFunctionsNativeMethods_setFunctions(SEXP r_dev, SEXP r_funs, SEXP r_preserve)
{
    RFunctionsNativeMethods *dev = GET_REF(r_dev, RFunctionsNativeMethods);
    return(dev->setFunctions(r_funs, LOGICAL(r_preserve)[0]));
}

extern "C"
SEXP
R_RFunctionsNativeMethods_getFunctions(SEXP r_dev)
{
    RFunctionsNativeMethods *dev = GET_REF(r_dev, RFunctionsNativeMethods);
    Rf_PrintValue(dev->getFunctions());
    return(dev->getFunctions());
}
#endif



#include "ROutputDev_auto.cpp_code"
