#include <oddeven_sort.h>

static void swap(void *lhs, void *rhs, size_t size);

void ya_oesort(void *first, size_t number, size_t size,
	    comparef_t comparator)
{
	char *begin = (char *)first;
	for (size_t i = 0; i < number; ++i) {
		for (size_t j = (i % 2) ? 0 : 1; j + 1 < number; j += 2) {
			if (comparator(&begin[j * size], &begin[(j + 1) * size]) > 0) {
				swap(&begin[j * size], &begin[(j + 1) * size], size);
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