/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_mtime_reverse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 12:10:46 by emartine          #+#    #+#             */
/*   Updated: 2018/02/22 12:10:48 by emartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "compat.h"

int	sort_mtime_reverse(const void *current_data,
		size_t current_size, const void *child_data, size_t child_size)
{
	t_fs_handle	*current;
	t_fs_handle	*child;

	(void)current_size;
	(void)child_size;
	current = (t_fs_handle *)current_data;
	child = (t_fs_handle *)child_data;
	if (current->stat.st_mtimespec.tv_sec == child->stat.st_mtimespec.tv_sec)
	{
		if (current->stat.st_mtimespec.tv_nsec ==
				child->stat.st_mtimespec.tv_nsec)
			return (sort_alpha_reverse(current_data, current_size, child_data,
						child_size));
		return (current->stat.st_mtimespec.tv_nsec -
				child->stat.st_mtimespec.tv_nsec);
	}
	return (current->stat.st_mtimespec.tv_sec -
			child->stat.st_mtimespec.tv_sec);
}
