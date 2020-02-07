#include <stddef.h>

/**
 * @brief sorting an array by odd-even sort algorithm
 * 
 * @param first start data pointer
 * @param number number of elements
 * @param size element size in bytes
 * @param comparator function to compare elements
 */
void oesort(void *first, size_t number, size_t size, int (*comp)(const void *, const void *));