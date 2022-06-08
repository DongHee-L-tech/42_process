/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donlee <donlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:46:42 by donlee            #+#    #+#             */
/*   Updated: 2022/04/04 13:07:57 by donlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_form(va_list ap, const char form)
{
	int		res;

	res = 0;
	if (form == 'c')
		res += ft_print_char(va_arg(ap, int));
	else if (form == 's')
		res += ft_print_str(va_arg(ap, char *));
	else if (form == 'p')
		res += (ft_print_str("0x") + ft_print_ptr(va_arg(ap, void *)));
	else if (form == 'd' || form == 'i')
		res += ft_print_nbr(va_arg(ap, int));
	else if (form == 'u')
		res += ft_print_unsign(va_arg(ap, unsigned int));
	else if (form == 'x' || form == 'X')
		res += ft_print_hex(va_arg(ap, unsigned int), form);
	else if (form == '%')
		res += ft_print_char('%');
	return (res);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		res;

	i = 0;
	res = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
			res += ft_parse_form(ap, format[++i]);
		else
			res += write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (res);
}
