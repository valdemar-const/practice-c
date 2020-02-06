#include "comb_sort.h"

static void swap(void *lhs, void *rhs, size_t size);

void csort(void *first, size_t number, size_t size,
	   int (*comparator)(const void *, const void *))
{
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