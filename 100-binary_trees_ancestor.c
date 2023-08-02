#include "binary_trees.h"

/* Prototypes */
binary_tree_t *peep_nodes(const binary_tree_t *first,
						  const binary_tree_t *second);
size_t binary_tree_local_depth(const binary_tree_t *tree);

/**
 * binary_trees_ancestor - finds the lowest common ancestor of the two nodes.
 * @first: first node
 * @second: second node.
 * Return: Poiner to the lowest ancestor or NULL.
 * Description: Uses comparison and depth.
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									 const binary_tree_t *second)
{

	binary_tree_t *lowest_common;
	size_t depth_first, depth_second;

	/* Checking if empty node are passed */
	if (!first || !second)
		return (NULL);

	/* In case the passed nodes are identical */
	if (first == second)
		return ((binary_tree_t *)first);

	/* Incase passed nodes have the same parents */
	if (first->parent == second->parent)
		/* return (lowest_common = peep_nodes(first, second)); */
		return ((binary_tree_t *)second->parent);

	/* Incase second node same to first's parent */
	if (second == first->parent)
		return ((binary_tree_t *)first->parent);

	/* Incase first node same to second's parent */
	if (first == second->parent)
		return ((binary_tree_t *)first);

	/* Traversing through both nodes to get the depth */
	for (depth_first = binary_tree_local_depth(first);
		 depth_first > 1; depth_first--)
		first = first->parent;
	for (depth_second = binary_tree_local_depth(second);
		 depth_second > 1; depth_second--)
		second = second->parent;

	if (first && second)
		return (lowest_common = peep_nodes(first, second));
	else
		return (NULL);
}

/**
 * binary_trees_ancestor - finds the lowest common ancestor of the two nodes.
 * @first: first node
 * @second: second node.
 * Return: Poiner to the lowest ancestor or NULL.
 * Description: Uses comparison and depth.
 */
binary_tree_t *peep_nodes(const binary_tree_t *first,
						  const binary_tree_t *second)
{

	/* In case the passed nodes are identical */
	if (first == second)
		return ((binary_tree_t *)first);

	/* Incase passed nodes have the same parents */
	if (first->parent == second->parent)
		return ((binary_tree_t *)second->parent);

	/* Incase second node same to first's parent */
	if (second == first->parent)
		return ((binary_tree_t *)first->parent);

	/* Incase first node same to second's parent */
	if (first == second->parent)
		return ((binary_tree_t *)first);

	return (0);
}

/**
 * depth - Measures node depth.
 * @tree: A pointer to the node.
 * Return: If tree is NULL, your function must return 0, else return the depth.
 */
size_t binary_tree_local_depth(const binary_tree_t *tree)
{
	return ((tree->parent != NULL) ? 1 + binary_tree_local_depth(tree->parent) : 0);
}