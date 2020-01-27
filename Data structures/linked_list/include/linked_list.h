#pragma once

#include <stdbool.h>

typedef struct node_t {
	int value;
	struct node_t *next;
} list_node;

typedef struct list_t {
	list_node *head;
} nv_list;

nv_list *init_list();
nv_list *delete_list(nv_list *list);

void insert_to_list(nv_list *list, int new_value);
void remove_from_list(nv_list *list, int value);
nv_list *reverse_list(nv_list *head);

bool is_in_list(nv_list *list, int value);

void print_list(nv_list *list);
