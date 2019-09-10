#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

nv_list *init_list(nv_list *list)
{
	if (list == NULL) {
		nv_list *new_list = (nv_list *)malloc(sizeof(nv_list));
		new_list->head = NULL;
		list = new_list;
	}
	return list;
}

void insert_to_list(nv_list *list, int new_value)
{
	list_node *new_node = (list_node *)malloc(sizeof(list_node));
	new_node->value = new_value;
	new_node->next = NULL;

	if (list->head == NULL) {
		list->head = new_node;
	} else {
		list_node *current = list->head;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = new_node;
	}
}

void remove_from_list(nv_list *list, int value)
{
	if (list != NULL) {
		if (list->head != NULL) {
			list_node *current = list->head;
			list_node *prev = current;

			while (current != NULL) {
				if (current->value != value) {
					prev = current;
					current = current->next;
				} else {
					list_node *temp = current;
					if (current != list->head) {
						prev->next = current->next;
						free(temp);
						return;
					} else {
						list->head = current->next;
						free(temp);
						return;
					}
				}
			}
		}
	}
}

bool is_in_list(nv_list *list, int value)
{
	if (list != NULL) {
		if (list->head != NULL) {
			list_node *current = list->head;
			while (current != NULL) {
				if (current->value == value) {
					return true;
				}
				current = current->next;
			}
		}
	}
	return false;
}

void print_list(nv_list *list)
{
	if (list != NULL) {
		if (list->head != NULL) {
			list_node *current = list->head;
			while (current != NULL) {
				printf("%d ", current->value);
				current = current->next;
			}
			puts("\n");
		}
	}
}

nv_list *delete_list(nv_list *list)
{
	if (list != NULL) {
		if (list->head != NULL) {
			list_node *current = list->head;
			while (current != NULL) {
				list_node *temp = current;
				current = temp->next;
				free(temp);
			}
		}
		free(list);
		list = NULL;
	}
	return list;
}
