/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 17:42:41 by emartine          #+#    #+#             */
/*   Updated: 2018/01/17 17:42:44 by emartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTREE_H
# define BTREE_H

#include <stdlib.h>

typedef struct s_btree	t_btree;

struct					s_btree
{
	t_btree				*parent;
	t_btree				*left;
	t_btree				*right;
	void				*data;
	size_t				size;
};

/*
** t_btree_cmp acts like strcmp. Used to add elements in the tree.
*/

typedef int				(*t_btree_cmp)(const void *current_data,
		size_t current_size, const void *child_data, size_t child_size);

typedef void			(*t_btree_action)(t_btree *node, void *param);

t_btree					*btree_create(void *srcdata, size_t size);
void					btree_clean(t_btree **tree);
void					btree_add(t_btree *tree, t_btree *child,
		t_btree_cmp cmp);

#endif
