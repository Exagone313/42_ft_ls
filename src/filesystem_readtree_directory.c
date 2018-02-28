/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filesystem_readtree_directory.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 12:01:08 by emartine          #+#    #+#             */
/*   Updated: 2018/02/28 12:01:10 by emartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <unistd.h>
#include "libft.h"
#include "filesystem.h"
#include "ft_ls_error.h"

static void	directory_prefix(t_fs_handle *data)
{
	write(1, data->filepath, ft_strlen(data->filepath));
	write(1, ":\n", 2);
}

static void	directory_tree_add(t_fs_tree *subtree, struct dirent *ent)
{
	// TODO prefix
	filesystem_savearg(subtree, ent->d_name);
}

static void	directory_read(t_fs_tree *tree, t_fs_handle *data)
{
	DIR			*dir;
	t_fs_tree	subtree;
	struct dirent *ent;

	if (!(dir = opendir(data->filepath)))
		ft_ls_error(tree->argv0, data->filepath);
	subtree.argv0 = tree->argv0;
	subtree.params = tree->params;
	subtree.sort = tree->sort;
	subtree.tree = 0;
	subtree.length = 0;
	subtree.args_tree = 0;
	while ((ent = readdir(dir)) != 0)
		directory_tree_add(&subtree, ent);
	filesystem_readtree_short(&subtree);
	btree_clean(&(subtree.tree));
	closedir(dir); // TODO do that before, need to copy names
}

static void	foreach_directory(t_btree *node, void *param)
{
	t_fs_handle	*data;
	t_fs_tree *tree;

	tree = (t_fs_tree *)param;
	data = (t_fs_handle	*)(node->data);
	if (data->stat.st_mode & S_IFDIR)
	{
		if (tree->length > 1)
			directory_prefix(data);
		directory_read(tree, data);
	}
}

void		filesystem_readtree_directory(t_fs_tree *tree)
{
	btree_each(tree->tree, foreach_directory, (void *)tree);
}
