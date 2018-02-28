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

int			sort_alpha_handle(t_fs_handle *current, t_fs_handle *child)
{
	return (ft_strcmp(current->filepath, child->filepath));
}
