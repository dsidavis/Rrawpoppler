setMethod( 'copy' , c( 'Dict' ),       
function( this, xrefA )
{
    .Call('R_Dict_copy', as(this, 'Dict'), as(xrefA, 'XRefPtr'))
} )


incRef <-
function( this )
{
    .Call('R_Dict_incRef', as(this, 'Dict'))
}

decRef <-
function( this )
{
    .Call('R_Dict_decRef', as(this, 'Dict'))
}

getLength <-
function( this )
{
    .Call('R_Dict_getLength', as(this, 'Dict'))
}

setMethod( 'add' , c( 'Dict' ),       
function( this, key, val )
{
    .Call('R_Dict_add', as(this, 'Dict'), as(key, 'character'), as(val, 'ObjectPtr'))
} )


set <-
function( this, key, val )
{
    .Call('R_Dict_set', as(this, 'Dict'), as(key, 'character'), as(val, 'ObjectPtr'))
}

remove <-
function( this, key )
{
    .Call('R_Dict_remove', as(this, 'Dict'), as(key, 'character'))
}

is <-
function( this, type )
{
    .Call('R_Dict_is', as(this, 'Dict'), as(type, 'character'))
}

lookup <-
function( this, key, obj, recursion )
{
    .Call('R_Dict_lookup', as(this, 'Dict'), as(key, 'character'), as(obj, 'ObjectPtr'), as(recursion, 'integer'))
}

lookupNF <-
function( this, key, obj )
{
    .Call('R_Dict_lookupNF', as(this, 'Dict'), as(key, 'character'), as(obj, 'ObjectPtr'))
}

lookupInt <-
function( this, key, alt_key, value )
{
    .Call('R_Dict_lookupInt', as(this, 'Dict'), as(key, 'character'), as(alt_key, 'character'), as(value, 'integer'))
}

getKey <-
function( this, i )
{
    .Call('R_Dict_getKey', as(this, 'Dict'), as(i, 'integer'))
}

getVal <-
function( this, i, obj )
{
    .Call('R_Dict_getVal', as(this, 'Dict'), as(i, 'integer'), as(obj, 'ObjectPtr'))
}

getValNF <-
function( this, i, obj )
{
    .Call('R_Dict_getValNF', as(this, 'Dict'), as(i, 'integer'), as(obj, 'ObjectPtr'))
}

setXRef <-
function( this, xrefA )
{
    .Call('R_Dict_setXRef', as(this, 'Dict'), as(xrefA, 'XRefPtr'))
}

setMethod( 'getXRef' , c( 'Dict' ),       
function( this )
{
    .Call('R_Dict_getXRef', as(this, 'Dict'))
} )


hasKey <-
function( this, key )
{
    .Call('R_Dict_hasKey', as(this, 'Dict'), as(key, 'character'))
}
