#include "binary_trees.h"

/* Prototypes */
bst_t *bst_search(const bst_t *tree, int value);

/**
 * array_to_bst - Builds a binary search tree from an array.
 * @array: A pointer to the array.
 * @size: Array size.
 * Return: Pointer to the root of the BST or NULL if failed.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL;

	if (array == NULL || size == 0)
		return (NULL);

	for (size_t i = 0; i < size; i++)
	{
		/* Check if the value is already in the tree before insertion. */
		if (bst_search(root, array[i]) == NULL)
		{
			if (bst_insert(&root, array[i]) == NULL)
			{
				/* If bst_insert fails, free the already created tree and return NULL.*/
				binary_tree_delete(root);
				return (NULL);
			}
		}
	}

	return (root);
}

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
