#include <merge_sort.h>

#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <inttypes.h>

static void swap(void *lhs, void *rhs, size_t size);
static void merge(void *left, size_t left_number, void *right,
		  size_t right_number, size_t size, comparef_t comparator);

void msort(void *first, size_t number, size_t size, comparef_t comparator)
{
	if (number == 1) {
		return;
	}
	char *begin = (char *)first;
	size_t left_size = number - number / 2;
	size_t right_size = number - left_size;
	char *middle = begin + left_size * size;
	msort(begin, left_size, size, comparator);
	msort(middle, right_size, size, comparator);
	merge(begin, left_size, middle, right_size, size, comparator);
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

static void merge(void *left, size_t left_number, void *right,
		  size_t right_number, size_t size, comparef_t comparator)
{
	size_t buff_size = (left_number + right_number) * size;
	char *buffer = (char *)malloc(buff_size);
	char *p_buffer = buffer;
	char *p_left = (char *)left;
	char *p_right = (char *)right;
	char *result = (char *)left;
	while (left_number && right_number) {
		if (comparator(p_left, p_right) <= 0) {
			memcpy(p_buffer, p_left, size);
			p_left += size;
			p_buffer += size;
			--left_number;
		} else {
			memcpy(p_buffer, p_right, size);
			p_right += size;
			p_buffer += size;
			--right_number;
		}
	}
	size_t remainder = llabs((long long)(left_number - right_number));
	char *rem_src =
		(remainder && left_number > right_number) ? p_left : p_right;
	while (remainder) {
		memcpy(p_buffer, rem_src, size);
		rem_src += size;
		p_buffer += size;
		--remainder;
	}
	memcpy(result, buffer, buff_size);
	free(buffer);
}