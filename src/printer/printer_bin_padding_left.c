/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_bin_padding_left.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 18:28:30 by emartine          #+#    #+#             */
/*   Updated: 2018/03/08 18:28:31 by emartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printer.h"

void	printer_bin_padding_left(t_printer_handle *handle, char *bin,
		size_t size, const t_padding pad)
{
	printer_padding(handle, size, &pad);
	printer_bin(handle, bin, size);
}
