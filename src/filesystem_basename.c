/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filesystem_basename.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 16:23:08 by emartine          #+#    #+#             */
/*   Updated: 2018/03/13 16:23:09 by emartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "filesystem_basename.h"

char	*filesystem_basename(char *filepath)
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
	return (filepath);
}
