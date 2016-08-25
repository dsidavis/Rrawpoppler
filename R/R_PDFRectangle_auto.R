isValid <-
function( this )
{
    .Call('R_PDFRectangle_isValid', as(this, 'PDFRectangle'))
}

contains <-
function( this, x, y )
{
    .Call('R_PDFRectangle_contains', as(this, 'PDFRectangle'), as(x, 'numeric'), as(y, 'numeric'))
}

clipTo <-
function( this, rect )
{
    .Call('R_PDFRectangle_clipTo', as(this, 'PDFRectangle'), as(rect, 'PDFRectanglePtr'))
}
