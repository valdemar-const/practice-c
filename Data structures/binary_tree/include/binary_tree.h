#pragma once

#include <stdlib.h>
#include <stdbool.h>

typedef struct node_t {
	int value;
	struct node_t *left;
	struct node_t *right;
} tree_node;

typedef struct tree_t {
	tree_node *root;
} ya_tree;

ya_tree *nvt_init_tree();
ya_tree *nvt_delete_tree(ya_tree *tree);

void nvt_add_value(ya_tree *tree, int new_value);

bool nvt_is_in_tree(ya_tree *tree, int value);

void nvt_invert_tree(ya_tree *tree);

void nvt_print(ya_tree *tree);