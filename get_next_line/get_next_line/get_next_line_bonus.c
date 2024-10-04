/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkander <rkander@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 11:35:52 by rkander           #+#    #+#             */
/*   Updated: 2024/02/28 14:47:16 by rkander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read(int fd, char *txt)
{
	int		t;
	char	*line;

	t = 1;
	line = (char *)malloc((size_t)BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	while (!ft_strchr(txt, '\n') && t != 0)
	{
		t = read(fd, line, BUFFER_SIZE);
		if (t == -1)
			return (free(line), free(txt), NULL);
		line[t] = '\0';
		txt = ft_strjoin(txt, line);
	}
	free (line);
	if (t == 0 && txt[0] == '\0')
	{
		free (txt);
		return (NULL);
	}
	return (txt);
}

char	*extract_line_without_newline(char *text)
{
	char	*str;
	int		i;
	int		t;

	i = 0;
	t = 0;
	while (text[i] != '\n' && text[i] != '\0' )
		i++;
	if (text[i] == '\n')
		i++;
	str = (char *)malloc(i + 1);
	if (!str)
		return (NULL);
	while (t < i)
	{
		str[t] = text[t];
		t++;
	}
	str[t] = '\0';
	return (str);
}

char	*extract_remaining_text(char *text)
{
	int		i;
	int		t;
	char	*str;

	i = 0;
	t = 0;
	while (text[i] != '\n' && text[i] != '\0')
		i++;
	if (text[i] == '\n')
		i++;
	str = (char *)malloc(ft_strlen(text + i) + 1);
	if (!str)
	{
		free(text);
		return (NULL);
	}
	while (text[i])
	{
		str[t] = text[i];
		i++;
		t++;
	}
	str[t] = '\0';
	free (text);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*text[OPEN_MAX + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	text[fd] = ft_read(fd, text[fd]);
	if (!text[fd])
		return (NULL);
	line = extract_line_without_newline(text[fd]);
	text[fd] = extract_remaining_text(text[fd]);
	return (line);
}
