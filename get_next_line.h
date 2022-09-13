/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 23:46:32 by mfroissa          #+#    #+#             */
/*   Updated: 2022/09/13 19:23:49 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <unistd.h>

int		search_n(char *line, char c);
char	*get_rest(char *buff, int n);
char	*strjoin(char *line, char *buff, int n);
char	*gnl_core(char *line, char *buff, int n);
char	*get_next_line(int fd);

#endif
