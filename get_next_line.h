/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 04:24:09 by mfroissa          #+#    #+#             */
/*   Updated: 2022/06/07 17:55:26 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>

size_t	ft_strlen(char *line);
size_t	ft_is_there_n(char *buff);
char	*ft_transfer(char *line, char *buff, size_t n);
void	ft_clear_n(char *buff, size_t n);
char	*get_next_line(int fd);

#endif
