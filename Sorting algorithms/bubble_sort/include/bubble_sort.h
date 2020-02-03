#include <stddef.h>

/**
 * @brief sorting an array by bubble sort algorithm
 * 
 * @param first start data pointer
 * @param number number of elements
 * @param size element size in bytes
 * @param comparator function to compare elements
 */
void bsort (void *first, size_t number, size_t size, int (* comparator)(const void *, const void *));