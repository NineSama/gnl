/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 18:27:29 by mfroissa          #+#    #+#             */
/*   Updated: 2022/06/15 15:08:23 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
		i++;
	return (i);
}

size_t	ft_is_there_n(char *buff)
{
	size_t	i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

char	*ft_transfer(char *line, char *buff, size_t n)
{
	size_t	i;
	char	*new;
	size_t	len;

	len = 0;
	i = 0;
	if (line)
		len = ft_strlen(line);
	new = (char *)malloc(sizeof(char) * (len + n + 1));
	while (i < len)
	{
		new[i] = line[i];
		i++;
	}
	i = 0;
	while (buff[i] && i < n)
	{
		new[i + len] = buff[i];
		i++;
	}
	new[i + len] = '\0';
	free(line);
	return (new);
}

void	ft_clear_n(char *buff, size_t n)
{
	size_t	i;

	i = 0;
	while (buff[i + n])
	{
		buff[i] = buff[i + n];
		i++;
	}
	buff[i] = buff[i + n];
}

char	*get_next_line(int fd)
{
	static char		buff[BUFFER_SIZE + 1] = {0};
	char			*line;
	static size_t	byte;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0 || (read(fd, 0, 0) <= -1))
		return (NULL);
	line = NULL;
	if (buff[0] != '\0')
	{
		if (ft_is_there_n(buff))
		{
			line = ft_transfer(line, buff, ft_is_there_n(buff));
			ft_clear_n(buff, ft_is_there_n(buff));
			return (line);
		}
		line = ft_transfer(line, buff, ft_strlen(buff));
		if (byte < BUFFER_SIZE && byte > 0)
		{
			byte = read(fd, buff, BUFFER_SIZE);
			buff[0] = '\0';
			return (line);
		}
	}
	byte = read(fd, buff, BUFFER_SIZE);
	if (byte == 0)
	{
		if (buff[0] != '\0')
		{
			buff[0] = '\0';
			return (line);
		}
		buff[0] = '\0';
		return (free(line), NULL);
	}
	buff[byte] = '\0';
	while (!ft_is_there_n(buff))
	{
		line = ft_transfer(line, buff, ft_strlen(buff));
		if (byte < BUFFER_SIZE)
		{
			byte = read(fd, buff, BUFFER_SIZE);
			buff[0] = '\0';
			return (line);
		}
		byte = read(fd, buff, BUFFER_SIZE);
		buff[byte] = '\0';
	}
	line = ft_transfer(line, buff, ft_is_there_n(buff));
	ft_clear_n(buff, ft_is_there_n(buff));
	return (line);
}
/*
int	main()
{
	int	fd = open("41_with_nl", O_RDONLY);
	char	*line;
	
	while ((line = get_next_line(fd)))
 	{
 		printf("%s", line);
 		free(line);
 	}
 	close(fd);
 	return (0);
}*/
