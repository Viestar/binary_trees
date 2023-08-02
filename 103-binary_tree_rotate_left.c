#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Left-rotates a binary tree.
 * @tree: A pointer to the root node.
 * Return: A pointer to the new root.
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *fulcrum, *temp, *temp2;
	(void)temp2;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	/* Switching left using a temp */
	fulcrum = tree->right;
	temp = fulcrum->left;
	fulcrum->left = tree;
	tree->right = temp;

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
