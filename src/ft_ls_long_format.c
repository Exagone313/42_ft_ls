/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_long_format.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 17:53:08 by emartine          #+#    #+#             */
/*   Updated: 2018/01/17 17:53:10 by emartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <pwd.h>
#include <grp.h>
#include <sys/stat.h>
#include <unistd.h>
#include "libft.h"
#include "ft_ls_error.h"
#include "ft_ls_itoan.h"

#define FT_LS_LONG_FORMAT_BUFFER_LENGTH (PATH_MAX + 1024)
#ifndef S_IFWHT
# define S_IFWHT 0
#endif

static void		get_chmod_rwx(char *buffer, struct stat *stat_buffer)
{
	buffer[1] = (stat_buffer->st_mode & S_IRUSR) ? 'r' : '-';
	buffer[2] = (stat_buffer->st_mode & S_IWUSR) ? 'w' : '-';
	buffer[3] = (stat_buffer->st_mode & S_IXUSR) ? 'x' : '-';
	buffer[4] = (stat_buffer->st_mode & S_IRGRP) ? 'r' : '-';
	buffer[5] = (stat_buffer->st_mode & S_IWGRP) ? 'w' : '-';
	buffer[6] = (stat_buffer->st_mode & S_IXGRP) ? 'x' : '-';
	buffer[7] = (stat_buffer->st_mode & S_IROTH) ? 'r' : '-';
	buffer[8] = (stat_buffer->st_mode & S_IWOTH) ? 'w' : '-';
	buffer[9] = (stat_buffer->st_mode & S_IXOTH) ? 'x' : '-';
}

static void		get_chmod(char *buffer, struct stat *stat_buffer)
{
	if (stat_buffer->st_mode & S_IFIFO)
		buffer[0] = 'p';
	else if (stat_buffer->st_mode & S_IFCHR)
		buffer[0] = 'c';
	else if (stat_buffer->st_mode & S_IFDIR)
		buffer[0] = 'd';
	else if (stat_buffer->st_mode & S_IFBLK)
		buffer[0] = 'b';
	else if (stat_buffer->st_mode & S_IFREG)
		buffer[0] = '-';
	else if (stat_buffer->st_mode & S_IFLNK)
		buffer[0] = 'l';
	else if (stat_buffer->st_mode & S_IFSOCK)
		buffer[0] = 's';
	else if (stat_buffer->st_mode & S_IFWHT)
		buffer[0] = 'w';
	else
		buffer[0] = '?';
	get_chmod_rwx(buffer, stat_buffer);
}

static void		get_hardlinks(char *buffer, struct stat *stat_buffer)
{
	size_t		i;

	i = ft_strnlen(buffer, FT_LS_LONG_FORMAT_BUFFER_LENGTH);
	buffer[i] = ' ';
	ft_ls_itoan(stat_buffer->st_nlink, buffer + i + 1,
			FT_LS_LONG_FORMAT_BUFFER_LENGTH - (i + 1));
}

static void		get_user(char *buffer, struct stat *stat_buffer)
{
	struct passwd	*passwd;
	size_t			i;

	i = ft_strnlen(buffer, FT_LS_LONG_FORMAT_BUFFER_LENGTH);
	buffer[i] = ' ';
	if ((passwd = getpwuid(stat_buffer->st_uid)))
		ft_strncpy(buffer + i + 1, passwd->pw_name,
				FT_LS_LONG_FORMAT_BUFFER_LENGTH - (i + 1));
	else
		ft_ls_itoan(stat_buffer->st_uid, buffer + i + 1,
				FT_LS_LONG_FORMAT_BUFFER_LENGTH - (i + 1));
}

static void		get_group(char *buffer, struct stat *stat_buffer)
{
	struct group	*group;
	size_t			i;

	i = ft_strnlen(buffer, FT_LS_LONG_FORMAT_BUFFER_LENGTH);
	buffer[i] = ' ';
	if ((group = getgrgid(stat_buffer->st_gid)))
		ft_strncpy(buffer + i + 1, group->gr_name,
				FT_LS_LONG_FORMAT_BUFFER_LENGTH - (i + 1));
	else
		ft_ls_itoan(stat_buffer->st_uid, buffer + i + 1,
				FT_LS_LONG_FORMAT_BUFFER_LENGTH - (i + 1));
}

static void		get_size(char *buffer, struct stat *stat_buffer)
{
	size_t			i;

	i = ft_strnlen(buffer, FT_LS_LONG_FORMAT_BUFFER_LENGTH);
	buffer[i] = ' ';
	ft_ls_itoan(stat_buffer->st_size, buffer + i + 1,
			FT_LS_LONG_FORMAT_BUFFER_LENGTH - (i + 1));
}

static void		get_datetime(char *buffer, struct stat *stat_buffer)
{
	size_t			i;

	(void)stat_buffer;
	i = ft_strnlen(buffer, FT_LS_LONG_FORMAT_BUFFER_LENGTH);
	buffer[i] = ' ';
	strncpy(buffer + i + 1, "datetime",
			FT_LS_LONG_FORMAT_BUFFER_LENGTH - (i + 1));
}

static void		add_name(char *buffer, char *shown_path)
{
	size_t			i;

	i = ft_strnlen(buffer, FT_LS_LONG_FORMAT_BUFFER_LENGTH);
	buffer[i] = ' ';
	strncpy(buffer + i + 1, shown_path,
			FT_LS_LONG_FORMAT_BUFFER_LENGTH - (i + 1));
}

void			ft_ls_long_format(char *argv0, char *directory,
		char *shown_path)
{
	char			full_path[PATH_MAX];
	struct stat		stat_buffer;
	char			buffer[FT_LS_LONG_FORMAT_BUFFER_LENGTH];

	if (directory)
		ft_strncpy(full_path, directory, PATH_MAX);
	ft_strncpy(full_path + ft_strnlen(full_path, PATH_MAX), shown_path,
			PATH_MAX);
	if (stat(full_path, &stat_buffer) < 0)
		ft_ls_error(argv0, shown_path);
	else
	{
		get_chmod(buffer, &stat_buffer);
		get_hardlinks(buffer, &stat_buffer);
		get_user(buffer, &stat_buffer);
		get_group(buffer, &stat_buffer);
		get_size(buffer, &stat_buffer);
		get_datetime(buffer, &stat_buffer);
		add_name(buffer, shown_path);
		write(1, buffer, ft_strnlen(buffer, FT_LS_LONG_FORMAT_BUFFER_LENGTH));
	}
}
