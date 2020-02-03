#include "bubble_sort.h"

static void swap(void *lhs, void *rhs, size_t size);

/**
 * @brief sorting an array by bubble sort algorithm
 * 
 * @param first start data pointer
 * @param number number of elements
 * @param size element size in bytes
 * @param comparator function to compare elements
 */
void bsort(void *first, size_t number, size_t size,
	   int (*comparator)(const void *, const void *))
{
	for (size_t i = 0; i < number - 1; ++i) {
		for (size_t j = 0; j < number - i - 1; ++j) {
			char *curr = (char *)first + size * j;
			char *next = (char *)first + size * (j + 1);
			if (comparator(curr, next) > 0) {
				swap(curr, next, size);
			}
		}
	}
}

static void swap(void *lhs, void *rhs, size_t size)
{
	char *first = lhs;
	char *second = rhs;
	do {
		char tmp = *first;
		*first++ = *second;
		*second++ = tmp;
	} while (--size > 0);
}