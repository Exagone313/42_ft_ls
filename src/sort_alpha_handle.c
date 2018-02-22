/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_alpha_handle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 12:47:32 by emartine          #+#    #+#             */
/*   Updated: 2018/02/22 12:47:34 by emartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sort_alpha_handle.h"

static int	alphanumeric_range(char ch)
{
	return (ch == ' '
			|| (ch >= '0' && ch <= '9')
			|| (ch >= 'A' && ch <= 'Z')
			|| (ch >= 'a' && ch <= 'z'));
}

int			sort_alpha_handle(t_fs_handle *current, t_fs_handle *child)
{
	unsigned int	i;
	unsigned int	j;
	int				r;

	i = 0;
	j = 0;
	while (current->filename[i] && child->filename[j])
	{
		if (!alphanumeric_range(current->filename[i]))
			i++;
		else if (!alphanumeric_range(child->filename[j]))
			j++;
		else if (current->filename[i] != child->filename[j])
			break ;
	}
	r = (unsigned char)(current->filename[i])
			- (unsigned char)(child->filename[i]);
	if (r == 0)
		return (ft_strcmp(current->filename, child->filename));
	return (r);
}
