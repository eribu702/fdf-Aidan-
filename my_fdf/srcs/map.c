/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroberts <aroberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:55:12 by aroberts          #+#    #+#             */
/*   Updated: 2024/03/05 10:44:21 by aroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	get_map_width(char *line)
{
	int		i;
	int		width;
	char	**split;

	width = 0;
	split = ft_split(line, ' ');
	if (!split)
		return (-1);
	i = 0;
	while (split[i])
	{
		width++;
		i++;
	}
	ft_free_split(split);
	return (width);
}

static bool	save_line_data(char *line, int width, t_stack **data)
{
	int		i;
	char	**split;
	char	**values;

	split = ft_split(line, ' ');
	if (!split)
		return (false);
	i = 0;
	while (split[i] && i < width)
	{
		values = ft_split(split[i], ',');
		if (!save_to_stack(values, data))
		{
			ft_free_split(values);
			ft_free_split(split);
			return (false);
		}
		ft_free_split(values);
		i++;
	}
	ft_free_split(split);
	if (i != width)
		return (false);
	return (true);
}

/*
our function, parse_map, reads the data from our t_map structure,
'map', and saves it to our t_stack structure, 'data'.
we initalize an int fd (file descriptor), and a char *line, that
we will use to get the data from the map file in a char *.
we use open() with a readonly flag to open map->file. we assign
this filedescriptor to fd, and check for errors.
after, we assign line to read_map_file(fd). after this we assign
map-> width to the width of the map, and height to 0, as we will
be incrementing down lines to structure our data.
while (line != '\0') we:
- save_line_data with (line and map-> width.) we use a check
to make sure this works, otherwise it will give us an error message.
we then take map->height and increment it, going down one line.
then we free (&line) and use read_map_file to save the nect line.
we continue doing this until our code meents a null and finishes.
we then close our file descriptor, and free our line. we check if (line) just in
case the while loop closed somehow before it reached the end of the map (fd).
we then do another check for errors, and then return true.

*/
bool	parse_map(t_map *map, t_stack **data)
{
	int		fd;
	char	*line;

	fd = open(map->file, O_RDONLY);
	if (fd <= 0)
		return (false);
	line = read_map_file(fd);
	map->width = get_map_width(line);
	map->height = 0;
	while (line)
	{
		if (!save_line_data(line, map->width, data))
			terminate(gen_error_msg(ERR, INIT), 1);
		map->height++;
		ft_free(&line);
		line = read_map_file(fd);
	}
	close(fd);
	if (line)
		ft_free(&line);
	if ((map->width && map->height) <= 0)
		return (false);
	return (true);
}
