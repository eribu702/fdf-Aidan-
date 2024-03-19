/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroberts <aroberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:55:12 by aroberts          #+#    #+#             */
/*   Updated: 2024/03/19 14:39:05 by aroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
get_map_width, takes char *line. this has within it one line
of data from our map file.
the map file contains numbers that have spaces in between them.
these numbers can range from negatives to double digits. we want to
count the data, which means -1, or 20, should both be treated as one
value of data. if we use something like strlen, we will be counting
10's as '1' and '0' 's. and spaces will add to the count, minus '-'
symbols also. instead we use split.
we create a char **split, which is an array of strings. so rather than
containing one string, it is like a string full of strings.
then we initalize i for incrementing. after a loop, we free **split,
and return i. we have effectively counted the data in line without
treating each single character as a piece of data.*/
static int	get_map_width(char *line)
{
	int		i;
	char	**split;

	split = ft_split(line, ' ');
	if (!split)
		return (-1);
	i = 0;
	while (split[i])
		i++;
	ft_free_split(split);
	return (i);
}

/*
in our function save_line_data, we save the data thats been retrieved by
our function read_map_file, that reads our fd (mapfile) in lines, sending them
through line by line. we take a string named line, this contains the line
of data to be saved. an int, width, that contains the expected width of the
data, this indicates the number of elements that should be in the line,
and a t_stack **data, a double pointer which not only allows us to modify
the 'data' value, but allows us to modify the pointer itself to the data
variable, so we can create a linked list.
we declare an int for incrementing, 'i'. and two char ** (an array of strings)
called split and values. because we have some values within our map function
that are not only seperated with spaces, but also with commas, we need to split
for both spaces and commas. our width value doesnt account for this though,
and to split these things up would require two calls of split, one for ' ' (space)
and one for ','. so, we split line by ' ' and set the result to **split.
we then check it for errors. after this we initialize i to 0, and and begin our loop.
split[i] does not refer to characters within the split string, but strings within
the split array. meaning split[0] will refer to the first character of the first string
and split[1] will refer to the first character of the second string.
while split[i] hasnt reached its final string, and while i < width.
then, we split[i] by ',' and set it to values. then we use our function
save_to_stack, with values and data, and check its result. if it fails,
we free our split and values chars and return false. otherwise, we just
free values, and increment. when this loop breaks, we free our split char,
and make sure that i matches width. and return false or true acordingly.
using our function this way, even though we split some values again, we
only increment i once per loop, meaning that i and width should match up
even if our file is littered with commas.*/
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
we then do another check for errors, and then return true.*/
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
