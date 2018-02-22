/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 11:10:48 by emartine          #+#    #+#             */
/*   Updated: 2018/02/22 11:10:52 by emartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "filesystem.h"
# include "btree/btree.h"

int			sort_alpha(const void *current_data,
		size_t current_size, const void *child_data, size_t child_size);
int			sort_alpha_reverse(const void *current_data,
		size_t current_size, const void *child_data, size_t child_size);
int			sort_mtime(const void *current_data,
		size_t current_size, const void *child_data, size_t child_size);
int			sort_mtime_reverse(const void *current_data,
		size_t current_size, const void *child_data, size_t child_size);
t_btree_cmp	sort_func(int params);

#endif
