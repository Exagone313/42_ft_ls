/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filesystem_readargs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:57:55 by emartine          #+#    #+#             */
/*   Updated: 2018/02/26 14:57:57 by emartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filesystem.h"

void			filesystem_readargs(t_fs_tree *tree)
{
	filesystem_readtree_short(tree);
	filesystem_readtree_directory(tree);
	btree_clean(&(tree->tree));
}
