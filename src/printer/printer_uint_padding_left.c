/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_uint_padding_left.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 19:07:31 by emartine          #+#    #+#             */
/*   Updated: 2018/03/08 19:07:32 by emartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printer.h"

void	printer_uint_padding_left(t_printer_handle *handle, unsigned int n,
		const t_padding pad)
{
	printer_padding(handle, printer_uint_length(n), &pad);
	printer_uint(handle, n);
}
