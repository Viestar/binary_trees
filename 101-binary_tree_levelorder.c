#include "binary_trees.h"

/* Prototypes */
void push_func(binary_tree_t *node, l_l_queue_t **q_tail, l_l_queue_t *q_head,
			   void (*func)(int));
l_l_queue_t *create_queue_node(binary_tree_t *node);
void free_queue(l_l_queue_t *q_head);
void pop_node(l_l_queue_t **head);

/**
 * binary_tree_levelorder - Traverses a tree using level-order
 * @tree: A pointer to the root node of the tree to traverse
 * @func: A pointer to a function to call for each node.
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	/* Queues to store node while traversing */
	l_l_queue_t *q_head, *q_tail;

	if (tree == NULL || func == NULL)
		return;

	/* Creating queue from a tree */
	q_head = create_queue_node((binary_tree_t *)tree);
	q_tail = create_queue_node((binary_tree_t *)tree);
	if (q_head == NULL)
		return;

	/* Traversing through the queue */
	while (q_head)
	{
		push_func(q_head->node, &q_tail, q_head, func);
		pop_node(&q_head);
	}
}
/**
 * create_queue_node - Creates a queue l_l_queue_t node.
 * @node: Tree to quese
 * Return: Queues
 */
l_l_queue_t *create_queue_node(binary_tree_t *node)
{
	l_l_queue_t *queue;

	/* Allocating and verifying memory for the Queue array*/
	queue = malloc(sizeof(l_l_queue_t));
	if (queue == NULL)
		return (NULL);

	queue->node = node;
	queue->next = NULL;

	return (queue);
}

/**
 * push_func - Queues.
 * @node: The binary tree node to print and push.
 * @q_head: A double pointer to the q_head of the queue.
 * @q_tail: A double pointer to the q_tail of the queue.
 * @func: A pointer to the function to call on @node.
 */
void push_func(binary_tree_t *node, l_l_queue_t **q_tail, l_l_queue_t *q_head,
			   void (*func)(int))
{
	l_l_queue_t *queue;

	func(node->n);
	if (node->left)
	{
		/* Queueing left side children */
		queue = create_queue_node(node->left);
		if (queue)
		{
			(*q_tail)->next = queue;
			*q_tail = queue;
		}
		free_queue(q_head);
		exit(1);
	}
	if (node->right)
	{
		/* Queueing right side children */
		queue = create_queue_node(node->right);
		if (queue == NULL)
		{
			free_queue(q_head);
			exit(1);
		}
		(*q_tail)->next = queue;
		*q_tail = queue;
	}
}

/**
 * free_queue - Frees a l_l_queue_t queue.
 * @q_head: A pointer to the q_head of the queue.
 *
 */
void free_queue(l_l_queue_t *q_head)
{
	l_l_queue_t *tmp;

	while (q_head != NULL)
	{
		tmp = q_head->next;
		free(q_head);
		q_head = tmp;
	}
}
/**
 * pop - Pops the head of the queue.
 * @head: A pointer to the head of the queue.
 */
void pop_node(l_l_queue_t **head)
{
	l_l_queue_t *tmp;

	tmp = (*head)->next;
	free(*head);
	*head = tmp;
}
