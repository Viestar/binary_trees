#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_preorder - Performs a pre-order traversal of a binary tree.
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to the function to call for each node.
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree == NULL || func == NULL)
        return;

    /** Call the function for the current node */
    func(tree->n);

    /** Recursive pre-order traversal on the left subtree */
    binary_tree_preorder(tree->left, func);

    /** Recursive pre-order traversal on the right subtree */
    binary_tree_preorder(tree->right, func);
}