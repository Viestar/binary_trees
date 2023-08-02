#ifndef BINARY_TREES_H
#define BINARY_TREES_H

/* Basic Binary Tree structure */
typedef struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
} binary_tree_t;

/* Binary Search Tree structure */
typedef struct binary_tree_s bst_t;

/* AVL Tree structure */
typedef struct binary_tree_s avl_t;

/* Max Binary Heap structure */
typedef struct binary_tree_s heap_t;

/* Function prototypes */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);

/* Additional function prototypes (if needed) */

#endif /* BINARY_TREES_H */