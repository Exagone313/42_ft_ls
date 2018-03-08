/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_str_padding_left.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 19:06:30 by emartine          #+#    #+#             */
/*   Updated: 2018/03/08 19:06:31 by emartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printer.h"

void	printer_str_padding_left(t_printer_handle *handle, char *str,
		const t_padding pad)
{
	printer_bin_padding_left(handle, str, ft_strlen(str), pad);
}
