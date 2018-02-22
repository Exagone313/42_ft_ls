/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 13:34:29 by emartine          #+#    #+#             */
/*   Updated: 2018/02/22 13:34:31 by emartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "main.h"

t_btree_cmp	sort_func(int params)
{
	if (params & PARAM_SORT_REVERSE)
	{
		if (params & PARAM_SORT_MTIME)
			return (sort_mtime_reverse);
		return (sort_alpha_reverse);
	}
	if (params & PARAM_SORT_MTIME)
		return (sort_mtime);
	return (sort_alpha);
}
