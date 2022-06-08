/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donlee <donlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 06:42:56 by donlee            #+#    #+#             */
/*   Updated: 2022/04/04 12:08:23 by donlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int nbr, char form)
{
	char	*base;
	int		res;

	res = 0;
	if (form == 'x')
		base = "0123456789abcdef";
	if (form == 'X')
		base = "0123456789ABCDEF";
	if (nbr >= 16)
		res += ft_print_hex(nbr / 16, form);
	res += ft_print_char(base[nbr % 16]);
	base = NULL;
	return (res);
}

int	ft_print_ptr(void *ptr)
{
	size_t	point;
	char	*base;
	int		res;

	point = (size_t)ptr;
	res = 0;
	base = "0123456789abcdef";
	if (point >= 16)
		res += ft_print_ptr((void *)(point / 16));
	res += ft_print_char(base[point % 16]);
	base = NULL;
	return (res);
}
