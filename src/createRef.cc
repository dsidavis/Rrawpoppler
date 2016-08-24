#include "Rpoppler.h"

SEXP
createRef(void *ptr, const char * const classname, R_CFinalizer_t fin)
{
  SEXP robj, klass, ref;

 
  PROTECT(klass = MAKE_CLASS(classname));
  PROTECT(robj = NEW(klass));
  SET_SLOT(robj, Rf_install("ref"), ref = R_MakeExternalPtr(ptr, Rf_install(classname), R_NilValue));

  // Set finalizer to garbage collect when we let go/release this object.
  if(fin)
     R_RegisterCFinalizer(ref, fin);
  UNPROTECT(2);  
  return(robj);
}

void
R_freeAPI(SEXP obj)
{
  PDFDoc * api = (PDFDoc *)  R_ExternalPtrAddr(obj)  ;
  if(api) {
#ifdef FINALIZER_DEBUG
    Rprintf("R_freeAPI\n");
#endif
    delete api;
  }
}
