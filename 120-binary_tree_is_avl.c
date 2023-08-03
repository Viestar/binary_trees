#include "binary_trees.h"
#include "limits.h"

int avl_detector(const binary_tree_t *tree, int lo, int hi);
size_t binary_tree_height(const binary_tree_t *tree);

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root tree node .
 * Return: 1 or 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree)
		return (avl_detector(tree, INT_MIN, INT_MAX));
	return (0);
}

/**
 * avl_detector - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 * @lo: The value of the smallest node visited thus far.
 * @hi: The value of the largest node visited this far.
 *
 * Return: If the tree is a valid AVL tree, 1, otherwise, 0.
 */
int avl_detector(const binary_tree_t *tree, int lo, int hi)
{
	size_t l_height, r_height, dif;

	if (tree)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		/* Calculating the balance factor (dif) */
		l_height = binary_tree_height(tree->left);
		r_height = binary_tree_height(tree->right);

		/* Fetching the absolute size_t difference */
		if (l_height > r_height)
			dif = l_height - r_height;
		dif = r_height - l_height;

		if (dif > 1)
			return (0);
		return (avl_detector(tree->left, lo, tree->n - 1) &&
				avl_detector(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree.
 *
 * Return: Height of the tree, 0 if the tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{

	size_t l = 0;
	size_t r = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
			r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		}
		return ((l > r) ? l : r);
	}
}
