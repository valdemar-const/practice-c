#include <quick_sort.h>

#include <stdlib.h>
#include <string.h>

static void swap(void *lhs, void *rhs, size_t size);
static void *partition(void *first, size_t number, size_t size,
		       comparef_t comparator);

void nv_qsort(void *first, size_t number, size_t size, comparef_t comparator)
{
	char *begin = (char *)first;
	char *last = begin + (number - 1) * size;
	if (number == 2 && comparator(begin, last) <= 0)
		return;
	if (begin < last) {
		char *pivot =
			(char *)partition(first, number, size, comparator);
		size_t left_number = (pivot - begin + size) / size;
		size_t right_number = (last - pivot) / size;
		nv_qsort(begin, left_number, size, comparator);
		nv_qsort(pivot + size, right_number, size, comparator);
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

static void *partition(void *first, size_t number, size_t size,
		       comparef_t comparator)
{
	char *begin = (char *)first;
	char *last = begin + (number - 1) * size;
	char *pivot = (char *)malloc(size);
	char *pivot_src = begin + (number - 1) / 2 * size;
	memcpy(pivot, pivot_src, size);
	char *i = begin - size;
	char *j = last + size;
	while (1) {
		do {
			i += size;
		} while (comparator(i, pivot) < 0);
		do {
			j -= size;
		} while (comparator(j, pivot) > 0);
		if (i >= j) {
			free(pivot);
			return j;
		}
		swap(i, j, size);
	}
}