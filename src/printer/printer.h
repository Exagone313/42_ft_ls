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

# define PRINTER_BUFFER_SIZE 4096

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
** functions that add a certain number of t_padding.ch characters
** before or after the following types (padding)
**
** t_padding.size is the total number of characters that will be output by
** the function
**
** padding left or right means that the t_padding.ch characters are added
** respectively before or after the value
**
** the value is expected to fit in the padding
*/
typedef struct	s_padding
{
	size_t		size;
	char		ch;
}				t_padding;

void			printer_str_padding_left(t_printer_handle *handle, char *str,
		const t_padding pad);
void			printer_bin_padding_left(t_printer_handle *handle, char *bin,
		size_t size, const t_padding pad);
void			printer_int_padding_left(t_printer_handle *handle, int n,
		const t_padding pad);
void			printer_uint_padding_left(t_printer_handle *handle,
		unsigned int n, const t_padding pad);
void			printer_long_padding_left(t_printer_handle *handle, long l,
		const t_padding pad);
void			printer_ulong_padding_left(t_printer_handle *handle,
		unsigned long l, const t_padding pad);

void			printer_str_padding_right(t_printer_handle *handle, char *str,
		const t_padding pad);
void			printer_bin_padding_right(t_printer_handle *handle, char *bin,
		size_t size, const t_padding pad);
void			printer_int_padding_right(t_printer_handle *handle, int n,
		const t_padding pad);
void			printer_uint_padding_right(t_printer_handle *handle,
		unsigned int n, const t_padding pad);
void			printer_long_padding_right(t_printer_handle *handle, long l,
		const t_padding pad);
void			printer_ulong_padding_right(t_printer_handle *handle,
		unsigned long l, const t_padding pad);

/*
** internal functions
*/

/*
** numeric types length
*/
size_t			printer_int_length(int nbr);
size_t			printer_uint_length(unsigned int nbr);
size_t			printer_long_length(long nbr);
size_t			printer_ulong_length(unsigned long nbr);

/*
** show padding
**
** (t_padding.size - size) t_padding.ch characters are output
*/
void			printer_padding(t_printer_handle *handle, size_t size,
		const t_padding *pad);

#endif
