#include <insertion_sort.h>

static void swap(void *lhs, void *rhs, size_t size);
static void *next(void *pointer, size_t size);
static void *prev(void *pointer, size_t size);

void ya_ins_sort(void *first, size_t number, size_t size, comparef_t comparator)
{
	char *begin = (char *)first;
	char *last = (char *)begin + size * (number - 1);
	for (char *i = begin + size; i <= last; i += size) {
		char *j = i;
		char *p = prev(j, size);
		while (comparator(j, p) < 0 && j > begin) {
			swap(j, p, size);
			j -= size;
			p -= size;
		}
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