#include "binary_trees.h"

/**
 * bst_insert - This will Insert a new value in a Binary Search Tree.
 * @tree: A double pointer to the root node of the BST to insert the value.
 * @value: The value to store in the node.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *temp, *new;

	if (tree != NULL)
	{
		temp = *tree;

		if (temp == NULL)
		{
			new = binary_tree_node(temp, value);
			if (new == NULL)
				return (NULL);
			return (*tree = new);
		}

		if (value < temp->n) /* insert in left subtree */
		{
			if (temp->left != NULL)
				return (bst_insert(temp->left, value));

			new = binary_tree_node(temp, value);
			if (new == NULL)
				return (NULL);
			return (temp->left = new);
		}
		if (value > temp->n)/* To insert right subtree */
		{
			if (temp->right != NULL)
				return (bst_insert(&temp->right, value));

			new = binary_tree_node(temp, value);
			if (new == NULL)
				return (NULL);
			return (temp->right = new);
		}
	}
	return (NULL);
}
