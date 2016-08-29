#include <poppler/PDFDoc.h>
#include <poppler/OutputDev.h>
#include <Rdefines.h>


class RFunctionsNativeMethods {

public:
    SEXP getFunctions() { return(r_method_funcs); }

    SEXP setFunctions(SEXP funcs, bool preserve) {
	Rprintf("setting method functions\n");
	SEXP old = r_method_funcs;
	r_method_funcs = funcs;
	if(preserve) {
	   R_PreserveObject(r_method_funcs);
	   needsRelease = true;
	}
	return(old);
    }

    ~RFunctionsNativeMethods() {
//	Rprintf("~RFunctionsNativeMethods. Releasing the r_methods_funcs\n");
	if(needsRelease)
	    R_ReleaseObject(r_method_funcs);
    }


protected:
    bool needsRelease;
    SEXP r_method_funcs; // use a hash table.

    SEXP lookupRMethod(const char *name);
    SEXP invokeMethod(SEXP e) {
	return(Rf_eval(e, R_GlobalEnv));
    }
};



class ROutputDev : public OutputDev, public RFunctionsNativeMethods {

public:

#include "ROutputDev_auto.h"

    ROutputDev(SEXP funs) {
	setFunctions(funs, true) ;
    }


#ifdef R_DEBUG_DEVICE
    ~ROutputDev() {
        Rprintf("deleting ROutputDev\n");
    }
#endif

#if 0
    ~ROutputDev() {
	if(needsRelease)
	    R_ReleaseObject(r_method_funcs);
    }



protected:
    bool needsRelease;
    SEXP r_method_funcs; // use a hash table.

    SEXP lookupRMethod(const char *name);
    SEXP invokeMethod(SEXP e) {
	return(Rf_eval(e, R_GlobalEnv));
    }



public:
    SEXP getFunctions() { return(r_method_funcs); }

    SEXP setFunctions(SEXP funcs, bool preserve) {
	SEXP old = r_method_funcs;
	r_method_funcs = funcs;
	if(preserve) {
	   R_PreserveObject(r_method_funcs);
	   needsRelease = true;
	}
	return(old);
    }
#endif
};
