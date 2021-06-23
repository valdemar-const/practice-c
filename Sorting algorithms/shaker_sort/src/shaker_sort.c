#include <shaker_sort.h>

static void swap(void *lhs, void *rhs, size_t size);

void ya_shr_sort(void *first, size_t number, size_t size,
	      comparef_t comparator)
{
	char *begin = (char *)first;
	char *last = (char *)first + size * (number - 1);
	while (begin <= last) {
		char *new_begin = last - size;
		char *new_end = begin;
		for (char *i = begin; i < last; i += size) {
			if (comparator(i, i+size) > 0) {
				swap(i, i+size, size);
			}
		}
		last -= size;
		for (char *i = new_begin; i > new_end; i -= size) {
			if (comparator(i, i-size) < 0) {
				swap(i, i-size, size);
			}
		}
		begin += size;
	}
}

static void swap(void *lhs, void *rhs, size_t size)
{
	char *first = lhs;
	char *second = rhs;
	if (lhs == rhs)
		return;
	do {
		char tmp = *first;
		*first++ = *second;
		*second++ = tmp;
	} while (--size > 0);
}