/*
 Copyright (C) 2016 Alexander Borisov
 
 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.
 
 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 
 Author: lex.borisov@gmail.com (Alexander Borisov)
*/

#ifndef MyHTML_SERIALIZATION_H
#define MyHTML_SERIALIZATION_H
#pragma once

#include <myhtml/myosi.h>
#include <myhtml/mystring.h>
#include <myhtml/tree.h>

#define myhtml_serialization_realloc_if_need(len)                        \
if((len + str->length) >= str->size) {                                   \
    size_t size = (len + str->length) + 4096;                            \
    char *data = (char*)myhtml_realloc(str->data, size * sizeof(char));  \
                                                                         \
    if(data) {                                                           \
        str->data = data;                                                \
        str->size = size;                                                \
    }                                                                    \
    else                                                                 \
        return false;                                                    \
}

#ifdef __cplusplus
extern "C" {
#endif

bool myhtml_serialization(myhtml_tree_t* tree, myhtml_tree_node_t* scope_node, myhtml_string_raw_t* str);
bool myhtml_serialization_node(myhtml_tree_t* tree, myhtml_tree_node_t* node, myhtml_string_raw_t* str);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MyHTML_SERIALIZATION_H */
