/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_etc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 22:14:26 by anda-cun          #+#    #+#             */
/*   Updated: 2024/01/19 18:59:10 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*open_cub(int fd)
{
	char	*line;

	if (fd < 0)
	{
		print_error("Error opening file", NULL);
		return (NULL);
	}
	line = get_next_line(fd);
	if (!line)
	{
		print_error("Empty file.", NULL);
		return (NULL);
	}
	return (line);
}

int check_xpm(t_data *data)
{
	int fd;

	fd = open(data->cardinal_image[NORTH].path, O_RDONLY);
	if (fd != -1)
		close(fd);
	else
		return (1);
	fd = open(data->cardinal_image[SOUTH].path, O_RDONLY);
	if (fd != -1)
		close(fd);
	else
		return (1);
	fd = open(data->cardinal_image[EAST].path, O_RDONLY);
	if (fd != -1)
		close(fd);
	else
		return (1);
	fd = open(data->cardinal_image[WEST].path, O_RDONLY);
	if (fd != -1)
		close(fd);
	else
		return (1);
	return(0);
}

int	check_extensions(t_data *data)
{
	if (check_xpm(data))
		return (print_error("Can't access xpm file.", NULL));
	if (check_ext(data->cardinal_image[NORTH].path, ".xpm"))
		return (print_error("Wrong file extension: ", data->cardinal_image[NORTH].path));
	if (check_ext(data->cardinal_image[SOUTH].path, ".xpm"))
		return (print_error("Wrong file extension: ", data->cardinal_image[SOUTH].path));
	if (check_ext(data->cardinal_image[WEST].path, ".xpm"))
		return (print_error("Wrong file extension: ", data->cardinal_image[WEST].path));
	if (check_ext(data->cardinal_image[EAST].path, ".xpm"))
		return (print_error("Wrong file extension: ", data->cardinal_image[EAST].path));
	return (0);
}