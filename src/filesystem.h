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
*/

typedef struct	s_fs_tree
{
	char		*argv0;
	int			params;
	t_btree		*tree;
	t_btree_cmp	sort;
	int			length;
	int			args_tree;
}				t_fs_tree;

typedef struct	s_fs_handle
{
	char		*filepath;
	struct stat	stat;
}				t_fs_handle;

/*
** init tree of arguments
*/
void			filesystem_initargs(t_fs_tree *tree, char *argv0, int params);
/*
** create a tree of arguments
*/
void			filesystem_savearg(t_fs_tree *tree, char *arg);
/*
** take a tree of arguments and do the job
*/
void			filesystem_readargs(t_fs_tree *tree);

/*
** read directories in a tree and adds prefix when necessary
*/
void			filesystem_readtree_directory(t_fs_tree *tree);
/*
** list files with short format
*/
void			filesystem_readtree_short(t_fs_tree *tree);
/*
** list files with long format
*/
void			filesystem_readtree_long(t_fs_tree *tree);

#endif
