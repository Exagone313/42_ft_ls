/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 17:42:41 by emartine          #+#    #+#             */
/*   Updated: 2018/01/17 17:42:44 by emartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

static int	progress(t_btree **current, t_btree **branch, t_btree *child)
{
	if (*branch != NULL)
		*current = *branch;
	else
	{
		*branch = child;
		child->parent = *current;
		return (1);
	}
	return (0);
}

void		btree_add(t_btree *tree, t_btree *child, t_btree_cmp cmp)
{
	t_btree	*current;

	if (tree == NULL)
		return ;
	current = tree;
	while (1)
	{
		if (cmp(current->data, current->size, child->data, child->size) >= 0)
		{
			if (progress(&current, &(current->left), child))
				return ;
		}
		else
		{
			if (progress(&current, &(current->right), child))
				return ;
		}
	}
}
