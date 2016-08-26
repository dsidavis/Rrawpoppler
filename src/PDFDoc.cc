#include <poppler/GlobalParams.h>
#include "Rpoppler.h"
#include "ROutputDev.h"


extern "C"
SEXP
R_Object_new()
{
    return(createRef(new Object(), "Object", NULL));     // XXX finalizer    
}


extern "C"
SEXP
R_GlobalParams_init(SEXP r_args)
{
  globalParams = new GlobalParams();
  return(R_NilValue);
}


extern "C"
SEXP
R_PDFDoc_constructor(SEXP r_file, SEXP r_password)
{
    GooString *str = new GooString(CHAR(STRING_ELT(r_file, 0)));
    PDFDoc *doc = new PDFDoc(str);

    return(createRef(doc, "PDFDoc", NULL));     // XXX finalizer
}


#if 0
extern "C"
SEXP
R_PDFDoc_getNumPages(SEXP r_pdf)
{
      PDFDoc *pdf = GET_REF(r_pdf, PDFDoc);
      return(ScalarInteger(pdf->getNumPages()));
}


extern "C"
SEXP
R_PDFDoc_readMetadata(SEXP r_pdf)
{

      PDFDoc *pdf = GET_REF(r_pdf, PDFDoc);
      GooString *ans;
      ans = pdf->readMetadata();
      return(GooStringToR(ans));
}
#endif



SEXP
GooStringToR(GooString *ans)
{
    if(!ans) 
        return(ScalarString(NA_STRING));
    char *str = ans->getCString();
    return(ScalarString(str ? mkChar(str) : NA_STRING));
}


GooString *
GooStringFromR(SEXP rstr)
{
    GooString *ans = NULL;
    if(TYPEOF(rstr) == STRSXP) {
        ans = new GooString(CHAR(STRING_ELT(rstr, 0)));
    } else
        ans = GET_REF(rstr, GooString);

    if(!ans) {
        PROBLEM  "C-level NULL value for a GooString"
            ERROR;
    }

    return(ans);
}


extern "C"
SEXP
R_ROutputDev_new(SEXP r_funcs)
{
    R_PreserveObject(r_funcs);
    ROutputDev *dev = new ROutputDev(r_funcs);

    dev->upsideDown();

    return(createRef(dev, "ROutputDev", NULL));     // finalizer
}


extern "C"
SEXP
R_PDFDoc_displayPage(SEXP r_pdf, SEXP r_dev, SEXP r_page, SEXP r_dpi, SEXP r_rotate, SEXP r_useMediaBox, SEXP r_crop, SEXP r_printing)
{
    PDFDoc *pdf = GET_REF(r_pdf, PDFDoc);    
    OutputDev *dev = GET_REF(r_dev, ROutputDev);    

    if(Rf_length(r_page) > 1) 
        pdf->displayPages(dev, INTEGER(r_page)[0], INTEGER(r_page)[1], REAL(r_dpi)[0], REAL(r_dpi)[1], 
                          INTEGER(r_rotate)[0], LOGICAL(r_useMediaBox)[0], LOGICAL(r_crop)[0], LOGICAL(r_printing)[0]);
    else
        pdf->displayPage(dev, INTEGER(r_page)[0], REAL(r_dpi)[0], REAL(r_dpi)[1], 
                         INTEGER(r_rotate)[0], LOGICAL(r_useMediaBox)[0], LOGICAL(r_crop)[0], LOGICAL(r_printing)[0]);

    return(R_NilValue);
}


