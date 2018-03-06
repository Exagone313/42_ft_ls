/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_mtime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 12:10:38 by emartine          #+#    #+#             */
/*   Updated: 2018/02/22 12:10:40 by emartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "compat.h"

int	sort_mtime(const void *current_data,
		size_t current_size, const void *child_data, size_t child_size)
{
	t_fs_handle	*child;
	t_fs_handle	*current;

	child = (t_fs_handle *)child_data;
	current = (t_fs_handle *)current_data;
	if (child->stat.st_mtimespec.tv_sec == current->stat.st_mtimespec.tv_sec)
	{
		if (child->stat.st_mtimespec.tv_nsec ==
				current->stat.st_mtimespec.tv_nsec)
			return (sort_alpha(current_data, current_size, child_data,
						child_size));
		return (child->stat.st_mtimespec.tv_nsec -
				current->stat.st_mtimespec.tv_nsec);
	}
	return (child->stat.st_mtimespec.tv_sec -
			current->stat.st_mtimespec.tv_sec);
}
