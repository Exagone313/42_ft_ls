/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 17:42:41 by emartine          #+#    #+#             */
/*   Updated: 2018/01/17 17:42:44 by emartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>
#include "libft.h"
#include "ft_ls_readpath.h"
#include "main.h"
#include "filesystem.h"

#define INVALID_OPTION_STR_1 ": invalid option -- '?'\n"
#define INVALID_OPTION_STR_2 "Available options: -a -A -d -l -r -R -t\n"
#define INVALID_OPTION_STR INVALID_OPTION_STR_1 INVALID_OPTION_STR_2

static int	parse_arg(char arg, int *result)
{
	if (arg == 'R')
		*result |= PARAM_RECURSIVE;
	else if (arg == 'l')
		*result |= PARAM_LONG_FORMAT;
	else if (arg == 'a')
	{
		*result |= PARAM_SHOW_ALL;
		*result |= PARAM_SHOW_HIDDEN;
	}
	else if (arg == 'r')
		*result |= PARAM_SORT_REVERSE;
	else if (arg == 't')
		*result |= PARAM_SORT_MTIME;
	else if (arg == 'd')
		*result |= PARAM_DIRECTORY;
	else if (arg == 'A')
		*result |= PARAM_SHOW_HIDDEN;
	else if (arg != '1')
		return (1);
	return (0);
}

static int	parse_args(int argc, char **argv, int *dashptr)
{
	int		i;
	int		j;
	int		result;

	result = 0;
	i = 0;
	while (i < argc)
	{
		if (argv[i][0] == '-')
		{
			if (argv[i][1] == '-' && argv[i][2] == '\0')
			{
				*dashptr = i;
				return (result);
			}
			j = 0;
			while (argv[i][++j] != '\0')
				if (parse_arg(argv[i][j], &result))
					return (-argv[i][j]);
		}
		i++;
	}
	return (result);
}

static int	print_help(char *argv0, int params)
{
	char	ch;
	char	buffer[NAME_MAX + sizeof(INVALID_OPTION_STR) + 1];
	size_t	i;
	size_t	l;
	ssize_t	r;

	if (params >= 0)
		return (0);
	ch = (char)-params;
	ft_strncpy(buffer, argv0, NAME_MAX);
	i = ft_strnlen(buffer, NAME_MAX);
	ft_strncpy(buffer + i, INVALID_OPTION_STR, sizeof(INVALID_OPTION_STR));
	buffer[i + 21] = ch;
	l = ft_strnlen(buffer, NAME_MAX + sizeof(INVALID_OPTION_STR));
	i = 0;
	while (i < l)
	{
		r = write(2, buffer + i, l - i);
		i += (unsigned)r;
	}
	return (1);
}

int			main(int argc, char **argv) // TODO file arguments are ordered in ls output!!!! so a loop like now may not be good
{
	int			params;
	int			dash;
	int			i;
	t_fs_tree	args;

	dash = argc;
	params = parse_args(argc, argv, &dash);
	if (print_help(*argv, params))
		return (1);
	filesystem_initargs(&args, argv[0], params);
	i = 0;
	while (++i < dash)
	{
		if (argv[i][0] != '-' || argv[i][1] == '\0')
			filesystem_savetree(&args, argv[i], 0);
	}
	if (dash != argc)
	{
		i = dash + 1;
		while (i < argc)
			filesystem_savetree(&args, argv[i++], 0);
	}
	if (args.length == 0)
		filesystem_savetree(&args, ".", 0);
	filesystem_readargs(&args);
}
