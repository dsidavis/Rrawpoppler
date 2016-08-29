zeroUnion <-
function( this )
{
    .Call('R_Object_zeroUnion', as(this, 'Object'))
}

initBool <-
function( this, boolnA )
{
    .Call('R_Object_initBool', as(this, 'Object'), as(boolnA, 'GBool'))
}

initInt <-
function( this, intgA )
{
    .Call('R_Object_initInt', as(this, 'Object'), as(intgA, 'integer'))
}

initReal <-
function( this, realA )
{
    .Call('R_Object_initReal', as(this, 'Object'), as(realA, 'numeric'))
}

initString <-
function( this, stringA )
{
    .Call('R_Object_initString', as(this, 'Object'), as(stringA, 'GooStringOrCharacter'))
}

initName <-
function( this, nameA )
{
    .Call('R_Object_initName', as(this, 'Object'), as(nameA, 'character'))
}

initNull <-
function( this )
{
    .Call('R_Object_initNull', as(this, 'Object'))
}

initArray <-
function( this, xref )
{
    .Call('R_Object_initArray', as(this, 'Object'), as(xref, 'XRefPtr'))
}

setMethod( 'initDict' , c( 'Object' ),       
function( this, xref )
{
    .Call('R_Object_initDictXRef_Ptr', as(this, 'Object'), as(xref, 'XRefPtr'))
} )


initDict <-
function( this, dictA )
{
    .Call('R_Object_initDictDict_Ptr', as(this, 'Object'), as(dictA, 'DictPtr'))
}

initStream <-
function( this, streamA )
{
    .Call('R_Object_initStream', as(this, 'Object'), as(streamA, 'StreamPtr'))
}

initRef <-
function( this, numA, genA )
{
    .Call('R_Object_initRef', as(this, 'Object'), as(numA, 'integer'), as(genA, 'integer'))
}

initCmd <-
function( this, cmdA )
{
    .Call('R_Object_initCmd', as(this, 'Object'), as(cmdA, 'character'))
}

initError <-
function( this )
{
    .Call('R_Object_initError', as(this, 'Object'))
}

initEOF <-
function( this )
{
    .Call('R_Object_initEOF', as(this, 'Object'))
}

initInt64 <-
function( this, int64gA )
{
    .Call('R_Object_initInt64', as(this, 'Object'), as(int64gA, 'numeric'))
}

setMethod( 'copy' , c( 'Object' ),       
function( this, obj )
{
    .Call('R_Object_copy', as(this, 'Object'), as(obj, 'ObjectPtr'))
} )


shallowCopy <-
function( this, obj )
{
    .Call('R_Object_shallowCopy', as(this, 'Object'), as(obj, 'ObjectPtr'))
}

setMethod( 'fetch' , c( 'Object' ),       
function( this, xref, obj, recursion = 0 )
{
    .Call('R_Object_fetch', as(this, 'Object'), as(xref, 'XRefPtr'), as(obj, 'ObjectPtr'), as(recursion, 'integer'))
} )


free <-
function( this )
{
    .Call('R_Object_free', as(this, 'Object'))
}

isBool <-
function( this )
{
    .Call('R_Object_isBool', as(this, 'Object'))
}

isInt <-
function( this )
{
    .Call('R_Object_isInt', as(this, 'Object'))
}

isReal <-
function( this )
{
    .Call('R_Object_isReal', as(this, 'Object'))
}

isNum <-
function( this )
{
    .Call('R_Object_isNum', as(this, 'Object'))
}

isString <-
function( this )
{
    .Call('R_Object_isString', as(this, 'Object'))
}

setMethod( 'isName' , c( 'Object' ),       
function( this )
{
    .Call('R_Object_isName', as(this, 'Object'))
} )


isNull <-
function( this )
{
    .Call('R_Object_isNull', as(this, 'Object'))
}

