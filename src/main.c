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
#include "sort.h"

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

static int	print_help(t_ls_state *state)
{
	char	ch;
	char	buffer[NAME_MAX + sizeof(INVALID_OPTION_STR) + 1];
	size_t	l;

	if (state->params >= 0)
		return (0);
	ch = (char)-(state->params);
	ft_strncpy(buffer, state->argv0, NAME_MAX);
	l = ft_strnlen(buffer, NAME_MAX);
	ft_strncpy(buffer + l, INVALID_OPTION_STR, sizeof(INVALID_OPTION_STR));
	buffer[l + 21] = ch;
	l = ft_strnlen(buffer, NAME_MAX + sizeof(INVALID_OPTION_STR));
	printer_bin(&(state->stderr), buffer, l);
	printer_flush(&(state->stderr));
	return (1);
}

static int	hack_state(t_ls_state *state, char *argv0, int params)
{
	if (argv0)
	{
		state->argv0 = argv0;
		state->params = params;
		printer_init(&(state->stderr), 2);
		if (print_help(state))
			return (1);
		state->sort = sort_func(params);
		printer_init(&(state->stdout), 1);
	}
	else
	{
		printer_flush(&(state->stdout));
		printer_flush(&(state->stderr));
	}
	return (0);
}

int			main(int argc, char **argv)
{
	t_ls_state	state;
	int			dash;
	int			i;
	t_fs_tree	args;

	dash = argc;
	if (hack_state(&state, argv[0], parse_args(argc, argv, &dash)))
		return (1);
	filesystem_initargs(&args, &state);
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
	hack_state(&state, 0, 42);
}
