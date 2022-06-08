/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donlee <donlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:46:54 by donlee            #+#    #+#             */
/*   Updated: 2022/04/04 12:12:30 by donlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_print_str("(null)"));
	else
	{
		while (str[i] != '\0')
		{
			ft_print_char(str[i]);
			i++;
		}
		return (i);
	}
}

int	ft_print_nbr(int nbr)
{
	int	res;

	res = 0;
	if (nbr == -2147483648)
	{
		return (write(1, "-2147483648", 11));
	}
	if (nbr < 0)
	{
		nbr *= -1;
		write(1, "-", 1);
		res++;
	}
	if (nbr >= 10)
		res += ft_print_nbr(nbr / 10);
	res += ft_print_char(nbr % 10 + '0');
	return (res);
}

int	ft_print_unsign(unsigned int nbr)
{
	int	res;

	res = 0;
	if (nbr >= 10)
		res += ft_print_unsign(nbr / 10);
	res += ft_print_char(nbr % 10 + '0');
	return (res);
}
