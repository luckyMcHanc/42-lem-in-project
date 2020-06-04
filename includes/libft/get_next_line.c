/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmhlanga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 13:00:45 by lmhlanga          #+#    #+#             */
/*   Updated: 2019/07/15 17:03:27 by lmhlanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_getnewline(char **str, char **line, int fd, int reader)
{
	char			*temp;
	unsigned int	i;
	unsigned int	length;

	i = 0;
	while (str[fd][i] != '\n' && str[fd][i] != '\0')
		i++;
	if (str[fd][i] == '\n')
	{
		length = i;
		*line = ft_strsub(str[fd], START, length);
		temp = ft_strdup(str[fd] + length + 1);
		free(str[fd]);
		str[fd] = temp;
		if (str[fd][0] == '\0')
			ft_strdel(&str[fd]);
	}
	else if (str[fd][i] == '\0')
	{
		if (reader == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	return (TRUE);
}

int		get_next_line(const int fd, char **line)
{
	static char	*str[19960630];
	char		buffer[BUFF_SIZE + 1];
	char		*temp;
	int			reader;

	if (fd < EMPTY || !line)
		return (ERROR);
	while ((reader = read(fd, buffer, BUFF_SIZE)) > EMPTY)
	{
		buffer[reader] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strnew(1);
		temp = ft_strjoin(str[fd], buffer);
		free(str[fd]);
		str[fd] = temp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (reader < EMPTY)
		return (ERROR);
	else if (reader == 0 && (str[fd] == NULL || str[fd][0] == '\0'))
		return (EMPTY);
	return (ft_getnewline(str, line, fd, reader));
}