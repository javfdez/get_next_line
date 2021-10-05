/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:18:48 by javferna          #+#    #+#             */
/*   Updated: 2021/10/06 00:17:31 by javferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	int		i;
	char	*cpy;

	len = ft_strlen(s1);
	cpy = malloc((len + 1) * sizeof(char));
	if (!cpy)
		return (NULL);
	i = -1;
	while (s1[++i])
		cpy[i] = s1[i];
	cpy[i] = '\0';
	return (cpy);
}

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	n;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (NULL);
	n = ft_strlen(&s[start]);
	if (len > n)
		len = n;
	substr = malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	while (s[start] && i < len)
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*cast_src;
	char		*cast_dst;
	size_t		i;

	if (src == NULL && dst == NULL)
		return (NULL);
	cast_src = src;
	cast_dst = dst;
	i = -1;
	while (++i < n)
		cast_dst[i] = cast_src[i];
	return (dst);
}
