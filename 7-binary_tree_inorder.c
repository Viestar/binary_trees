#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_inorder - Performs an in-order traversal of a binary tree.
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to a function to call for each node.
 *
 * Description: In-order traversal means visiting the left subtree, then
 * the current node, and finally the right subtree.
 * The value in each node is passed as a parameter to the function `func`.
 * If either `tree` or `func` is NULL, do nothing.
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree == NULL || func == NULL)
        return;

    /** Recursive in-order traversal on the left subtree */
    binary_tree_inorder(tree->left, func);

    /** Call the function for the current node */
    func(tree->n);

    /** Recursive in-order traversal on the right subtree */
    binary_tree_inorder(tree->right, func);
}
