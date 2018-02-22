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

int	sort_mtime(const void *current_data,
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
		return (current->stat.st_mtimespec.tv_nsec -
				child->stat.st_mtimespec.tv_nsec);
	}
	return (current->stat.st_mtimespec.tv_sec -
			child->stat.st_mtimespec.tv_sec);
}
