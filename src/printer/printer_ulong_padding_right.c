/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_ulong_padding_right.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 19:07:20 by emartine          #+#    #+#             */
/*   Updated: 2018/03/08 19:07:22 by emartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printer.h"

void	printer_ulong_padding_right(t_printer_handle *handle, unsigned long l,
		const t_padding pad)
{
	printer_ulong(handle, l);
	printer_padding(handle, printer_ulong_length(l), &pad);
}
