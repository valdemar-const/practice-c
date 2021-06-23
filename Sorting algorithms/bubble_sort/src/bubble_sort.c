#include "bubble_sort.h"

static void swap(void *lhs, void *rhs, size_t size);

void bsort(void *first, size_t number, size_t size, comparef_t comparator)
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