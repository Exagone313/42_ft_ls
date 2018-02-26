/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filesystem_savearg.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:57:39 by emartine          #+#    #+#             */
/*   Updated: 2018/02/26 14:57:41 by emartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include "filesystem.h"
#include "ft_ls_error.h"

void			filesystem_savearg(t_args_tree *tree, char *arg)
{
	t_fs_handle	hdl;
	t_btree		*child;

	if (lstat(arg, &(hdl.stat)) < 0)
		ft_ls_error(tree->argv0, arg);
	else
	{
		hdl.path_prefix = 0;
		// TODO prefix??
		hdl.filename = arg;
		child = btree_create(&hdl, sizeof(hdl));
		if (!(tree->tree))
			tree->tree = child;
		else
			btree_add(tree->tree, child, tree->sort);
	}
}
