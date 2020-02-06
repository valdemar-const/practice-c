#include <insertion_sort.h>

static void swap(void *lhs, void *rhs, size_t size);
static void *next(void *pointer, size_t size);
static void *prev(void *pointer, size_t size);

void ins_sort(void *first, size_t number, size_t size,
	      int (*comp)(const void *, const void *))
{
	char *begin = (char *)first;
	char *last = (char *)next(first, size * (number - 1));
	
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