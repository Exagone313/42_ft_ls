/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filesystem_readtree_long_aux.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 20:00:36 by emartine          #+#    #+#             */
/*   Updated: 2018/03/12 20:00:38 by emartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pwd.h>
#include <grp.h>
#include <time.h>
#include "filesystem_readtree_long_aux.h"

#ifndef S_IFIFO
# define S_IFIFO 0
#endif
#ifndef S_IFWHT
# define S_IFWHT 0
#endif

#define SIXMONTHS ((365 / 2) * 86400)

static char	filetype(mode_t fmt)
{
	if (fmt == S_IFDIR)
		return ('d');
	if (fmt == S_IFCHR)
		return ('c');
	if (fmt == S_IFBLK)
		return ('b');
	if (fmt == S_IFREG)
		return ('-');
	if (fmt == S_IFLNK)
		return ('l');
	if (fmt == S_IFSOCK)
		return ('s');
	if (fmt == S_IFIFO)
		return ('p');
	if (fmt == S_IFWHT)
		return ('w');
	return ('?');
}

/*
** TODO ACL (+) and extended attributes (@)
*/

static void	print_mode(t_ls_state *state, mode_t mode)
{
	printer_char(&(state->stdout), filetype(mode & S_IFMT));
	printer_char(&(state->stdout), mode & S_IRUSR ? 'r' : '-');
	printer_char(&(state->stdout), mode & S_IWUSR ? 'w' : '-');
	if (mode & S_ISUID)
		printer_char(&(state->stdout), mode & S_IXUSR ? 's' : 'S');
	else
		printer_char(&(state->stdout), mode & S_IXUSR ? 'x' : '-');
	printer_char(&(state->stdout), mode & S_IRGRP ? 'r' : '-');
	printer_char(&(state->stdout), mode & S_IWGRP ? 'w' : '-');
	if (mode & S_ISGID)
		printer_char(&(state->stdout), mode & S_IXGRP ? 's' : 'S');
	else
		printer_char(&(state->stdout), mode & S_IXGRP ? 'x' : '-');
	printer_char(&(state->stdout), mode & S_IROTH ? 'r' : '-');
	printer_char(&(state->stdout), mode & S_IWOTH ? 'w' : '-');
	if (mode & S_ISVTX)
		printer_char(&(state->stdout), mode & S_IXOTH ? 't' : 'T');
	else
		printer_char(&(state->stdout), mode & S_IXOTH ? 'x' : '-');
	printer_bin(&(state->stdout), "  ", 2);
}

static void	print_datetime(t_ls_state *state, t_fs_handle *handle)
{
	time_t	now;
	char	*dtstr;

	printer_char(&(state->stdout), ' ');
	now = time(NULL);
	dtstr = ctime(&(handle->stat.st_mtimespec.tv_sec));
	if (now - SIXMONTHS < handle->stat.st_mtimespec.tv_sec
			&& now + SIXMONTHS > handle->stat.st_mtimespec.tv_sec)
		printer_bin(&(state->stdout), dtstr + 4, 12);
	else
	{
		printer_bin(&(state->stdout), dtstr + 4, 7);
		printer_bin(&(state->stdout), dtstr + 19, 5);
	}
	printer_char(&(state->stdout), ' ');
}

static void	print_user_group(t_ls_long *long_state, t_fs_handle *data)
{
	struct passwd	*passwd;
	struct group	*group;
	t_padding		pad;

	pad.ch = ' ';
	pad.size = long_state->max_user_length;
	if ((passwd = getpwuid(data->stat.st_uid)))
		printer_str_padding_right(&(long_state->tree->state->stdout),
				passwd->pw_name, pad);
	else
		printer_uint_padding_right(&(long_state->tree->state->stdout),
				data->stat.st_uid, pad);
	printer_bin(&(long_state->tree->state->stdout), "  ", 2);
	pad.size = long_state->max_group_length;
	if ((group = getgrgid(data->stat.st_gid)))
		printer_str_padding_right(&(long_state->tree->state->stdout),
				group->gr_name, pad);
	else
		printer_uint_padding_right(&(long_state->tree->state->stdout),
				data->stat.st_gid, pad);
}

void		filesystem_readtree_long_aux(t_ls_long *long_state,
		t_fs_handle *data)
{
	t_padding		pad;

	pad.ch = ' ';
	print_mode(long_state->tree->state, data->stat.st_mode);
	pad.size = printer_ulong_length(long_state->max_links);
	printer_ulong_padding_left(&(long_state->tree->state->stdout),
			data->stat.st_nlink, pad);
	printer_char(&(long_state->tree->state->stdout), ' ');
	print_user_group(long_state, data);
	printer_bin(&(long_state->tree->state->stdout), "  ", 2);
	pad.size = printer_ulong_length(long_state->max_size);
	printer_ulong_padding_left(&(long_state->tree->state->stdout),
			data->stat.st_size, pad);
	print_datetime(long_state->tree->state, data);
}
