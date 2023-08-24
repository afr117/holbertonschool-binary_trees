#include "binary_trees.h"
#include <stddef.h>

/**
 * max - Returns the maximum of two numbers.
 * @a: First number.
 * @b: Second number.
 *
 * Return: The maximum of a and b.
 */
size_t max(size_t a, size_t b)
{
	return (a > b ? a : b);
}

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: The height of the binary tree, or 0 if tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
	return (0);

	return (1 + max(binary_tree_height(tree->left), binary_tree_height(tree->right)));
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the balance factor.
 *
 * Return: The balance factor of the binary tree, or 0 if tree is NULL.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
	return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (left_height - right_height);
}
