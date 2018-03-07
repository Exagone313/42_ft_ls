/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filesystem_savetree.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 16:36:19 by emartine          #+#    #+#             */
/*   Updated: 2018/03/06 16:36:21 by emartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filesystem.h"
#include "ft_ls_error.h"

/*
** If someday, lstat accepts paths bigger than PATH_MAX, problems will occur.
*/

void			filesystem_savetree(t_fs_tree *tree, char *arg, int hidden)
{
	t_fs_handle	hdl;
	t_btree		*child;

	if (lstat(arg, &(hdl.stat)) < 0)
		ft_ls_error(tree->state->argv0, arg);
	else
	{
		ft_strncpy(hdl.filepath, arg, PATH_MAX);
		hdl.hidden = hidden;
		child = btree_create(&hdl, sizeof(hdl));
		if (!(tree->tree))
			tree->tree = child;
		else
			btree_add(tree->tree, child, tree->state->sort);
		if (child)
			tree->length++;
	}
}
