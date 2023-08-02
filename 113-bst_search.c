#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a binary search tree.
 * @tree: A pointer to the root node of the BST to search.
 * @value: The value to search for in the BST.
 *
 * Return: Null or Pointer
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree)
	{
		/* Base case returning a value */
		if (tree->n == value)
			return ((bst_t *)tree);

		/* Traversing either to left or right depending on node and the value*/
		if (tree->n > value)
			return (bst_search(tree->left, value));
		return (bst_search(tree->right, value));
	}
	return (NULL);
}
