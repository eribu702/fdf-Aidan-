/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:32:38 by lmells            #+#    #+#             */
/*   Updated: 2022/02/15 10:46:19 by lmells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	*update_buffer(char **buffer, int pos)
{
	char	*tmp;
	int		len;

	len = ft_strlen(*buffer) - pos;
	tmp = ft_strndup(*buffer + pos, len);
	free(*buffer);
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
		pos = ft_strlen(*buffer);
	else
		pos++;
	output = ft_strndup(*buffer, pos);
	if (pos == ft_strlen(*buffer))
		ft_free(buffer);
	else
		*buffer = update_buffer(buffer, pos);
	return (output);
}

char	*read_map_file(int fd)
{
	int			bytes;
	int			pos;
	char		*read_buff;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes = 0;
	read_buff = NULL;
	pos = strchr_flag(buffer, '\n', 0);
	while (pos == -1 && pos != -5)
	{
		read_buff = (char *)ft_calloc(BUFFER_SIZE, sizeof(char));
		if (!read_buff)
			return (NULL);
		bytes = read(fd, read_buff, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		buffer = ft_strnjoin(buffer, read_buff, bytes);
		pos = strchr_flag(buffer, '\n', 1);
		ft_free(&read_buff);
	}
	ft_free(&read_buff);
	return (check_update_output(&buffer, pos, bytes));
}
