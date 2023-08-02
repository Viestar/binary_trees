#include "binary_trees.h"

/* Prototypes */
binary_tree_t *peep_nodes(const binary_tree_t *first,
						  const binary_tree_t *second);

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
	binary_tree_t *local_first = first;
	binary_tree_t *local_second = second;
	binary_tree_t *lowest_common;
	size_t depth_first, depth_second;

	/* Checking if empty node are passed */
	if (!local_first || !local_second)
		return (NULL);

	/* In case the passed nodes are identical */
	if (local_first == local_second)
		return (local_first);

	/* Incase passed nodes have the same parents */
	if (local_first->parent == local_second->parent)
		/* return (lowest_common = peep_nodes(local_first, local_second)); */
		return (local_second->parent);

	/* Incase second node same to first's parent */
	if (local_second == local_first->parent)
		return (local_first->parent);

	/* Incase first node same to second's parent */
	if (local_first == local_second->parent)
		return (local_first);

	/* Traversing through both nodes to get the depth */
	for (depth_first = binary_tree_depth(local_first);
		 depth_first > 1; depth_first--)
		local_first = local_first->parent;
	for (depth_second = binary_tree_depth(local_second);
		 depth_second > 1; depth_second--)
		local_second = local_second->parent;

	if (local_first && local_second)
		return (lowest_common = peep_nodes(local_first, local_second));
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
	binary_tree_t *local_first = first;
	binary_tree_t *local_second = second;

	/* In case the passed nodes are identical */
	if (local_first == local_second)
		return (local_first);

	/* Incase passed nodes have the same parents */
	if (local_first->parent == local_second->parent)
		return (local_second->parent);

	/* Incase second node same to first's parent */
	if (local_second == local_first->parent)
		return (local_first->parent);

	/* Incase first node same to second's parent */
	if (local_first == local_second->parent)
		return (local_first);
}
