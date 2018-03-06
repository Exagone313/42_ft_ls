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

static void	directory_tree_add(t_fs_handle *parent, t_fs_tree *subtree,
		struct dirent *ent)
{
	char	filepath[PATH_MAX];
	size_t	i;

	if (filesystem_hidden(subtree->params, ent->d_name))
		return ;
	if (ft_strcmp(parent->filepath, ".") == 0)
	{
		filesystem_savetree(subtree, ent->d_name, 0);
		return ;
	}
	strncpy(filepath, parent->filepath, PATH_MAX);
	i = strlen(filepath);
	strncpy(filepath + i, "/", PATH_MAX - i);
	i = strlen(filepath);
	strncpy(filepath + i, ent->d_name, PATH_MAX - i);
	filesystem_savetree(subtree, filepath, 0);
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
	subtree.level = tree->level + 1;
	while ((ent = readdir(dir)) != 0)
		directory_tree_add(data, &subtree, ent);
	closedir(dir);
	filesystem_readtree_short(&subtree);
	btree_clean(&(subtree.tree));
}

static void	foreach_directory(t_btree *node, void *param)
{
	t_fs_handle	*data;
	t_fs_tree *tree;

	tree = (t_fs_tree *)param;
	data = (t_fs_handle	*)(node->data);
	if (data->stat.st_mode & S_IFDIR)
	{
		if (!(tree->level == 0) && (ft_strcmp(data->filepath, ".") == 0
				|| ft_strcmp(data->filepath, "..") == 0))
			return ;
		if (tree->length > 1)
			directory_prefix(data);
		directory_read(tree, data);
	}
}

void		filesystem_readtree_directory(t_fs_tree *tree)
{
	btree_each(tree->tree, foreach_directory, (void *)tree);
}
