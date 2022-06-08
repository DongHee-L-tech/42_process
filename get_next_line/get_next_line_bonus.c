/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donlee <donlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 14:52:43 by donlee            #+#    #+#             */
/*   Updated: 2022/05/09 13:16:01 by donlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*pre_next_line(char *buff)
{
	char	*next_line;
	int		buff_len;
	int		i;

	i = 0;
	buff_len = ft_strlen(buff);
	while (buff[i])
	{
		if (buff[i] == '\n')
		{
			next_line = ft_substr(buff, i + 1, buff_len - i - 1);
			free (buff);
			return (next_line);
		}
		i++;
	}
	free(buff);
	return (NULL);
}

char	*take_line(char *buff)
{
	int		i;
	char	*line;

	i = 0;
	if (!buff[0])
		return (NULL);
	while (buff[i] && buff[i] != '\n')
		i++;
	line = ft_substr(buff, 0, i + 1);
	return (line);
}

char	*read_buff(int fd, char *buff)
{
	int		read_value;
	char	*temp;

	temp = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	read_value = 1;
	while (!ft_strchr(buff, '\n') && read_value)
	{
		read_value = read(fd, temp, BUFFER_SIZE);
		if (read_value == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[read_value] = '\0';
		buff = ft_strjoin(buff, temp);
	}
	free (temp);
	return (buff);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buff [MAX];

	if (fd < 0 || fd > MAX || BUFFER_SIZE <= 0)
		return (NULL);
	buff[fd] = read_buff(fd, buff[fd]);
	if (!buff[fd])
		return (NULL);
	line = take_line(buff[fd]);
	buff[fd] = pre_next_line(buff[fd]);
	return (line);
}
