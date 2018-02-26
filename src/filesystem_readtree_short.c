/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filesystem_readtree_short.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 13:38:32 by emartine          #+#    #+#             */
/*   Updated: 2018/02/26 13:38:34 by emartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "filesystem.h"

static void	foreach_short(t_btree *node, void *param)
{
	t_fs_handle	*data;

	(void)param;
	data = (t_fs_handle	*)(node->data);
	write(1, data->filename, ft_strlen(data->filename));
	write(1, "\n", 1);
}

void		filesystem_readtree_short(t_btree *tree)
{
	btree_each(tree, foreach_short, 0);
}
