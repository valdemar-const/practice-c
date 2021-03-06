#include <assert.h>
#include <stdlib.h>
#include "linked_list.h"

int main()
{
	ya_list *my_list = init_list();

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

	my_list = reverse_list(my_list);
	print_list(my_list);

	remove_from_list(my_list, 5);
	remove_from_list(my_list, 3);

	print_list(my_list);

	assert(!is_in_list(my_list, 5));
	assert(!is_in_list(my_list, 3));

	my_list = delete_list(my_list);
	assert(my_list == NULL);
}
