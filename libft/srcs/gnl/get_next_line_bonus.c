/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 09:33:42 by rseki             #+#    #+#             */
/*   Updated: 2024/09/11 19:13:17 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd);
void	read_save_file(int fd, char **saved);
char	*strjoin_wf(char *save_buffer, char *buff);
char	*keep_line(char *saved);
char	*save_remaining(char *saved);

char	*get_next_line(int fd)
{
	char		*line;
	static char	*saved[__FD_SETSIZE];

	if (fd < 0 || __FD_SETSIZE <= fd || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(saved[fd]);
		saved[fd] = NULL;
		return (NULL);
	}
	read_save_file(fd, &saved[fd]);
	if (!saved[fd])
		return (NULL);
	line = keep_line(saved[fd]);
	saved[fd] = save_remaining(saved[fd]);
	if (!line)
		free(saved[fd]);
	return (line);
}

void	read_save_file(int fd, char **saved)
{
	ssize_t	bytes_read;
	char	*buff;

	if (!*saved)
		*saved = ft_calloc(1, 1);
	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff)
	{
		free(*saved);
		*saved = NULL;
		return ;
	}
	bytes_read = read(fd, buff, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buff[bytes_read] = '\0';
		*saved = strjoin_wf(*saved, buff);
		if (ft_strchr(buff, '\n'))
			break ;
		bytes_read = read(fd, buff, BUFFER_SIZE);
	}
	free(buff);
}

char	*strjoin_wf(char *save_buffer, char *buff)
{
	char	*conc;

	conc = ft_strjoin_gnl(save_buffer, buff);
	free(save_buffer);
	if (!conc)
		return (NULL);
	return (conc);
}

char	*keep_line(char *saved)
{
	char	*line;
	int		i;

	i = 0;
	if (!saved[i])
		return (NULL);
	while (saved[i] && saved[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (saved[i] && saved[i] != '\n')
	{
		line[i] = saved[i];
		i++;
	}
	if (saved[i] && saved[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*save_remaining(char *saved)
{
	int		i;
	int		j;
	char	*rem;

	i = 0;
	while (saved[i] && saved[i] != '\n')
		i++;
	if (!saved[i])
	{
		free(saved);
		return (NULL);
	}
	rem = ft_calloc((ft_strlen(saved) - i + 1), sizeof(char));
	if (!rem)
		return (NULL);
	j = 0;
	i++;
	while (saved[i])
		rem[j++] = saved[i++];
	free(saved);
	return (rem);
}
