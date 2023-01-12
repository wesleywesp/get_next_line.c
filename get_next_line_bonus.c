/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wearaujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:57:11 by wearaujo          #+#    #+#             */
/*   Updated: 2023/01/04 13:57:18 by wearaujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

int	ft_strchr(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static char	*gotoleft(char *n)
{
	int		len;
	char	*array;
	int		strchr;

	strchr = ft_strchr(n);
	len = 0;
	if (n[strchr + 1] == '\0' || strchr == -1)
	{
		free (n);
		return (NULL);
	}
	array = malloc((ft_strlen(n) - strchr + 1) * sizeof(char));
	if (!array)
		return (NULL);
	while (n[len + strchr +1] != '\0')
	{
		array[len] = n[len + strchr + 1];
		len++;
	}
	array[len] = '\0';
	free (n);
	return (array);
}

static char	*get_read(int fd, char *next)
{
	int		byte;
	char	*lido;

	lido = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!lido)
		return (NULL);
	byte = 1;
	while (ft_strchr(lido) == -1 && byte > 0)
	{
		byte = read (fd, lido, BUFFER_SIZE);
		if (byte < 0)
			break ;
		lido[byte] = '\0';
		next = ft_free_strjoin(next, lido);
	}
	free (lido);
	if (byte < 0)
	{
		free (next);
		return (NULL);
	}
	else
		return (next);
}

static char	*get_line(char	*backup)
{
	char	*line;
	int		size;

	if (!*backup)
		return (NULL);
	size = 0;
	while (backup[size] && backup[size] != '\n')
		size++;
	line = (char *)malloc(sizeof(char) * (size + 2));
	if (!line)
		return (NULL);
	ft_strlcpy(line, backup, size + 1);
	if (backup[size] == '\n')
		line[size++] = '\n';
	line[size] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*str[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 4095)
		return (NULL);
	str[fd] = get_read(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	line = get_line(str[fd]);
	str[fd] = gotoleft(str[fd]);
	return (line);
}
/*
int	main(void)
{
	int fd;
	int fd2;
	char *str;

	fd = open("arquivo.txt",O_RDONLY);
	str = get_next_line(fd);
	printf("%s\n",str);
	str = get_next_line(fd);
	printf("%s\n",str);

	fd2 = open("arq.txt",O_RDONLY);
	str = get_next_line(fd2);
	printf("%s\n",str);
	
	str = get_next_line(fd);
	printf("%s\n",str);

	str = get_next_line(fd2);
	printf("%s\n",str);
	
	close(fd);
	return 0;
}
*/
