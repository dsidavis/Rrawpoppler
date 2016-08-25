#include <poppler/PDFDoc.h>
#include <poppler/GfxState.h>
#include <Rdefines.h>

#define GET_REF(obj, type) \
  (type *) R_ExternalPtrAddr(GET_SLOT(obj, Rf_install("ref")))

SEXP createRef(void *ptr, const char * const classname, R_CFinalizer_t fin);

#define R_createRef(a, b)  createRef((a), (b), NULL)

void R_freeAPI(SEXP obj);

SEXP GooStringToR(GooString *ans);
GooString * GooStringFromR(SEXP rstr);
