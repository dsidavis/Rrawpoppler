
#include <PDFDoc.h>

extern "C"
SEXP
R_PDFDoc_constructor(SEXP r_file, SEXP r_password)
{
    GooString *str = new GooString(CHAR(STRING_ELT(r_file, 0)));
    PDFDoc *doc = new PDFDoc(str);

    
}
