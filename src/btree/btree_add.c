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

void	btree_add(t_btree *tree, t_btree *child, t_btree_cmp cmp)
{
	t_btree	*current;

	if (tree == NULL)
		return ;
	current = tree;
	while (1)
	{
		if (cmp(current->data, current->size, child->data, child->size) >= 0)
		{
			if (current->left != NULL)
				current = current->left;
			else
			{
				current->left = child;
				child->parent = current;
				return ;
			}
		}
		else
		{
			if (current->right != NULL)
				current = current->right;
			else
			{
				current->right = child;
				child->parent = current;
				return ;
			}
		}
	}
}
