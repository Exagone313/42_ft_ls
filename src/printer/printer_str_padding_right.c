/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_str_padding_right.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 19:06:37 by emartine          #+#    #+#             */
/*   Updated: 2018/03/08 19:06:38 by emartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printer.h"

void	printer_str_padding_right(t_printer_handle *handle, char *str,
		const t_padding pad)
{
	printer_bin_padding_right(handle, str, ft_strlen(str), pad);
}
