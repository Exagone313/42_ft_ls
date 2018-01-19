/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_itoan.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 21:49:12 by emartine          #+#    #+#             */
/*   Updated: 2018/01/17 21:49:14 by emartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_itoan.h"

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

size_t			ft_ls_itoan(int nbr, char *buffer, size_t n)
{
	size_t	length;
	size_t	i;

	length = nbr_length(nbr);
	if (length > n)
		return (0);
	i = length;
	if (nbr < 0)
	{
		*(buffer++) = '-';
		i--;
	}
	while (i--)
	{
		buffer[i] = '0' + (nbr < 0 ? -(nbr % 10) : nbr % 10);
		nbr /= 10;
	}
	return (length);
}
