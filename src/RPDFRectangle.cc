#define R_NO_REMAP 1

#include "Rpoppler.h"

SEXP R_PDFRectangle_isValid(SEXP r_tthis)
{
    PDFRectangle *tthis = GET_REF(r_tthis, PDFRectangle);
    GBool ans;
    ans = tthis->isValid();
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

SEXP R_PDFRectangle_contains(SEXP r_tthis, SEXP r_x, SEXP r_y)
{
    PDFRectangle *tthis = GET_REF(r_tthis, PDFRectangle);
    double x;
    x = REAL(r_x)[0];
    double y;
    y = REAL(r_y)[0];
    GBool ans;
    ans = tthis->contains(x, y);
    SEXP r_ans = Rf_ScalarLogical(ans);
    return(r_ans);
}

SEXP R_PDFRectangle_clipTo(SEXP r_tthis, SEXP r_rect)
{
    PDFRectangle *tthis = GET_REF(r_tthis, PDFRectangle);
    PDFRectangle * rect;
    rect = GET_REF(r_rect, PDFRectangle );
    tthis->clipTo(rect);
    return(R_NilValue);
}
