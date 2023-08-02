#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_postorder - Performs a post-order traversal of a binary tree.
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to the function to call for each node.
 *
 * Description: Post-order traversal means visiting the left subtree, then
 * the right subtree, and finally the current node.
 * The value in each node is passed as a parameter to the function `func`.
 * If either `tree` or `func` is NULL, do nothing.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
if (tree == NULL || func == NULL)
return;
binary_tree_postorder(tree->left, func);
binary_tree_postorder(tree->right, func);
func(tree->n);
}
