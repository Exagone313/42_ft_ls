/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_long_padding_right.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 19:08:18 by emartine          #+#    #+#             */
/*   Updated: 2018/03/08 19:08:19 by emartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printer.h"
#include "printer_private.h"

void	printer_long_padding_right(t_printer_handle *handle, long l,
		const t_padding pad)
{
	printer_long(handle, l);
	printer_padding(handle, printer_long_length(l), &pad);
}
