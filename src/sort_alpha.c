/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_alpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 12:10:54 by emartine          #+#    #+#             */
/*   Updated: 2018/02/22 12:10:55 by emartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "sort_alpha_handle.h"

int	sort_alpha(const void *current_data,
		size_t current_size, const void *child_data, size_t child_size)
{
	t_fs_handle		*current;
	t_fs_handle		*child;

	(void)current_size;
	(void)child_size;
	current = (t_fs_handle *)current_data;
	child = (t_fs_handle *)child_data;
	return (sort_alpha_handle(current, child));
}
