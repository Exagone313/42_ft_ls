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

int	sort_mtime_reverse(const void *current_data,
		size_t current_size, const void *child_data, size_t child_size)
{
	t_fs_handle	*child;
	t_fs_handle	*current;

	(void)child_size;
	(void)current_size;
	child = (t_fs_handle *)child_data;
	current = (t_fs_handle *)current_data;
	if (child->stat.st_mtimespec.tv_sec == current->stat.st_mtimespec.tv_sec)
	{
		return (child->stat.st_mtimespec.tv_nsec -
				current->stat.st_mtimespec.tv_nsec);
	}
	return (child->stat.st_mtimespec.tv_sec -
			current->stat.st_mtimespec.tv_sec);
}
