/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_bin_padding_right.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 18:32:33 by emartine          #+#    #+#             */
/*   Updated: 2018/03/08 18:32:35 by emartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printer.h"

void	printer_bin_padding_right(t_printer_handle *handle, char *bin,
		size_t size, const t_padding pad)
{
	printer_bin(handle, bin, size);
	printer_padding(handle, size, &pad);
}
