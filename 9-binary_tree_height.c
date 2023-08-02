#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height.
 *
 * Return: The height of the binary tree as a size_t value.
 * If `tree` is NULL, the function returns 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left_height, right_height;

    if (tree == NULL)
        return (0);

    /** Recursive call to get the height of the left subtree */
    left_height = binary_tree_height(tree->left);

    /** Recursive call to get the height of the right subtree */
    right_height = binary_tree_height(tree->right);

    /** Return the maximum height from the left and right subtrees plus 1 for the current node */
    return (1 + (left_height > right_height ? left_height : right_height));
}
