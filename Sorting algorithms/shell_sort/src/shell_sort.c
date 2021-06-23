#include <shell_sort.h>

static void swap(void *lhs, void *rhs, size_t size);

void shl_sort(void *first, size_t number, size_t size,
	      int (*comparator)(const void *, const void *))
{
	char *begin = (char *)first;
	char *last = begin + size * (number - 1);
	size_t distance = number / 2;
	while (distance) {
		size_t p_dist = distance * size;
		for (char *i = begin + p_dist; i <= last; i += size) {
			for (char *j = i - p_dist; j >= begin; j -= p_dist) {
				if (comparator(j, j + p_dist) > 0) {
					swap(j, j + p_dist, size);
				}
			}
		}
		distance /= 2;
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