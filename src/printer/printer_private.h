/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_private.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 19:14:25 by emartine          #+#    #+#             */
/*   Updated: 2018/03/08 19:14:26 by emartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTER_PRIVATE_H
# define PRINTER_PRIVATE_H

/*
** internal functions
*/

# include "printer.h"

/*
** numeric types length
*/
size_t	printer_int_length(int nbr);
size_t	printer_uint_length(unsigned int nbr);
size_t	printer_long_length(long nbr);
size_t	printer_ulong_length(unsigned long nbr);

/*
** show padding
**
** (t_padding.size - size) t_padding.ch characters are output
*/
void	printer_padding(t_printer_handle *handle, size_t size,
		const t_padding *pad);

#endif
