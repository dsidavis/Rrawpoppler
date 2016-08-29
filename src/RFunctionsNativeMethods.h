
#include <Rinternals.h>

class RFunctionsNativeMethods {

public:
    SEXP getFunctions() { return(r_method_funcs); }

    SEXP setFunctions(SEXP funcs, bool preserve) {
//	Rprintf("setting method functions %p\n", this);
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
