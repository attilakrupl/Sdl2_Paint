/*!
 * \file   macros.h
 * \author Attila Krüpl dr.
 * \date   02/12/2019
 */

#include <stdio.h>

#define IS_NOT( _aBool ) ( !( _aBool ) )
#define IS_FAIL( _aResult ) ( ( _aResult  ) != 0 )
#define IS_SUCCESS( _aResult ) ( ( _aResult  ) == 0 )
#define IS_NULL( _aPointer ) ( ( _aPointer ) == nullptr )
#define PRINT_ERROR( _aError ) printf( "File: %s,\n Line: %d,\n Error: %s\n\n"  , __FILE__, __LINE__, ( _aError   ) )
#define PRINT_WARNING( _aWarning ) printf( "File: %s,\n Line: %d,\n Warning: %s\n\n", __FILE__, __LINE__, ( _aWarning ) )
#define ADDRESS_OF( _aObject ) ( &( _aObject ) )