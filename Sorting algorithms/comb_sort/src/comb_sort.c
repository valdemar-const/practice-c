#include "comb_sort.h"
#include "bubble_sort.h"

const double shrink_factor = 1.247;

static void swap(void *lhs, void *rhs, size_t size);

void csort(void *first, size_t number, size_t size, comparef_t comparator)
{
	char *begin = (char *)first;
	char *last = (char *)first + (number - 1) * size;
	size_t distance = (number - 1) / shrink_factor;
	while (distance) {
		char *j = begin + distance * size;
		for (char *i = begin; j <= last; i += size, j += size) {
			if (comparator(i, j) > 0) {
				swap(i, j, size);
			}
		}
		distance /= shrink_factor;
	}
	bsort(first, number, size, comparator);
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