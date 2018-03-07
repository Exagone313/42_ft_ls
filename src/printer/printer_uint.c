/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_uint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 16:36:12 by emartine          #+#    #+#             */
/*   Updated: 2018/03/07 16:36:14 by emartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printer.h"

static size_t	nbr_length(unsigned int nbr)
{
	size_t	length;

	length = 1;
	while (nbr > 9)
	{
		length++;
		nbr /= 10;
	}
	return (length);
}

void			printer_uint(t_printer_handle *handle, unsigned int n)
{
	char	buffer[10];
	size_t	length;
	size_t	i;

	length = nbr_length(n);
	if (length > 10)
		return ;
	i = length;
	while (i--)
	{
		buffer[i] = '0' + n % 10;
		n /= 10;
	}
	printer_bin(handle, buffer, length);
}
