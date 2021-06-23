#include <selection_sort.h>

static void swap(void *lhs, void *rhs, size_t size);
static void *next(void *pointer, size_t size);
static void *prev(void *pointer, size_t size);
static void *min(void *first, void *last, size_t size, comparef_t comparator);

void ya_sel_sort(void *first, size_t number, size_t size, comparef_t comparator)
{
	char *begin = (char *)first;
	char *last = (char *)next(first, size * (number - 1));
	for (char *i = begin; i <= last; i += size) {
		swap(i, min(i, last, size, comparator), size);
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

static void *next(void *pointer, size_t size)
{
	return (char *)pointer + size;
}

static void *prev(void *pointer, size_t size)
{
	return (char *)pointer - size;
}

static void *min(void *first, void *last, size_t size, comparef_t comparator)
{
	char *min = (char *)first;
	for (char *i = min + size; i <= (char *)last; i += size) {
		if (comparator(i, min) < 0) {
			min = i;
		}
	}
	return min;
}