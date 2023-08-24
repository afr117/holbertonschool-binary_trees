#include "binary_trees.h"
#include <stddef.h>

size_t max(size_t a, size_t b)
{
    return (a > b ? a : b);
}

/**
 * binary_tree_height - Measures height of binary tree.
 * @tree: Points to root node of tree, measures the height.
 *
 * Return: Height of the binary tree, or 0 if tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
	return (0);

	return (1 + max(binary_tree_height(tree->left), binary_tree_height(tree->right)));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: Pointer to root node of tree to check.
 *
 * Return: 1 if tree perfect, otherwise 0.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
	return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (left_height == right_height)
{
	if (binary_tree_is_perfect(tree->left) &&
	binary_tree_is_perfect(tree->right))
	return (1);
	return (binary_tree_is_perfect(tree->left) && binary_tree_is_perfect(tree->right));
}

	return (0);
}
