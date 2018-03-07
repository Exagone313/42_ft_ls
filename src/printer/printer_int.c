/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 16:17:22 by emartine          #+#    #+#             */
/*   Updated: 2018/03/07 16:17:24 by emartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printer.h"

static size_t	nbr_length(int nbr)
{
	size_t	length;

	length = nbr < 0 ? 2 : 1;
	while (nbr < -9 || nbr > 9)
	{
		length++;
		nbr /= 10;
	}
	return (length);
}

void			printer_int(t_printer_handle *handle, int n)
{
	char	buffer[6];
	char	*bufferptr;
	size_t	length;
	size_t	i;

	length = nbr_length(n);
	if (length > 6)
		return ;
	i = length;
	bufferptr = (char *)buffer;
	if (n < 0)
	{
		*(bufferptr++) = '-';
		i--;
	}
	while (i--)
	{
		bufferptr[i] = '0' + (n < 0 ? -(n % 10) : n % 10);
		n /= 10;
	}
	printer_bin(handle, buffer, length);
}
