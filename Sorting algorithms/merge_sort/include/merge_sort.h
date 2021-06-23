#pragma once

#include <sort_common_definitions.h>
#include <stddef.h>

/**
 * @brief sorting an array by merge sort algorithm
 * 
 * @param first start data pointer
 * @param number number of elements
 * @param size element size in bytes
 * @param comparator function to compare elements
 */
void msort(void *first, size_t number, size_t size, comparef_t comparator);