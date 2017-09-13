/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkhosa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 13:08:26 by wkhosa            #+#    #+#             */
/*   Updated: 2017/09/13 18:01:34 by wkhosa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int		main(int argc, char **argv)
{
	char	*line;
	int		index;
	int		fd;

	if (!(line = ft_strnew(1)) || !(line = ft_strnew(100)))
	{
		ft_putendl("failed to allocate memory in main line 23");
		return (0);
	}
	if (argc > 1)
	{
		index = 1;
		while (index < argc)
		{
			if ((fd = open(argv[index], O_RDONLY)) == -1)
			{
				ft_putstr("Failed to open file --");
				ft_putstr(argv[index]);
				ft_putendl("-- please check if it exist");
				return (0);
			}
			get_next_line(fd, &line);
		//	while (get_next_line(fd, &line))
				ft_putendl(line);
			index++;
		}
		return (1);
	}
	ft_putendl("No argument was entered program exit >>>");
	return (1);
}
