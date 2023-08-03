#include "binary_trees.h"

/**
 * bst_insert - Inserts a passed value in a Binary Search Tree.
 * @tree: A double pointer to the root node of the BST.
 * @value: The passed value to be inserted.
 * Return: A pointer or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *local_tree;
	bst_t *new_tree;

	if (!tree)
		return (NULL);

	local_tree = *tree;
	if (local_tree == NULL)
	{
		/* Creating a new_tree tree incase a NULL pointer is passed */
		new_tree = binary_tree_node(local_tree, value);
		if (new_tree == NULL)
			return (NULL);
		return (*tree = new_tree);
	}

	if (value < local_tree->n)
	{
		/* Recursing through until a leaf is reached */
		if (local_tree->left)
			return (bst_insert(&local_tree->left, value));

		/* inserting into the left subtree */
		new_tree = binary_tree_node(local_tree, value);
		if (new_tree == NULL)
			return (NULL);
		return (local_tree->left = new_tree);
	}
	if (value > local_tree->n)
	{
		/* Recursing through until a leaf is reached */
		if (local_tree->right)
			return (bst_insert(&local_tree->right, value));

		/* inserting into the right subtree */
		new_tree = binary_tree_node(local_tree, value);
		if (new_tree == NULL)
			return (NULL);
		return (local_tree->right = new_tree);
	}
}
