/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroberts <aroberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:19:48 by aroberts          #+#    #+#             */
/*   Updated: 2024/03/19 16:53:32 by aroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static char	*update_buffer(char **buffer, int pos)
{
	char	*tmp;
	int		len;

	len = ft_strlen(*buffer) - pos;
	tmp = ft_strndup(*buffer + pos, len);
	free (*buffer);
	*buffer = tmp;
	return (*buffer);
}

static char	*check_update_output(char **buffer, int pos, int bytes)
{
	char	*output;

	if ((!*buffer && bytes <= 0) || pos == -5)
	{
		if (*buffer)
			return (*buffer);
		return (NULL);
	}
	output = NULL;
	if (pos == -1)
		pos = ft_strnlen (*buffer);
	else
		pos++;
	output = ft_strndup(*buffer, pos);
	if (pos == ft_strlen(*buffer))
		ft_free(buffer);
	else
		*buffer = update_buffer(buffer, pos);
	return (output);
}

/*
our function read map file, takes a file descritpor that stores a map file.
it converts the file descriptor to a char *.
first we initilize and int, bytes, which we will use to count the amount of data
that has been 'read'. pos, which will hold the position of the next '\n' character.
a char pointer that will be able to store chunks of our file at a time. and a 
static char * that will accumulate the contents of our file.
we first check that the file descriptor is valid and that BUFFER_SIZE is not
<= 0. if these are true we return NULL. we initalize bytes and read_buff,
and then we use a function named ft_strchr_flag() to find the first '\n'
in buffer and set that to an interger called 'pos'.
strchr_flag uses a flag system, this avoids problems in how our function
reads our file descriptor. the first time we use it, it has the flag 0,
it now operates as the normal strchr() function.
we begin the while loop while pos == -1 or while its == to -5.
-1 is the return value of strchr when it has failed to find a '\n' in
its string. this string's size is determined by BUFFER_SIZE which is a
fixed variable set in fdf.h.
our first step in the while loop is to allocate memory to read buff.
we give it the size of BUFFER_SIZE, then we check it to avoid errors.
then, bytes = read(fd, read_buff, BUFFER_SIZE).
this reads BUFFER_SIZE amount of bytes from fd, and records them in
read_buff, it also counts how many bytes its read, and records that in
our int bytes. we then check to make sure there was data read there, if
not, we break the loop. otherwise, we join read_buff, on to the end of
buffer. this is a static char remember, so each time we add read_buff
on the end, the total information in buffer accumulates.
we then use ft_strnchr flag to find the '\n' character again. this time,
with the flag 1, so that if there is nothing in buffer, the function will
return -5. this allows for a different type of error, in that if it returns
its normal -1, the function will continue the loop believing that it hasn't
found its '\n' yet, when in reality, the funtion is reading random memory.
then we free read_buff, so that we can use it to read the next chunk of
memory. after the loop we free it again, this makes sure it is free,
as the loop can exit or finish before the end of its code, and read_buff
may still be allocated memory.
we then return check_update_output. which checks everything ran smoothly,
and de-allocates buffer, and returns the original contents of buffer.
*/
char	*read_map_file(int fd)
{
	int			bytes;
	int			pos;
	char		*read_buff;
	static char	*buffer = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes = 0;
	read_buff = NULL;
	pos = ft_strchr_flag(buffer, '\n', 0);
	while (pos == -1 && pos != -5)
	{
		read_buff = (char *)ft_calloc(BUFFER_SIZE, sizeof(char));
		if (!read_buff)
			return (NULL);
		bytes = read(fd, read_buff, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		buffer = ft_strnjoin(buffer, read_buff, bytes);
		pos = ft_strchr_flag(buffer, '\n', 1);
		ft_free(&read_buff);
	}
	ft_free(&read_buff);
	return (check_update_output(&buffer, pos, bytes));
}
