#include "odd-even_sort.h"

static void swap(void *lhs, void *rhs, size_t size);

void oesort(void *first, size_t number, size_t size,
	    int (*comp)(const void *, const void *))
{
	char *begin = (char *)first;
	char *last = begin + (number - 1) * size;
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