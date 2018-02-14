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

static void	get_down(t_btree **current, t_btree **previous,
		t_btree_action action, void *param)
{
	*previous = *current;
	if ((*current)->left != NULL)
		(*current) = (*current)->left;
	else
	{
		action(*current, param);
		if ((*current)->right != NULL)
			*current = (*current)->right;
		else
		{
			*previous = *current;
			*current = (*current)->parent;
		}
	}
}

static void get_up(t_btree **current, t_btree **previous,
		t_btree_action action, void *param)
{
	if ((*current)->left == *previous)
	{
		*previous = *current;
		action(*current, param);
		if ((*current)->right != NULL)
			*current = (*current)->right;
		else
			*current = (*current)->parent;
	}
	else
	{
		*previous = *current;
		*current = (*current)->parent;
	}
}

void	btree_each(t_btree *tree, t_btree_action action, void *param)
{
	t_btree	*previous;
	t_btree	*current;

	if (tree == NULL)
		return ;
	previous = NULL;
	current = tree;
	while (current != NULL)
	{
		if (current->parent == previous)
			get_down(&current, &previous, action, param);
		else
			get_up(&current, &previous, action, param);
	}
}
