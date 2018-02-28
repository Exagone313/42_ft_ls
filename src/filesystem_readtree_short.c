/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filesystem_readtree_short.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 13:38:32 by emartine          #+#    #+#             */
/*   Updated: 2018/02/26 13:38:34 by emartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "filesystem.h"
#include "main.h"

static void	foreach_short(t_btree *node, void *param)
{
	t_fs_handle	*data;
	t_fs_tree *tree;

	tree = (t_fs_tree *)param;
	data = (t_fs_handle	*)(node->data);
	if (!tree->args_tree || !(data->stat.st_mode & S_IFDIR))
	{
		if (tree->params & PARAM_SHOW_ALL || data->filepath[0] != '.')
		{
			write(1, data->filepath, ft_strlen(data->filepath));
			write(1, "\n", 1);
		}
	}
}

void		filesystem_readtree_short(t_fs_tree *tree)
{
	btree_each(tree->tree, foreach_short, (void *)tree);
}
