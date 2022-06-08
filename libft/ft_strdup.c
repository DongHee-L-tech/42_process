/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donlee <donlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 09:26:05 by donlee            #+#    #+#             */
/*   Updated: 2022/01/15 14:28:30 by donlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*copy;
	int		len;
	int		i;

	len = ft_strlen(s);
	i = 0;
	copy = malloc(sizeof(char) * len + 1);
	if (!copy)
		return (NULL);
	while (s[i])
	{	
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
