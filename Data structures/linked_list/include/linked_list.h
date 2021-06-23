#pragma once

#include <stdbool.h>

typedef struct node_t {
	int value;
	struct node_t *next;
} list_node;

typedef struct list_t {
	list_node *head;
} ya_list;

ya_list *init_list();
ya_list *delete_list(ya_list *list);

void insert_to_list(ya_list *list, int new_value);
void remove_from_list(ya_list *list, int value);
ya_list *reverse_list(ya_list *head);

bool is_in_list(ya_list *list, int value);

void print_list(ya_list *list);
