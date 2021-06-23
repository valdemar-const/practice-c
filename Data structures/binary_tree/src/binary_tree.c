#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

static void free_node_tree(tree_node *root);
static void insert_value(tree_node **root, int new_value);
static void print_tree(tree_node *root);
static bool is_in_tree(tree_node *root, int value);
static tree_node *invert_tree(tree_node *root);

ya_tree *nvt_init_tree()
{
	ya_tree *new_tree = malloc(sizeof(struct tree_t));
	new_tree->root = NULL;

	return new_tree;
}

ya_tree *nvt_delete_tree(ya_tree *tree)
{
	if (tree) {
		free_node_tree(tree->root);
		free(tree);
		tree = NULL;
	}
	return tree;
}

void nvt_add_value(ya_tree *tree, int new_value)
{
	if (tree) {
		insert_value(&tree->root, new_value);
	}
}

bool nvt_is_in_tree(ya_tree *tree, int value)
{
	bool answer = false;
	if (tree) {
		answer = is_in_tree(tree->root, value);
	}
	return answer;
}

void nvt_print(ya_tree *tree)
{
	if (tree) {
		print_tree(tree->root);
	}
}

static void free_node_tree(tree_node *root)
{
	if (root) {
		free_node_tree(root->left);
		free_node_tree(root->right);
		free(root);
	}
}

static void insert_value(tree_node **root, int new_value)
{
	if (!*root) {
		tree_node *new_node = malloc(sizeof(tree_node));
		new_node->value = new_value;
		new_node->left = NULL;
		new_node->right = NULL;

		*root = new_node;
	} else if (new_value < (*root)->value) {
		insert_value(&(*root)->left, new_value);
	} else {
		insert_value(&(*root)->right, new_value);
	}
}

void nvt_invert_tree(ya_tree *tree)
{
	if (!tree->root) {
		return;
	}
	invert_tree(tree->root);
}

static void print_tree(tree_node *root)
{
	if (root) {
		print_tree(root->left);
		printf("%d ", root->value);
		print_tree(root->right);
	}
}

static bool is_in_tree(tree_node *root, int value)
{
	bool answer = false;
	if (root) {
		if (root->value == value) {
			answer = true;
		} else {
			answer = answer || is_in_tree(root->left, value);
			answer = answer || is_in_tree(root->right, value);
		}
	}
	return answer;
}

static tree_node *invert_tree(tree_node *root)
{
	if (root) {
		tree_node *temp = root->left;
		root->left = invert_tree(root->right);
		root->right = invert_tree(temp);
	}
	return root;
}