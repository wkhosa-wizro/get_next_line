/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkhosa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 13:07:23 by wkhosa            #+#    #+#             */
/*   Updated: 2017/09/13 18:01:29 by wkhosa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen_to_c(char const *s, char const c)
{
	size_t	len;

	len = 0;
	if (ft_strchr(s, c) == NULL)
		return (ft_strlen(s));
	while (*s != c)
	{
		s++;
		len++;
	}
	return (len);
}

void	reset(char **s)
{
	char	*temp;
	size_t	len;

	temp = ft_strchr(*s, '\n');
	if (temp == NULL)
		return ;
	else
	{
		temp++;
		len = ft_strlen(temp);
		ft_memmove(*s, temp, len);
	}
}

int		get_next_line(const int fd, char **line)
{
	static	char	*temp = NULL;
	char			*buffer;
	int				byts_read;
	
	if (!(buffer = ft_strnew(BUFF_SIZE)))
		return (-1);
	byts_read = read(fd, buffer, BUFF_SIZE);
	buffer[byts_read] = '\0';
	if (temp == NULL)
	{
		if (!(temp = ft_strnew(2 * BUFF_SIZE)))
			return (-1);
		temp[0] = '\0';
	}
	ft_strcat(temp,buffer);
	ft_strcat(*line, temp);
	while (!(ft_strchr(temp, '\n')))
	{
//		ft_putstr(">>>> line ");
//		ft_putendl(*line);
		byts_read = read(fd, buffer, BUFF_SIZE);	
		buffer[byts_read] = '\0';
		ft_strcpy(temp, buffer);
		ft_strncat(*line, temp, ft_strlen_to_c(temp, '\n'));
		if (byts_read == 0)
		{
			reset(&temp);
			return (0);
		}
	}
	reset(&temp);
	return (1);
}
