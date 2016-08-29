#include <poppler/PDFDoc.h>
#include <poppler/GfxState.h>
#include <Rdefines.h>

#define GET_REF(obj, type) \
  (type *) R_ExternalPtrAddr(GET_SLOT(obj, Rf_install("ref")))

SEXP createRef(void *ptr, const char * const classname, R_CFinalizer_t fin);

// #define R_createRef(a, b)  createRef((a), (b), NULL)
#define R_createRef(a, b, c)  createRef((a), (b), (c))

void R_freeAPI(SEXP obj);

SEXP GooStringToR(GooString *ans);
GooString * GooStringFromR(SEXP rstr);


SEXP R_makeEnumValue(int val, const char *elName, const char *className);

#include "R_auto_enums.h"
