#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/* Print binary tree using ASCII art */
void print_tree(const binary_tree_t *tree, int level, char *prefix, int is_left)
{
    if (tree == NULL)
        return;

    printf("%s", prefix);
    printf(is_left ? "|-- " : "`-- ");
    printf("%d\n", tree->n);

    if (tree->left || tree->right)
    {
        char new_prefix[255];
        snprintf(new_prefix, sizeof(new_prefix), "%s%s", prefix, is_left ? "|   " : "    ");
        print_tree(tree->right, level + 1, new_prefix, 0);
        print_tree(tree->left, level + 1, new_prefix, 1);
    }
}

/* Wrapper for the print_tree function */
void binary_tree_print(const binary_tree_t *tree)
{
    print_tree(tree, 0, "", 0);
}

