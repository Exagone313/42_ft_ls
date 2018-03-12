/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_int_padding_left.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 19:06:51 by emartine          #+#    #+#             */
/*   Updated: 2018/03/08 19:06:52 by emartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printer.h"

void	printer_int_padding_left(t_printer_handle *handle, int n,
		const t_padding pad)
{
	printer_padding(handle, printer_int_length(n), &pad);
	printer_int(handle, n);
}
