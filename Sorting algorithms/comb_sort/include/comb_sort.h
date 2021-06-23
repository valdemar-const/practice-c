#pragma once

#include <sort_common_definitions.h>
#include <stddef.h>
/**
 * @brief sorting an array by comb sort algorithm
 * 
 * @param first start data pointer
 * @param number number of elements
 * @param size element size in bytes
 * @param comparator function to compare elements
 */
void ya_csort (void *first, size_t number, size_t size, comparef_t comparator);