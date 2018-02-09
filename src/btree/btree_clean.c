/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_clean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 17:42:41 by emartine          #+#    #+#             */
/*   Updated: 2018/01/17 17:42:44 by emartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

static t_btree	*current_delete(t_btree *current)
{
	t_btree	*parent;

	parent = current->parent;
	if (parent->left == current)
		parent->left = NULL;
	else
		parent->right = NULL;
	free(current->data);
	free(current);
	return (parent);
}

void			btree_clean(t_btree **tree)
{
	t_btree	*current;

	if (tree == NULL || *tree == NULL)
		return ;
	current = *tree;
	while (1)
	{
		if (current->left != NULL)
			current = current->left;
		else if (current->right != NULL)
			current = current->right;
		else if (current->parent == NULL)
			break ;
		else
			current = current_delete(current);
	}
	free((*tree)->data);
	free(*tree);
	*tree = NULL;
}
