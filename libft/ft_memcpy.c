/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donlee <donlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 09:36:21 by donlee            #+#    #+#             */
/*   Updated: 2022/01/15 14:33:50 by donlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*paste;
	unsigned char	*copy;
	size_t			i;

	i = 0;
	if (n == 0)
		return (dest);
	if (!dest && !src)
		return (NULL);
	paste = (unsigned char *) dest;
	copy = (unsigned char *) src;
	while (i < n)
	{
		paste[i] = copy[i];
		i++;
	}
	return (dest);
}
