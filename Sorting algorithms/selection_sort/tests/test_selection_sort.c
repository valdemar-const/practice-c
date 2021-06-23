#include <selection_sort.h>

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// #define DEBUG_PRINT

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
	// int array[250] = {65956, 44352, 69917, 64048, 27049, 86406, 87922, 8066, 54321, 78913, 83846, 21805, 65169, 81413, 53676, 2388, 81910, 91860, 29651, 38578, 65111, 96944, 50991, 66032, 26354, 65243, 95072, 51058, 34491, 85368, 48294, 447, 29719, 18210, 64494, 56767, 4616, 52415, 64832, 58936, 31327, 48677, 80740, 96496, 30089, 34416, 98883, 11999, 26275, 28533, 50576, 91386, 25477, 1566, 57417, 51830, 66809, 52488, 2888, 1299, 37855, 51181, 1746, 67573, 69391, 66239, 24339, 74006, 18654, 89171, 32942, 49981, 37847, 13682, 46477, 67936, 48097, 45359, 79934, 74372, 73892, 30510, 65757, 99369, 32075, 23174, 51199, 98883, 75661, 54086, 182, 13516, 5267, 1927, 81088, 74657, 68166, 5427, 48663, 86820, 94597, 81605, 36800, 32444, 95287, 83276, 380, 43383, 28635, 80314, 17755, 2526, 10823, 83512, 1895, 42898, 6685, 53093, 41781, 82345, 7178, 41962, 95860, 12444, 43889, 76948, 87101, 12054, 82375, 35764, 98873, 76972, 17368, 35673, 9416, 12654, 18949, 9795, 56037, 47583, 90108, 73791, 50109, 930, 57303, 52003, 43828, 63987, 5096, 85608, 46331, 12273, 27569, 42191, 24717, 71457, 19139, 11818, 83511, 1513, 47581, 82383, 78485, 64949, 18056, 87900, 77603, 37004, 97694, 33639, 84587, 87801, 7430, 34696, 88731, 64733, 86699, 32558, 28719, 91794, 18165, 75050, 4067, 45734, 17240, 28784, 17191, 36379, 40601, 701, 37892, 88182, 83084, 16376, 53130, 1140, 4275, 30733, 38143, 1969, 64371, 22730, 89770, 71801, 57425, 78500, 36533, 44124, 11058, 65252, 35917, 29223, 40301, 39983, 74957, 57540, 68766, 92147, 93919, 9367, 92848, 31810, 97548, 75932, 48185, 50678, 77071, 52459, 81410, 15213, 54428, 45781, 37943, 44197, 17582, 95367, 22696, 54115, 39490, 33754, 19366, 75407, 62976, 59666, 15390, 37932, 17206, 84156, 30079, 11124};
	// int array[max_size] = {9, 4, 7, 6, 7, 3, 5, 3, 2, 1};
	set_intarr_rnd(array, max_size);
#ifdef DEBUG_PRINT
	print_arr(array, max_size);
#endif
	assert(!is_sorted_arr(array, max_size));

	sel_sort(array, max_size, sizeof(int), int_cmp);
#ifdef DEBUG_PRINT
	print_arr(array, max_size);
#endif
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