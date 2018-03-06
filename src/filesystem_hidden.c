/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filesystem_hidden.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 17:03:39 by emartine          #+#    #+#             */
/*   Updated: 2018/03/06 17:03:41 by emartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filesystem.h"
#include "main.h"

int		filesystem_hidden(int params, char *filename)
{
	if (params & PARAM_SHOW_ALL)
		return (0);
	if (ft_strcmp(filename, ".") == 0 || ft_strcmp(filename, "..") == 0)
		return (1);
	return (!(params & PARAM_SHOW_HIDDEN) && filename[0] == '.');
}