isArray <-
function( this )
{
    .Call('R_Object_isArray', as(this, 'Object'))
}

setMethod( 'isDict' , c( 'Object' ),       
function( this )
{
    .Call('R_Object_isDict', as(this, 'Object'))
} )


setMethod( 'isStream' , c( 'Object' ),       
function( this )
{
    .Call('R_Object_isStream', as(this, 'Object'))
} )


isRef <-
function( this )
{
    .Call('R_Object_isRef', as(this, 'Object'))
}

setMethod( 'isCmd' , c( 'Object' ),       
function( this )
{
    .Call('R_Object_isCmd', as(this, 'Object'))
} )


isError <-
function( this )
{
    .Call('R_Object_isError', as(this, 'Object'))
}

isEOF <-
function( this )
{
    .Call('R_Object_isEOF', as(this, 'Object'))
}

isNone <-
function( this )
{
    .Call('R_Object_isNone', as(this, 'Object'))
}

isInt64 <-
function( this )
{
    .Call('R_Object_isInt64', as(this, 'Object'))
}

isIntOrInt64 <-
function( this )
{
    .Call('R_Object_isIntOrInt64', as(this, 'Object'))
}

isName <-
function( this, nameA )
{
    .Call('R_Object_isNameconst_char_Ptr', as(this, 'Object'), as(nameA, 'character'))
}

isDict <-
function( this, dictType )
{
    .Call('R_Object_isDictconst_char_Ptr', as(this, 'Object'), as(dictType, 'character'))
}

isStream <-
function( this, dictType )
{
    .Call('R_Object_isStreamchar_Ptr', as(this, 'Object'), as(dictType, 'character'))
}

isCmd <-
function( this, cmdA )
{
    .Call('R_Object_isCmdconst_char_Ptr', as(this, 'Object'), as(cmdA, 'character'))
}

getBool <-
function( this )
{
    .Call('R_Object_getBool', as(this, 'Object'))
}

getInt <-
function( this )
{
    .Call('R_Object_getInt', as(this, 'Object'))
}

getReal <-
function( this )
{
    .Call('R_Object_getReal', as(this, 'Object'))
}

setMethod( 'getNum' , c( 'Object' ),       
function( this )
{
    .Call('R_Object_getNum', as(this, 'Object'))
} )


getString <-
function( this )
{
    .Call('R_Object_getString', as(this, 'Object'))
}

takeString <-
function( this )
{
    .Call('R_Object_takeString', as(this, 'Object'))
}

getName <-
function( this )
{
    .Call('R_Object_getName', as(this, 'Object'))
}

getArray <-
function( this )
{
    .Call('R_Object_getArray', as(this, 'Object'))
}

getDict <-
function( this )
{
    .Call('R_Object_getDict', as(this, 'Object'))
}

getStream <-
function( this )
{
    .Call('R_Object_getStream', as(this, 'Object'))
}

getRefNum <-
function( this )
{
    .Call('R_Object_getRefNum', as(this, 'Object'))
}

getRefGen <-
function( this )
{
    .Call('R_Object_getRefGen', as(this, 'Object'))
}

getCmd <-
function( this )
{
    .Call('R_Object_getCmd', as(this, 'Object'))
}

getInt64 <-
function( this )
{
    .Call('R_Object_getInt64', as(this, 'Object'))
}

getIntOrInt64 <-
function( this )
{
    .Call('R_Object_getIntOrInt64', as(this, 'Object'))
}

arrayGetLength <-
function( this )
{
    .Call('R_Object_arrayGetLength', as(this, 'Object'))
}

arrayAdd <-
function( this, elem )
{
    .Call('R_Object_arrayAdd', as(this, 'Object'), as(elem, 'ObjectPtr'))
}

arrayRemove <-
function( this, i )
{
    .Call('R_Object_arrayRemove', as(this, 'Object'), as(i, 'integer'))
}

