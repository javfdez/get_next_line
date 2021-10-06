/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:18:48 by javferna          #+#    #+#             */
/*   Updated: 2021/10/06 16:59:38 by javferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != (char)c)
		i++;
	if (!s[i] && (char)c != '\0')
		return (NULL);
	return ((char *)&s[i]);
}
