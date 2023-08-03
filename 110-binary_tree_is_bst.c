#include "binary_trees.h"
#include "limits.h"
#include <stdbool.h>

bool comp_left_and_right_with_node(const binary_tree_t *tree,
								   int lowest, int highest);

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid binary search tree.
 * @tree: A pointer to the root node of the tree to check.
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	bool result;

	if (!tree)
		return (0);

	/* Use INT_MIN and INT_MAX as initial min and max values.*/
	result = comp_left_and_right_with_node(tree, INT_MIN, INT_MAX);

	if (result)
		return (1);
	return (0);
}

/**
 * comp_left_and_right_with_node - Checks if left child less than node
 *          and right child greater than node.
 * @tree: A pointer to the root node of the tree to check.
 * @lowest: The value of the smallest node visited thus far.
 * @highest: The value of the largest node visited this far.
 * Return: True of False.
 */

bool comp_left_and_right_with_node(const binary_tree_t *tree,
								   int lowest, int highest)
{
	if (tree)
	{
		if (tree->n < lowest || tree->n > highest)
			return (false);

		/* Recursively check the left and right subtrees */
		return (comp_left_and_right_with_node(tree->left, lowest, tree->n - 1) &&
				comp_left_and_right_with_node(tree->right, tree->n + 1, highest));
	}
	return (true);
}
