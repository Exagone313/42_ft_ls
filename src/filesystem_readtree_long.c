/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filesystem_readtree_long.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 13:38:32 by emartine          #+#    #+#             */
/*   Updated: 2018/03/12 15:46:02 by emartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include "libft.h"
#include "filesystem.h"
#include "main.h"
#include "filesystem_readtree_long_aux.h"

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

static void	foreach_long(t_btree *node, void *param)
{
	t_fs_handle		*data;
	t_ls_long		*long_state;
	char			linkpath[PATH_MAX];
	ssize_t			r;

	long_state = (t_ls_long *)param;
	data = (t_fs_handle	*)(node->data);
	if ((long_state->tree->level > 0 || !(data->stat.st_mode & S_IFDIR))
			&& !data->hidden)
	{
		filesystem_readtree_long_aux(long_state, data);
		if (long_state->tree->level > 0)
			filepath_name_write(long_state->tree->state, data->filepath);
		else
			printer_str(&(long_state->tree->state->stdout), data->filepath);
		if (data->stat.st_mode & S_IFLNK && (r = readlink(data->filepath,
						linkpath, PATH_MAX)) > 0)
		{
			printer_bin(&(long_state->tree->state->stdout), " -> ", 4);
			printer_bin(&(long_state->tree->state->stdout), linkpath, r);
		}
		printer_endl(&(long_state->tree->state->stdout));
		if (!(long_state->tree->state->double_endl_prefix))
			long_state->tree->state->double_endl_prefix = 1;
	}
}

static void	foreach_first_pass_aux(t_ls_long *long_state, t_fs_handle *data)
{
	struct passwd	*passwd;
	struct group	*group;
	size_t			i;

	if ((passwd = getpwuid(data->stat.st_uid)))
		i = strlen(passwd->pw_name);
	else
		i = printer_uint_length(data->stat.st_uid);
	if (i > long_state->max_user_length)
		long_state->max_user_length = i;
	if ((group = getgrgid(data->stat.st_gid)))
		i = strlen(group->gr_name);
	else
		i = printer_uint_length(data->stat.st_gid);
	if (i > long_state->max_group_length)
		long_state->max_group_length = i;
}

static void	foreach_first_pass(t_btree *node, void *param)
{
	t_fs_handle	*data;
	t_ls_long	*long_state;

	long_state = (t_ls_long *)param;
	data = (t_fs_handle	*)(node->data);
	long_state->total += data->stat.st_blocks;
	if (data->stat.st_nlink > long_state->max_links)
		long_state->max_links = data->stat.st_nlink;
	if ((unsigned long)(data->stat.st_size) > long_state->max_size)
		long_state->max_size = (unsigned long)(data->stat.st_size);
	foreach_first_pass_aux(long_state, data);
}

void		filesystem_readtree_long(t_fs_tree *tree)
{
	t_ls_long	long_state;

	if (tree->length > 0)
	{
		ft_memset(&long_state, 0, sizeof(long_state));
		long_state.tree = tree;
		btree_each(tree->tree, foreach_first_pass, (void *)&long_state);
		if (tree->level > 0)
		{
			printer_str(&(tree->state->stdout), "total ");
			printer_ulong(&(tree->state->stdout), long_state.total);
			printer_endl(&(tree->state->stdout));
		}
		btree_each(tree->tree, foreach_long, (void *)&long_state);
	}
}
