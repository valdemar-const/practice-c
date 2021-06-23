#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

ya_list *init_list()
{
	ya_list *new_list = (ya_list *)malloc(sizeof(ya_list));
	new_list->head = NULL;

	return new_list;
}

void insert_to_list(ya_list *list, int new_value)
{
	list_node *new_node = (list_node *)malloc(sizeof(list_node));
	new_node->value = new_value;
	new_node->next = NULL;

	if (!list->head) {
		list->head = new_node;
	} else {
		list_node *current = list->head;
		while (current->next) {
			current = current->next;
		}
		current->next = new_node;
	}
}

void remove_from_list(ya_list *list, int value)
{
	if (list && list->head) {
		list_node *current = list->head;
		list_node *prev = current;

		while (current) {
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

bool is_in_list(ya_list *list, int value)
{
	if (list && list->head) {
		list_node *current = list->head;
		while (current) {
			if (current->value == value) {
				return true;
			}
			current = current->next;
		}
	}
	return false;
}

static list_node *reverse(list_node *head);

ya_list *reverse_list(ya_list *list) {
	list->head = reverse(list->head);
	return list;
}

void print_list(ya_list *list)
{
	if (list) {
		if (list->head) {
			list_node *current = list->head;
			while (current) {
				printf("%d ", current->value);
				current = current->next;
			}
			puts("\n");
		}
	}
}

ya_list *delete_list(ya_list *list)
{
	if (list) {
		if (list->head) {
			list_node *current = list->head;
			while (current) {
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

static list_node *reverse(list_node *head) {
	if (!head || !head->next) {
		return head;
	}
	list_node *tmp = reverse(head->next);
	head->next->next = head;
	head->next = NULL;
	return tmp;
}