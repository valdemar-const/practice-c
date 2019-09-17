#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

static void free_node_tree(tree_node root);
static void insert_value(tree_node *root, int new_value);
static void print_tree(tree_node root);
static bool is_in_tree(tree_node root, int value);

nv_tree nvt_init_tree(nv_tree *tree)
{
	if (*tree == NULL) {
		nv_tree new_tree = malloc(sizeof(struct tree_t));
		new_tree->root = NULL;

		*tree = new_tree;
		return *tree;
	}
	return *tree;
}

nv_tree nvt_delete_tree(nv_tree *tree)
{
	if (*tree != NULL) {
		free_node_tree((*tree)->root);
        free(*tree);
		*tree = NULL;
	}
	return *tree;
}

void nvt_add_value(nv_tree tree, int new_value)
{
	if (tree != NULL) {
		insert_value(&tree->root, new_value);
	}
}

bool nvt_is_int_tree(nv_tree tree, int value)
{
    bool answer = false;
    if (tree != NULL){
        answer = is_in_tree(tree->root, value);
    }
    return answer;
}

void nvt_print(nv_tree tree)
{
    if (tree != NULL){
        print_tree(tree->root);
    }
}

static void free_node_tree(tree_node root)
{
	if (root != NULL) {
		free_node_tree(root->left);
		free_node_tree(root->right);
		free(root);
	}
}

static void insert_value(tree_node *root, int new_value)
{
	if (*root == NULL) {
		tree_node new_node = malloc(sizeof(struct node_t));
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

static void print_tree(tree_node root){
    if (root != NULL){
        print_tree(root->left);
        printf("%d ", root->value);
        print_tree(root->right);
    }
}

static bool is_in_tree(tree_node root, int value)
{
    bool answer = false;
    if (root != NULL){
        if (root->value == value){
            answer = true;
        } else {
            answer = answer || is_in_tree(root->left, value);
            answer = answer || is_in_tree(root->right, value);
        }
    }
    return answer;
}
