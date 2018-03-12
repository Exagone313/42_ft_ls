/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_long_padding_left.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 19:08:13 by emartine          #+#    #+#             */
/*   Updated: 2018/03/08 19:08:15 by emartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printer.h"

void	printer_long_padding_left(t_printer_handle *handle, long l,
		const t_padding pad)
{
	printer_padding(handle, printer_long_length(l), &pad);
	printer_long(handle, l);
}