arrayGet <-
function( this, i, obj, recursion )
{
    .Call('R_Object_arrayGet', as(this, 'Object'), as(i, 'integer'), as(obj, 'ObjectPtr'), as(recursion, 'integer'))
}

arrayGetNF <-
function( this, i, obj )
{
    .Call('R_Object_arrayGetNF', as(this, 'Object'), as(i, 'integer'), as(obj, 'ObjectPtr'))
}

dictGetLength <-
function( this )
{
    .Call('R_Object_dictGetLength', as(this, 'Object'))
}

dictAdd <-
function( this, key, val )
{
    .Call('R_Object_dictAdd', as(this, 'Object'), as(key, 'character'), as(val, 'ObjectPtr'))
}

dictSet <-
function( this, key, val )
{
    .Call('R_Object_dictSet', as(this, 'Object'), as(key, 'character'), as(val, 'ObjectPtr'))
}

dictRemove <-
function( this, key )
{
    .Call('R_Object_dictRemove', as(this, 'Object'), as(key, 'character'))
}

dictIs <-
function( this, dictType )
{
    .Call('R_Object_dictIs', as(this, 'Object'), as(dictType, 'character'))
}

dictLookup <-
function( this, key, obj, recursion = 0 )
{
    .Call('R_Object_dictLookup', as(this, 'Object'), as(key, 'character'), as(obj, 'ObjectPtr'), as(recursion, 'integer'))
}

dictLookupNF <-
function( this, key, obj )
{
    .Call('R_Object_dictLookupNF', as(this, 'Object'), as(key, 'character'), as(obj, 'ObjectPtr'))
}

dictGetKey <-
function( this, i )
{
    .Call('R_Object_dictGetKey', as(this, 'Object'), as(i, 'integer'))
}

dictGetVal <-
function( this, i, obj )
{
    .Call('R_Object_dictGetVal', as(this, 'Object'), as(i, 'integer'), as(obj, 'ObjectPtr'))
}

dictGetValNF <-
function( this, i, obj )
{
    .Call('R_Object_dictGetValNF', as(this, 'Object'), as(i, 'integer'), as(obj, 'ObjectPtr'))
}

streamIs <-
function( this, dictType )
{
    .Call('R_Object_streamIs', as(this, 'Object'), as(dictType, 'character'))
}

streamReset <-
function( this )
{
    .Call('R_Object_streamReset', as(this, 'Object'))
}

streamClose <-
function( this )
{
    .Call('R_Object_streamClose', as(this, 'Object'))
}

streamGetChar <-
function( this )
{
    .Call('R_Object_streamGetChar', as(this, 'Object'))
}

streamGetChars <-
function( this, nChars, buffer )
{
    .Call('R_Object_streamGetChars', as(this, 'Object'), as(nChars, 'integer'), as(buffer, 'GucharPtr'))
}

streamLookChar <-
function( this )
{
    .Call('R_Object_streamLookChar', as(this, 'Object'))
}

streamGetLine <-
function( this, buf, size )
{
    .Call('R_Object_streamGetLine', as(this, 'Object'), as(buf, 'character'), as(size, 'integer'))
}

streamGetPos <-
function( this )
{
    .Call('R_Object_streamGetPos', as(this, 'Object'))
}

streamSetPos <-
function( this, pos, dir = 0 )
{
    .Call('R_Object_streamSetPos', as(this, 'Object'), as(pos, 'Goffset'), as(dir, 'integer'))
}

streamGetDict <-
function( this )
{
    .Call('R_Object_streamGetDict', as(this, 'Object'))
}

getTypeName <-
function( this )
{
    .Call('R_Object_getTypeName', as(this, 'Object'))
}

print <-
function( this, f )
{
    .Call('R_Object_print', as(this, 'Object'), as(f, 'FILEPtr'))
}

memCheck <-
function( f )
{
    .Call('R_Object_memCheck', as(f, 'FILEPtr'))
}
