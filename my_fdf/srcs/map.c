/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroberts <aroberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:55:12 by aroberts          #+#    #+#             */
/*   Updated: 2024/02/20 15:03:08 by aroberts         ###   ########.fr       */
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
	ft_free(&line);
	if ((map->width && map->height) <= 0)
		return (false);
	return (true);
}
