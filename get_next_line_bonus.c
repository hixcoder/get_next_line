/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:56:19 by hboumahd          #+#    #+#             */
/*   Updated: 2021/11/21 15:57:35 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	ft_check_buff(char *buffer)
{
	int	i;

	i = -1;
	while (buffer[++i])
	{
		if (buffer[i] == '\n')
			return (1);
	}
	return (0);
}

static char	*ft_read(int fd, char *buffer, char *saved_str)
{
	int		readed_bytes;
	char	*temp;

	readed_bytes = 1;
	while (readed_bytes > 0)
	{
		readed_bytes = read(fd, buffer, BUFFER_SIZE);
		if (readed_bytes == -1)
			return (NULL);
		if (readed_bytes == 0)
			break ;
		buffer[readed_bytes] = '\0';
		if (saved_str == NULL)
			saved_str = ft_strdup("");
		temp = saved_str;
		saved_str = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_check_buff(buffer) == 1)
			break ;
	}
	return (saved_str);
}

static char	*ft_read_one_line(char *line)
{
	size_t	i;
	char	*remain_str;
	size_t	line_len;

	i = 0;
	line_len = ft_strlen(line);
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (NULL);
	remain_str = ft_substr(line, (i + 1), (line_len - i));
	if (remain_str[0] == '\0')
	{
		free(remain_str);
		remain_str = NULL;
	}
	line[i + 1] = '\0';
	return (remain_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*saved_str[1024];

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = ft_read(fd, buffer, saved_str[fd]);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	saved_str[fd] = ft_read_one_line(line);
	return (line);
}
