#pragma once

#include <stddef.h>
#include <stddef.h>
/**
 * @brief shell sort
 */
void ya_shl_sort(void *first, size_t number, size_t size, int (*comparator)(const void *, const void *));