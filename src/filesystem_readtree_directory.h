/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filesystem_readtree_directory.h                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 18:35:38 by emartine          #+#    #+#             */
/*   Updated: 2018/03/06 18:35:42 by emartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILESYSTEM_READTREE_DIRECTORY_H
# define FILESYSTEM_READTREE_DIRECTORY_H

/*
** local header
*/

static void	foreach_directory(t_btree *node, void *param);
static void	foreach_directory_prefix(t_btree *node, void *param);

#endif
