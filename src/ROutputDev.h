#include <poppler/PDFDoc.h>
#include <poppler/OutputDev.h>
#include <Rdefines.h>

class ROutputDev : public OutputDev {

public:

#include "ROutputDev_auto.h"

    ROutputDev(SEXP funs) : r_method_funcs(funs) {}

#if 0

    GBool upsideDown();
    GBool useDrawChar();
    GBool interpretType3Chars();



    void startPage(int pageNum, GfxState *state, XRef *xref);
    void endPage();
    void updateFillColor(GfxState * state);
#endif

protected:
    SEXP r_method_funcs; // use a hash table.

    SEXP lookupRMethod(const char *name);
    SEXP invokeMethod(SEXP e) {
	return(Rf_eval(e, R_GlobalEnv));
    }
};
