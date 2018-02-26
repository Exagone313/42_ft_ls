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
	char		*argv0; // FIXME
	int			params; // FIXME
	t_btree		*tree;
	t_btree_cmp	sort;
	int			column_links; // are column fields really needed
	int			column_user;
	int			column_group;
	int			column_size;
}				t_fs_tree;

typedef struct	s_fs_handle
{
	char		*path_prefix; // FIXME
	char		*filename;
	struct stat	stat;
}				t_fs_handle;

typedef struct	s_args_tree
{
	char		*argv0;
	int			params;
	t_btree		*tree;
	t_btree_cmp	sort;
	int			length;
}				t_args_tree;

/*
** une fonction long, une fonction short, qui prennent un arbre de
** t_fs_handle en argument
*/
void			filesystem_readtree_short(t_btree *tree);
void			filesystem_readtree_long(t_btree *tree);
/*
** une fonction qui rajoute le nom sur une ligne prefixe, utilise long ou short
** le prefixe est ajoute uniquement pour les dossiers ...
*/
void			filesystem_readtree_prefix(t_fs_tree *tree);
/*
** une fonction qui lit le fichier ou dossier, cree l'arbre et appelle
** une des fonctions du dessus, puis reparcours l'arbre pour lire recursivement
** les dossiers si besoin
** FIXME
*/
void			filesystem_readpath(char *argv0, int params, char *target);
/*
** init tree of arguments
*/
void			filesystem_initargs(t_args_tree *tree, char *argv0, int params);
/*
** creates a tree of arguments
*/
void			filesystem_savearg(t_args_tree *tree, char *arg);
/*
** takes a tree of arguments and do the job
*/
void			filesystem_readargs(t_args_tree *tree);

#endif
