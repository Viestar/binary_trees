#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Right-rotates a binary tree.
 * @tree: A pointer to the root node.
 * Return: A pointer to the new root.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *center, *fulcrum, *temp;

	(void)center;
	if (tree == NULL || tree->left == NULL)
		return (NULL);

	/* Switching the right child with left at center */
	fulcrum = tree->left;
	temp = fulcrum->right;
	fulcrum->right = tree;
	tree->left = temp;

	if (temp)
		temp->parent = tree;

	temp = tree->parent;
	tree->parent = fulcrum;
	fulcrum->parent = temp;

	if (temp)
	{
		if (temp->left == tree)
			temp->left = fulcrum;
		else
			temp->right = fulcrum;
	}

	return (fulcrum);
}
