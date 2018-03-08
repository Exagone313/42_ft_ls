/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_int_padding_right.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 19:07:00 by emartine          #+#    #+#             */
/*   Updated: 2018/03/08 19:07:01 by emartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printer.h"
#include "printer_private.h"

void	printer_int_padding_right(t_printer_handle *handle, int n,
		const t_padding pad)
{
	printer_int(handle, n);
	printer_padding(handle, printer_int_length(n), &pad);
}
