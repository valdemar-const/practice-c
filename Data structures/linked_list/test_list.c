#include <assert.h>
#include <stdlib.h>
#include "linked_list.h"

int main()
{
	nv_list* my_list = NULL;
	my_list = init_list(my_list);
	assert(my_list != NULL);
	insert_to_list(my_list, 3);
	insert_to_list(my_list, 2);
	insert_to_list(my_list, 1);
	insert_to_list(my_list, 5);
	
	print_list(my_list);

	assert(is_in_list(my_list, 1));
	assert(is_in_list(my_list, 3));
	assert(is_in_list(my_list, 2));
	assert(is_in_list(my_list, 5));

	remove_from_list(my_list, 5);
	remove_from_list(my_list, 3);

	print_list(my_list);

	assert(!is_in_list(my_list, 5));
	assert(!is_in_list(my_list, 3));
	// head = remove_from_list(head, 1);

	// assert(!is_in_list(head, 1));

	// print_list(head);

	my_list = delete_list(my_list);
	assert(my_list == NULL);
}
