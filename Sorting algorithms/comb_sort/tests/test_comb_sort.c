#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "comb_sort.h"

static int int_cmp(const void *lhs, const void *rhs);
static inline void set_intarr_rnd(int *array, size_t size);
static inline int get_rnd_in_range(int min, int max);
static void print_arr(int *array, size_t size);
static int is_sorted_arr(int *array, size_t size);

enum { max_size = 10000, max_value = 100000 };

int main(void)
{
	srand(time(NULL));
	int *array = (int *)malloc(max_size * sizeof(int));
	set_intarr_rnd(array, max_size);

	assert(!is_sorted_arr(array, max_size));

	csort(array, max_size, sizeof(int), int_cmp);

	assert(is_sorted_arr(array, max_size));

	free(array);
}

static int int_cmp(const void *lhs, const void *rhs)
{
	return *(int *)lhs - *(int *)rhs;
}

static void set_intarr_rnd(int *array, size_t size)
{
	for (size_t i = 0; i < size; ++i) {
		array[i] = get_rnd_in_range(1, max_value);
	}
}

static int get_rnd_in_range(int min, int max)
{
	return min + (double)max * rand() / (RAND_MAX + 1.0);
}

static void print_arr(int *array, size_t size)
{
	printf("-- start print array --\n");
	for (size_t i = 0; i < size; ++i) {
		(i > 0) ? printf(", %d", array[i]) : printf("%d", array[i]);
	}
	printf("\n");
	printf("-- end print array --\n");
}

static int is_sorted_arr(int *array, size_t size)
{
	for (size_t i = 0; i < size - 1; ++i) {
		if (array[i] > array[i + 1]) {
			return 0;
		}
	}
	return 1;
}