/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donlee <donlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 09:36:49 by donlee            #+#    #+#             */
/*   Updated: 2022/01/12 15:33:52 by donlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char const *src, size_t dstsize)
{
	size_t	dstl;
	size_t	srcl;
	size_t	result;

	srcl = 0;
	result = 0;
	dstl = ft_strlen(dst);
	while (src[result])
		result++;
	if (dstsize <= dstl)
	{
		return (result + dstsize);
	}
	else
		result += dstl;
	while (src[srcl] && dstl + 1 < dstsize)
	{
		dst[dstl] = src[srcl];
		dstl++;
		srcl++;
	}
	dst[dstl] = '\0';
	return (result);
}
