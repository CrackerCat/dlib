/*******************************************************************************
 * Copyright (c) 2015, Jean-David Gadina - www.xs-labs.com
 * Distributed under the Boost Software License, Version 1.0.
 * 
 * Boost Software License - Version 1.0 - August 17th, 2003
 * 
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 * 
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer,
 * must be included in all copies of the Software, in whole or in part, and
 * all derivative works of the Software, unless such copies or derivative
 * works are solely in the form of machine-executable object code generated by
 * a source language processor.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 ******************************************************************************/

#ifndef DLIB_PRIVATE_H
#define DLIB_PRIVATE_H
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include "dlib-types.h"

#ifndef WIN32
#include <stdbool.h>
#endif

typedef struct
{
    void                  * data;
    size_t                  used;
    size_t                  available;
    size_t                  dataSize;
}
__DLib_Array;

typedef struct
{
    char                 ** data;
    size_t                  used;
    size_t                  available;
    size_t                  dataSize;
}
__DLib_StringArray;

struct __DLib_Symbol
{
    char                  * name;
    DLib_ModuleRef          module;
    void                  * address;
};

typedef struct
{
    struct __DLib_Symbol  * data;
    size_t                  used;
    size_t                  available;
    size_t                  dataSize;
}
__DLib_SymbolArray;

struct __DLib_Module
{
    DLib_ModuleType         type;
    int                     loaded;
    char                  * name;
    char                  * path;
    void                  * handle;
    __DLib_SymbolArray      symbols;
};

typedef struct
{
    struct __DLib_Module  * data;
    size_t                  used;
    size_t                  available;
    size_t                  dataSize;
}
__DLib_ModuleArray;

void            __DLib_Array_Init( void * array, size_t dataSize );
size_t          __DLib_Array_GetCount( void * array );
void *          __DLib_Array_GetValueAtIndex( void * array, size_t i );
void            __DLib_Array_InsertCopyOfValue( void * array, void * value );

void            __DLib_Module_Load( DLib_ModuleRef module );

#ifdef WIN32

wchar_t * __DLib_CreateWideStringFromString( char * s );

#endif

#ifdef __cplusplus
}
#endif

#endif /* DLIB_PRIVATE_H */