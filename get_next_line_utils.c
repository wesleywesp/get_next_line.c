/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wearaujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 02:07:14 by wearaujo          #+#    #+#             */
/*   Updated: 2023/01/04 02:07:16 by wearaujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

void	ft_bzero(void *s, size_t n)
{
	char	*str2;

	str2 = s;
	while (n > 0)
	{
		str2[n - 1] = '\0';
		n--;
	}
}

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*array;

	array = malloc(nitems * size);
	if (!array)
		return (NULL);
	ft_bzero(array, nitems * size);
	return (array);
}

char	*ft_free_strjoin(char *s1, char *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	count;
	char	*joined;

	count = 0;
	if (!s1)
		s1 = ft_calloc(1, sizeof(char));
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	joined = ft_calloc((len_s1 + len_s2 + 1), sizeof(char));
	while (s1[count] != '\0')
	{
		joined[count] = s1[count];
		count++;
	}
	count = 0;
	while (s2[count] != '\0')
	{
		joined[len_s1 + count] = s2[count];
		count++;
	}
	joined[len_s1 + count] = '\0';
	free(s1);
	return (joined);
}

size_t	ft_strlcpy(char	*dest, const char	*src, size_t	size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (src[len])
		len++;
	if (!size)
		return (len);
	while (i < (size - 1) && i < len && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len);
}
