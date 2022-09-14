/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:01:17 by mfroissa          #+#    #+#             */
/*   Updated: 2022/09/14 14:48:48 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	search_n(char *line, char c)
{
	int	i;

	if (!line)
		return (0);
	i = 0;
	while (line[i])
	{
		if (line[i] == '\n' && c == 'n')
			return (i + 1);
		i++;
	}
	if (c != 'n')
		return (i);
	return (0);
}

char	*get_rest(char *buff, int n)
{
	int	i;

	i = 0;
	while (buff[n])
	{
		buff[i] = buff[n];
		i++;
		n++;
	}
	buff[i] = '\0';
	return (buff);
}

char	*strjoin(char *line, char *buff, int n)
{
	char	*str;
	int		i;

	str = malloc(sizeof(char) * (search_n(line, 's') + n + 1));
	if (!str)
		return (NULL);
	i = 0;
	if (line)
	{
		while (line[i])
		{
			str[i] = line[i];
			i++;
		}
	}
	i = 0;
	while (i < n)
	{
		str[search_n(line, 's') + i] = buff[i];
		i++;
	}
	str[search_n(line, 's') + i] = '\0';
	free(line);
	return (str);
}

char	*gnl_core(char *line, char *buff, int fd)
{
	size_t	byte;

	byte = 1;
	if (buff[0] == '\0')
	{
		byte = read(fd, buff, BUFFER_SIZE);
		if (byte == 0)
			return (NULL);
		buff[byte] = '\0';
	}
	while (!search_n(buff, 'n') && byte)
	{
		line = strjoin(line, buff, search_n(buff, 's'));
		byte = read(fd, buff, BUFFER_SIZE);
		buff[byte] = '\0';
	}
	line = strjoin(line, buff, search_n(buff, 'n'));
	buff = get_rest(buff, search_n(buff, 'n'));
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buff[1024][BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0 || (read(fd, 0, 0) <= -1))
		return (NULL);
	line = NULL;
	line = gnl_core(line, buff[fd], fd);
	return (line);
}

// int	 main()
// {
// 	int	i;

// 	i = 0;
// 	int	fd = open("test", O_RDONLY);
// 	int	fd2 = open("test2", O_RDONLY);
// 	char	*line;
// 	char	*line2;

// 	while (i < 6)
// 	{
// 		line = get_next_line(fd);
// 		line2 = get_next_line(fd2);
// 		printf("%s", line);
// 		printf("%s", line2);
// 		i++;
// 		free(line);
// 		free(line2);
// 	}
// 	close(fd);
// 	close(fd2);
// 	return (0);
// }
