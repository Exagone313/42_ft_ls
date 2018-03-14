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

#include <unistd.h>
#include "libft.h"
#include "filesystem.h"
#include "ft_ls_error.h"
#include "main.h"
#include "filesystem_readtree_directory.h"

static void	directory_read(t_fs_tree *tree, t_fs_handle *data)
{
	t_fs_tree	subtree;
	DIR			*dir;

	if (!(dir = opendir(data->filepath)))
	{
		ft_ls_error(tree->state, filesystem_basename(data->filepath));
		return ;
	}
	filesystem_subtree(&subtree, tree, data, dir);
	if (tree->state->params & PARAM_LONG_FORMAT)
		filesystem_readtree_long(&subtree);
	else
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
	t_fs_tree	*tree;

	tree = (t_fs_tree *)param;
	data = (t_fs_handle	*)(node->data);
	if (!data->hidden && ((data->stat.st_mode & S_IFMT) == S_IFDIR
			|| (tree->level == 0 && !(tree->state->params & PARAM_LONG_FORMAT)
			&& (filesystem_stat_mode(data->filepath) & S_IFMT) == S_IFDIR)))
	{
		if (tree->level > 0
				&& (ft_strcmp(filesystem_basename(data->filepath), ".") == 0
				|| ft_strcmp(filesystem_basename(data->filepath), "..") == 0))
			return ;
		if (tree->level > 0 || tree->length > 1 || tree->state->arg_error)
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
