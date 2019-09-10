typedef struct node_t {
	int value;
	struct node_t *left;
	struct node_t *right;
} tree_node;

typedef struct tree_t {
	tree_node *root;
} nv_tree;