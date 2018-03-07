/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 15:29:40 by emartine          #+#    #+#             */
/*   Updated: 2018/03/07 15:29:41 by emartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printer.h"

void	printer_init(t_printer_handle *handle, int fd)
{
	handle->fd = fd;
	handle->length = 0;
	handle->buffer[0] = '\0';
	handle->buffer[PRINTER_BUFFER_SIZE] = '\0';
}
