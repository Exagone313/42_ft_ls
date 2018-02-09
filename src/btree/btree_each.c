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

void	btree_each(t_btree *tree, t_btree_action action, void *param)
{
	t_btree	*previous;
	t_btree	*current;

	if (tree == NULL)
		return ;
	previous = NULL;
	current = tree;
	while (current != NULL) // TODO
	{
		if (current->parent == previous) // get down
		{
			previous = current;
			if (current->left != NULL)
				current = current->left;
			else
			{
				action(current, param);
				if (current->right != NULL)
					current = current->right;
				else
				{
					previous = current;
					current = current->parent;
				}
			}
		}
		else // get up
		{
			if (current->left == previous)
			{
				previous = current;
				action(current, param);
				if (current->right != NULL)
					current = current->right;
				else
					current = current->parent;
			}
			else // current->right == previous ?
			{
				previous = current;
				current = current->parent;
			}
		}
		/*if (current->parent == previous && current->parent->right == current)
		{
			action(current, param);
			previous = current;
			if (current->left != NULL)
				current = current->left;
			else //if(current->right != N
				current = current->parent;
		}
		if (current->left == previous)
		{
			action(current, param);
			previous = current;
			if (current->right != NULL)
				current = current->right;
			else
				current = current->parent;
		}
		if (current->right == previous)
		{
			previous = current;
			current = current->parent;
		}
		else if (current->left != NULL && previous != current->left)
			current = current->left;
		else if (current->right != NULL && previous != current->right)
			current = current->right;
		else
		{
			action(current, param);
			previous = current;
			current = current->parent;
		}*/
	}
}

