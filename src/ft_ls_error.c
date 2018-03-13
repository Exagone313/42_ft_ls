/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:47:25 by emartine          #+#    #+#             */
/*   Updated: 2018/01/17 16:47:26 by emartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <unistd.h>
#include "libft.h"
#include "ft_ls_error.h"
#include "printer/printer.h"

#define FT_LS_ERROR_BUFFER_LENGTH (NAME_MAX + 2 + PATH_MAX)

void	ft_ls_error(t_ls_state *state, char *file)
{
	char	buffer[FT_LS_ERROR_BUFFER_LENGTH];
	int		i;

	printer_flush(&(state->stdout));
	printer_flush(&(state->stderr));
	ft_strncpy(buffer, state->argv0, NAME_MAX);
	i = ft_strnlen(buffer, NAME_MAX);
	buffer[i++] = ':';
	buffer[i++] = ' ';
	ft_strncpy(buffer + i, file, PATH_MAX);
	perror(buffer);
}
