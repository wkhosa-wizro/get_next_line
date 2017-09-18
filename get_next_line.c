/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkhosa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 13:07:23 by wkhosa            #+#    #+#             */
/*   Updated: 2017/09/18 18:05:59 by wkhosa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
int		get_next_line(int const fd, char **line)
{
//	return (-1);

	if (buff is not initialised)
		initialise buff

	initialise temp

	nbyte = read(fd, temp, BUFF_SIZE);
	{
		ft_strcat(buff, temp);
		nbyte < BUFF_SIZE;
		{
			take data from buff up to endl or newl to line
				if (newl comes before endl)
					shift data in buff
					return (1)
				else
					free buff
			return (0)
		}
		nbyte == BUFF_SIZE;
		{
			take data from buff up to newl or endl to line
				if (newl comes before endl)
					shift data in buff
					return (1);
				else
					free buff
					gnl
				return (1)
		}
		nbyte == 0;
		{
			take data from buff to line
			free buff
			return (0)
		}
	}
	return (0)
}
*/

#include <stdio.h>

int		get_next_line(int const fd, char **line)
{
	static	char	*buff = NULL;
	char			*temp;
	int				nbyte;

	if (!(buff))
	{
		if (!(buff = ft_strnew(2 * BUFF_SIZE))) 
			return (-1);
	//	printf(">>> buff initialising buff = %s\n", buff);
	}
	if (!(temp = ft_strnew(BUFF_SIZE)) || fd < 0)
		return (-1);
	ft_strclr(*line);
	while ((nbyte = read(fd, temp, BUFF_SIZE)) > 0)
	{
		temp[nbyte] = '\0';
	//	printf("#1>>> nbyte = %d, temp = %s '\n", nbyte, temp);
		if (ft_strchr(ft_strcat(buff , temp), '\n'))
		{
	//		printf("#2>>> buff = %s, temp = %s '\n", buff, temp);
			ft_strdel(&temp);
		//	ft_strclr(*line);
			temp = ft_strsub(buff, 0, ft_strchr(buff, '\n') - buff + 1);
	//		printf("#3>>> buff = %s, temp = %s '\n", buff, temp);
			ft_memmove(buff, ft_strchr(buff, '\n') + 1, ft_strlen(ft_strchr(buff, '\n')) + 1);
	//		printf("#4>>> line = %s  buff = %s, temp = %s '\n", *line, buff, temp);
			ft_strncat(*line, temp, ft_strchr(temp, '\n') - temp);
	//		printf("#5>>> line = %s  buff = %s, temp = %s '\n", *line, buff, temp);
			return (1);
		}
	//		printf("#6>>> line = %s  buff = %s, temp = %s '\n", *line, buff, temp);
		ft_strcat(*line, buff);
		ft_strclr(buff);
	//		printf("#7>>> line = %s  buff = %s, temp = %s '\n", *line, buff, temp);
	}
	//		printf("#8>>> line = %s  buff = %s, temp = %s '\n", *line, buff, temp);
	return (0);
}
