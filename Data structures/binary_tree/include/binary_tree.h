#pragma once

#include <stdlib.h>
#include <stdbool.h>

typedef struct node_t {
	int value;
	struct node_t *left;
	struct node_t *right;
} * tree_node;

typedef struct tree_t {
	tree_node root;
} * nv_tree;

nv_tree nvt_init_tree();
nv_tree nvt_delete_tree(nv_tree tree);

void nvt_add_value(nv_tree tree, int new_value);

bool nvt_is_int_tree(nv_tree tree, int value);

void nvt_print(nv_tree tree);