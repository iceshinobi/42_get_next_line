/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokuyos <ctokuyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:09:15 by ctokuyos          #+#    #+#             */
/*   Updated: 2024/12/11 12:31:31 by ctokuyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*temp;
	size_t			msize;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	temp = malloc(nmemb * size);
	if (!temp)
		return (NULL);
	msize = nmemb * size;
	while (msize)
		temp[--msize] = 0;
	return (temp);
}

char	*ft_strdup(const char *s)
{
	char	*strcp;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s);
	strcp = (char *)malloc((len + 1) * sizeof(char));
	if (!strcp)
		return (NULL);
	while (s[i] != '\0')
	{
		strcp[i] = s[i];
		i++;
	}
	strcp[i] = '\0';
	return (strcp);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	full_len;
	char			*res;

	full_len = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)malloc((full_len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
		res[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		res[j++] = s2[i++];
	res[j] = '\0';
	return (res);
}
