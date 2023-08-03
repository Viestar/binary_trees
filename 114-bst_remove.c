#include "binary_trees.h"

/**
 * bst_remove - Removes a node from a Binary Search Tree (BST).
 * @root: A pointer to the root node of the tree where we will remove a node.
 * @value: The value to remove in the tree.
 * Return: A pointer to the new root of the tree after removal.
 */
bst_t *bst_remove(bst_t *root, int value)
{
    if (root == NULL)
        return NULL;

    /* Search for the node with the given value. */
    if (value < root->n)
    {
        root->left = bst_remove(root->left, value);
    }
    else if (value > root->n)
    {
        root->right = bst_remove(root->right, value);
    }
    else
    {
        /* Node with the given value found, handle removal cases.
        Case 1 : Node has no children or only one child. */
        if (root->left == NULL)
        {
            bst_t *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            bst_t *temp = root->left;
            free(root);
            return temp;
        }

        /* Case 2: Node has two children.
        Find th e inorder successor (smallest node in the right subtree). */
        bst_t *temp = root->right;
        while (temp->left != NULL)
            temp = temp->left;

        /* Copy the data of the inorder successor to the current node.*/
        root->n = temp->n;

        /* Remove the inorder successor from the right subtree. */
        root->right = bst_remove(root->right, temp->n);
    }

    return root;
}
