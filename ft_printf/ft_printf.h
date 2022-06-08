/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donlee <donlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:48:08 by donlee            #+#    #+#             */
/*   Updated: 2022/04/04 13:09:16 by donlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_parse_form(va_list ap, const char form);
int	ft_print_char(int c);
int	ft_print_str(char *str);
int	ft_print_nbr(int nbr);
int	ft_print_unsign(unsigned int nbr);
int	ft_print_hex(unsigned int nbr, char form);
int	ft_print_ptr(void *ptr);

#endif
