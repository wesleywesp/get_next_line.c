/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wearaujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:57:23 by wearaujo          #+#    #+#             */
/*   Updated: 2023/01/04 13:57:25 by wearaujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t	ft_strlen(const char *str);
char	*ft_free_strjoin(char *s1, char *s2);
void	*ft_calloc(size_t nitems, size_t size);
char	*get_next_line(int fd);
size_t	ft_strlcpy(char	*dest, const char	*src, size_t	size);

#endif
