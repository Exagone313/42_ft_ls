/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_alpha_reverse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 12:10:58 by emartine          #+#    #+#             */
/*   Updated: 2018/02/22 12:11:00 by emartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "sort_alpha_handle.h"

int	sort_alpha_reverse(const void *current_data,
		size_t current_size, const void *child_data, size_t child_size)
{
	t_fs_handle	*child;
	t_fs_handle	*current;

	(void)child_size;
	(void)current_size;
	child = (t_fs_handle *)child_data;
	current = (t_fs_handle *)current_data;
	return (sort_alpha_handle(child, current));
}
