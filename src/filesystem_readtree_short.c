/* ************************************************************************** *//*                                                                            */
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

static void	filepath_name_write(t_ls_state *state, char *filepath)
{
	size_t	i;

	i = 0;
	while (filepath[i])
	{
		if (filepath[i] == '/')
		{
			filepath += i + 1;
			i = 0;
		}
		else
			i++;
	}
	printer_str(&(state->stdout), filepath);
}

static void	foreach_short(t_btree *node, void *param)
{
	t_fs_handle	*data;
	t_fs_tree *tree;

	tree = (t_fs_tree *)param;
	data = (t_fs_handle	*)(node->data);
	if (!(tree->level == 0) || !(data->stat.st_mode & S_IFDIR))
	{
		if (!data->hidden)
		{
			if (tree->level > 0)
				filepath_name_write(tree->state, data->filepath);
			else
				printer_str(&(tree->state->stdout), data->filepath);
			printer_endl(&(tree->state->stdout));
			if (!(tree->state->double_endl_prefix))
				tree->state->double_endl_prefix = 1;
		}
	}
}

void		filesystem_readtree_short(t_fs_tree *tree)
{
	btree_each(tree->tree, foreach_short, (void *)tree);
}
