/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filesystem_subtree.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 16:38:30 by emartine          #+#    #+#             */
/*   Updated: 2018/03/12 16:38:55 by emartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filesystem.h"

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

void		filesystem_subtree(t_fs_tree *subtree, t_fs_tree *tree,
		t_fs_handle *data, DIR *dir)
{
	struct dirent	*ent;

	subtree->tree = 0;
	subtree->state = tree->state;
	subtree->length = 0;
	subtree->level = tree->level + 1;
	while ((ent = readdir(dir)) != 0)
		directory_tree_add(data, subtree, ent);
	closedir(dir);
}
