/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 14:14:50 by emartine          #+#    #+#             */
/*   Updated: 2018/03/07 14:14:54 by emartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTER_H
# define PRINTER_H

# include <limits.h>
# include <stdlib.h>

# define PRINTER_BUFFER_SIZE PIPE_BUF

typedef struct	s_printer_handle
{
	int			fd;
	char		buffer[PRINTER_BUFFER_SIZE + 1];
	size_t		length;
}				t_printer_handle;

/*
** initialize pointed struct
*/
void			printer_init(t_printer_handle *handle, int fd);
/*
** flush buffer (required to ensure output)
*/
void			printer_flush(t_printer_handle *handle);

/*
** functions used to print and/or add to buffer the following types
*/
void			printer_str(t_printer_handle *handle, char *str);
void			printer_bin(t_printer_handle *handle, char *bin, size_t size);
void			printer_int(t_printer_handle *handle, int n);
void			printer_uint(t_printer_handle *handle, unsigned int n);
void			printer_long(t_printer_handle *handle, long l);
void			printer_ulong(t_printer_handle *handle, unsigned long l);
void			printer_char(t_printer_handle *handle, char ch);
void			printer_endl(t_printer_handle *handle);

/*
** functions that add spaces before or after the following types (padding)
** pad is the total number of characters that will be output by the function
**
** padding left or right means that spaces are added respectively before
** or after the second parameter value to output pad characters
**
** the second parameter value is expected to fit in the padding
*/
void			printer_str_padding_left(t_printer_handle *handle, char *str,
		size_t pad);
void			printer_bin_padding_left(t_printer_handle *handle, char *bin,
		size_t size, size_t pad);
void			printer_int_padding_left(t_printer_handle *handle, int n,
		size_t pad);
void			printer_uint_padding_left(t_printer_handle *handle,
		unsigned int n, size_t pad);
void			printer_long_padding_left(t_printer_handle *handle, long l,
		size_t pad);
void			printer_ulong_padding_left(t_printer_handle *handle,
		unsigned long l, size_t pad);

void			printer_str_padding_right(t_printer_handle *handle, char *str,
		size_t pad);
void			printer_bin_padding_right(t_printer_handle *handle, char *bin,
		size_t size, size_t pad);
void			printer_int_padding_right(t_printer_handle *handle, int n,
		size_t pad);
void			printer_uint_padding_right(t_printer_handle *handle,
		unsigned int n, size_t pad);
void			printer_long_padding_right(t_printer_handle *handle, long l,
		size_t pad);
void			printer_ulong_padding_right(t_printer_handle *handle,
		unsigned long l, size_t pad);

#endif
