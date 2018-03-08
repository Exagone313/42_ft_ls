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
#include "main.h"
#include "filesystem_readtree_directory.h"

static void	directory_tree_add(t_fs_handle *parent, t_fs_tree *subtree,
		struct dirent *ent)
{
	char	filepath[PATH_MAX];
	size_t	i;

	if (filesystem_hidden(subtree->state->params, ent->d_name))
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
		ft_ls_error(tree->state->argv0, data->filepath);
	subtree.state = tree->state;
	subtree.tree = 0;
	subtree.length = 0;
	subtree.level = tree->level + 1;
	while ((ent = readdir(dir)) != 0)
		directory_tree_add(data, &subtree, ent);
	closedir(dir);
	filesystem_readtree_short(&subtree);
	if (tree->state->params & PARAM_RECURSIVE)
	{
		btree_each(subtree.tree, foreach_directory_prefix, (void *)data);
		btree_each(subtree.tree, foreach_directory, (void *)&subtree);
	}
	btree_clean(&(subtree.tree));
}

static void	foreach_directory(t_btree *node, void *param)
{
	t_fs_handle	*data;
	t_fs_tree *tree;

	tree = (t_fs_tree *)param;
	data = (t_fs_handle	*)(node->data);
	if (!data->hidden && data->stat.st_mode & S_IFDIR)
	{
		if (!(tree->level == 0) && (ft_strcmp(data->filepath, ".") == 0
				|| ft_strcmp(data->filepath, "..") == 0))
			return ;
		//if (tree->length > 1) // FIXME
		//if (ft_strcmp(data->filepath, ".") != 0) // FIXME
		if (tree->level > 0 || tree->length > 1) // FIXME
		{
			if (tree->state->double_endl_prefix)
				printer_endl(&(tree->state->stdout));
			else
				tree->state->double_endl_prefix = 1;
			printer_str(&(tree->state->stdout), data->filepath);
			printer_bin(&(tree->state->stdout), ":\n", 2);
		}
		directory_read(tree, data);
	}
}

static void	foreach_directory_prefix(t_btree *node, void *param)
{
	t_fs_handle	*data;
	t_fs_handle *parent;
	char		filepath[PATH_MAX];

	parent = (t_fs_handle *)param;
	data = (t_fs_handle	*)(node->data);
	if (data->stat.st_mode & S_IFDIR)
	{
		if (ft_strcmp(data->filepath, ".") == 0
				|| ft_strcmp(data->filepath, "..") == 0)
			data->hidden = 1;
		else if (ft_strcmp(parent->filepath, ".") == 0)
		{
			memcpy(filepath, "./", 2);
			ft_strncpy(filepath + 2, data->filepath, PATH_MAX);
			ft_strncpy(data->filepath, filepath, PATH_MAX);
		}
	}
}

void		filesystem_readtree_directory(t_fs_tree *tree)
{
	btree_each(tree->tree, foreach_directory, (void *)tree);
}
