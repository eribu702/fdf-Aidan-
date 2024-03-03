/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroberts <aroberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:32:37 by lmells            #+#    #+#             */
/*   Updated: 2024/02/12 16:59:27 by aroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
 * 	Gets the map width from the first line read from file.
 * 		Split the line by whitespace ' ' to get all seperate values.
 * 		Loop through each block from split array and increment width.
 * 		Free the split array and return the width.
 */
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
	free_split(split);
	return (width);
}

/*
 * 	Saves data from line and pushes values to stack.
 * 		Split line to get each block of values.
 * 		Trim off the '\n' character to avoid unwanted values.
 * 		Split index value from ',' seperator. This will give us a colour code if
 * 		map spcifies colour for its 'z' coordinates.
 * 		Check if push to stack function succeeds.
 * 		Upon failure, Free both split arrays and return failure.
 * 		Success, frees the split values from index, continue loop.
 */
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
			free_split(values);
			free_split(split);
			return (false);
		}
		free_split(values);
		i++;
	}
	free_split(split);
	if (i != width)
		return (false);
	return (true);
}

/*
 * 	Gets and stores map data from file.
 * 		Get width from function after first read.
 * 		Get height from looping through file, each new-line '\n' increments the
 * 		height.
 * 		After each read of a new line, The data is pushed onto a stack.
 * 		Check the width and height are valid.
 * 		Returns (1) on Success, (0) on Failure.
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
			terminate(gen_error_msg(ERR_MSG, INIT), 1);
		map->height++;
		ft_free(&line);
		line = read_map_file(fd);
	}
	close(fd);
	ft_free(&line);
	if ((map->width && map->height) <= 0)
		return (false);
	return (true);
}
