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
# include <limits.h>
# include <dirent.h>
# include "btree/btree.h"
# include "printer/printer.h"

typedef struct			s_ls_state
{
	char				*argv0;
	int					params;
	t_btree_cmp			sort;
	t_printer_handle	stdout;
	t_printer_handle	stderr;
	int					double_endl_prefix;
	int					arg_error;
}						t_ls_state;

/*
** tree is a pointer to a binary tree of s_fs_handle,
** sorted by the function sort
*/
typedef struct			s_fs_tree
{
	t_ls_state			*state;
	t_btree				*tree;
	int					length;
	int					level;
}						t_fs_tree;

typedef struct			s_fs_handle
{
	char				filepath[PATH_MAX + 1];
	struct stat			stat;
	int					hidden;
}						t_fs_handle;

/*
** init tree of arguments
*/
void					filesystem_initargs(t_fs_tree *tree, t_ls_state *state);
/*
** take a tree of arguments and do the job
*/
void					filesystem_readargs(t_fs_tree *tree);

/*
** create a tree of files
*/
void					filesystem_savetree(t_fs_tree *tree, char *arg,
		int hidden);
/*
** read directories in a tree and adds prefix when necessary
*/
void					filesystem_readtree_directory(t_fs_tree *tree);
void					filesystem_subtree(t_fs_tree *subtree, t_fs_tree *tree,
		t_fs_handle *data, DIR *dir);
/*
** list files with short format
*/
void					filesystem_readtree_short(t_fs_tree *tree);
/*
** list files with long format
*/
void					filesystem_readtree_long(t_fs_tree *tree);
typedef struct			s_ls_long
{
	t_fs_tree			*tree;
	size_t				total;
	size_t				max_links;
	size_t				max_user_length;
	size_t				max_group_length;
	size_t				max_size;
}						t_ls_long;
/*
** check if file is hidden
*/
int						filesystem_hidden(int params, char *filename);

#endif
