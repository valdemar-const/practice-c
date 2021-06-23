#include <assert.h>
#include "binary_tree.h"

int main()
{
	ya_tree *my_tree = nvt_init_tree();
	assert(my_tree);

	nvt_add_value(my_tree, 5);
	nvt_add_value(my_tree, 2);
	nvt_add_value(my_tree, 7);
	nvt_add_value(my_tree, 1);
	nvt_add_value(my_tree, 4);

	assert(nvt_is_in_tree(my_tree, 5));
	assert(nvt_is_in_tree(my_tree, 2));
	assert(nvt_is_in_tree(my_tree, 7));
	assert(nvt_is_in_tree(my_tree, 1));
	assert(nvt_is_in_tree(my_tree, 4));

	nvt_print(my_tree);

	nvt_invert_tree(my_tree);

	assert(nvt_is_in_tree(my_tree, 5));
	assert(nvt_is_in_tree(my_tree, 2));
	assert(nvt_is_in_tree(my_tree, 7));
	assert(nvt_is_in_tree(my_tree, 1));
	assert(nvt_is_in_tree(my_tree, 4));

	nvt_print(my_tree);

	my_tree = nvt_delete_tree(my_tree);

	assert(!my_tree);
}