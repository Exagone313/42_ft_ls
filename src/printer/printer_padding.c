/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_padding.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 18:46:46 by emartine          #+#    #+#             */
/*   Updated: 2018/03/08 18:46:47 by emartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printer.h"

void	printer_padding(t_printer_handle *handle, size_t size,
		const t_padding *pad)
{
	size_t	i;

	if (pad->size < size)
		i = 0;
	else
		i = pad->size - size;
	while (i-- > 0)
		printer_char(handle, pad->ch);
}
