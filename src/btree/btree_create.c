/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 17:42:41 by emartine          #+#    #+#             */
/*   Updated: 2018/01/17 17:42:44 by emartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "btree.h"

t_btree		*btree_create(void *srcdata, size_t size)
{
	t_btree		*tree;
	char		*data;

	if(!(data = malloc(size)))
		return (NULL);
	if(!(tree = malloc(sizeof(*tree))))
	{
		free(data);
		return (NULL);
	}
	ft_memcpy(data, srcdata, size);
	tree->parent = NULL;
	tree->left = NULL;
	tree->right = NULL;
	tree->data = data;
	tree->size = size;
	return (tree);
}
