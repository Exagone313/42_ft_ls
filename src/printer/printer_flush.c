/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_flush.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 15:16:25 by emartine          #+#    #+#             */
/*   Updated: 2018/03/07 15:16:26 by emartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <errno.h>
#include "printer.h"

void	printer_flush(t_printer_handle *handle)
{
	size_t	i;
	ssize_t	r;

	if (handle->length > 0)
	{
		i = 0;
		while (i < handle->length)
		{
			r = write(handle->fd, handle->buffer + i, handle->length - i);
			if (r == 0
					|| (r == -1 && (errno != EAGAIN && errno != EWOULDBLOCK)))
				break ;
			i += r;
		}
		handle->length = 0;
	}
}
