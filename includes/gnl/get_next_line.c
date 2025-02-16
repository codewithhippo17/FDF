/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:20:02 by ehamza            #+#    #+#             */
/*   Updated: 2025/02/11 15:38:18 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_last(char	*line)
{
	int		i;

	i = 0;
	if (!line)
		return (NULL);
	while (line[i] && line[i] != 10)
		i++;
	if (line[i] == 0)
		return (line);
	line[i + 1] = 0;
	return (line);
}

void	ft_save(char **reminder, char *buffer)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	if (!(buffer))
		return ;
	if (buffer)
	{
		len = ft_strlen(buffer);
		*reminder = malloc(len + 1);
		if (*reminder)
		{
			while (buffer[i])
			{
				(*reminder)[i] = buffer[i];
				i++;
			}
			(*reminder)[i] = '\0';
		}
	}
}

void	fill_word(int fd, char **word, char **line, char **newline_pos)
{
	ssize_t		size;

	size = 0;
	while (1)
	{
		*word = malloc(BUFFER_SIZE + 1);
		if (!(*word))
			return ;
		size = read(fd, *word, BUFFER_SIZE);
		if (size <= 0)
		{
			*newline_pos = ft_find_char(*line);
			free(*word);
			break ;
		}
		(*word)[size] = 0;
		*line = str_concat(*line, *word);
		*newline_pos = ft_find_char(*line);
		if (*newline_pos)
			break ;
	}
}

char	*read_buffer(int fd)
{
	static char	*reminder;
	char		*word;
	char		*line;
	char		*newline_pos;

	line = NULL;
	newline_pos = NULL;
	if (reminder)
	{
		line = str_concat(line, reminder);
		reminder = NULL;
	}
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	fill_word(fd, &word, &line, &newline_pos);
	if (!word)
		return (NULL);
	if (newline_pos)
		ft_save(&reminder, newline_pos + 1);
	return (line);
}

char	*get_next_line(int fd)
{
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_last(read_buffer(fd));
	if (!line || line[0] == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

// int main()
// {
// 	int fd = open("bbb", O_RDWR, 0777);
// 	char *line = NULL;
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);

// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);

// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);

// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);

// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);

// 	line = get_next_line(fd);
// 	printf("%s", line);
// }
