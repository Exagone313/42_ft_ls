/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filesystem.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 11:23:49 by emartine          #+#    #+#             */
/*   Updated: 2018/02/22 11:23:51 by emartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILESYSTEM_H
# define FILESYSTEM_H

# include <sys/stat.h>
# include "btree/btree.h"

/*
** tree is a pointer to a binary tree of s_fs_handle,
** sorted by the function sort
** column_* are the maximum lengths for each column, used for long format
*/

typedef struct	s_fs_tree
{
	t_btree		*tree;
	t_btree_cmp	sort;
	int			column_links;
	int			column_user;
	int			column_group;
	int			column_size;
}				t_fs_tree;

typedef struct	s_fs_handle
{
	char		*path_prefix;
	char		*filename;
	struct stat	stat;
}				t_fs_handle;

#endif
