/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wearaujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 02:06:20 by wearaujo          #+#    #+#             */
/*   Updated: 2023/01/04 02:06:50 by wearaujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

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
	char			*linha;
	static char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	next_line = get_read(fd, next_line);
	if (!next_line)
		return (NULL);
	linha = get_line(next_line);
	next_line = gotoleft(next_line);
	return (linha);
}
/*
#include <unistd.h>
#include <fcntl.h>
 
int main(void)
{
	FILE *fb_simples;
	char w[] = "baby tubarao";
	fb_simples = fopen("simples", "w");
	fputs("baby shark\n", fb_simples);
	fprintf(fb_simples, "%s\n", w);
	fputs("cuco cade o bebe", fb_simples);

	fclose(fb_simples);

	char *prt;
 	int fd = open("simples", O_RDONLY);	
	prt = get_next_line(fd);
	printf("%s\n", prt);
	prt = get_next_line(fd);
	printf("%s\n", prt);
	prt = get_next_line(fd);
	printf("%s", fd);
	prt = get_next_line(fd);
	printf("%s\n", prt);
	prt = get_next_line(fd);
	printf("%s\n", prt);
	free (prt);
	close(fd);
	return 0;

    int fd = open("simples", O_WRONLY);
 
    if (fd < 0) {
        return (0);
    }
	
    write(fd, "baby shark tutu\n", 17);
	write(fd, "cuco baby\n", 13);
	close (fd);
	char	*prt;
	fd = open("simples", O_RDONLY);
	prt = get_next_line(fd);
	printf("\n %s\n", prt);
	free(prt);
	prt = get_next_line(fd);
	printf("\n %s\n", prt);
	free(prt);
	prt = get_next_line(fd);
	printf("\n %s\n", prt);
	free(prt);
	prt = get_next_line(fd);
	printf("\n %s\n", prt);
	free(prt);
	prt = get_next_line(fd);
	printf("\n %s\n", prt);
	free(prt);
	prt = get_next_line(fd);
	printf("\n %s\n", prt);
	free(prt);
	prt = get_next_line(fd);
	printf("\n%s\n", prt);
	free(prt);
	close(fd);


	
}*/
