/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filesystem_stat_mode.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 16:13:39 by emartine          #+#    #+#             */
/*   Updated: 2018/03/14 16:13:40 by emartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filesystem.h"

mode_t	filesystem_stat_mode(char *path)
{
	struct stat		buf;

	if (stat(path, &buf) < 0)
		return (0);
	else
		return (buf.st_mode);
}
