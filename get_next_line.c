/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:18:32 by javferna          #+#    #+#             */
/*   Updated: 2021/10/04 18:24:54 by javferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_newline(char *temp)
{
	int	i;

	i = 0;
	while (temp[i] && temp[i] != '\n')
		i++;
	return (i);
}

static char	*ft_fill_line(int fd, char *aux, char *buf, char *temp)
{
	long	i;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	i = BUFFER_SIZE;
	while (i == BUFFER_SIZE)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1 || !*buf)
			break;
		buf[i] = '\0';
		aux = temp;
		if (!temp)
			temp = ft_strdup(buf);
		else
			temp = ft_strjoin(aux, buf);
		free(aux);
		i = ft_newline(buf);
	}
	free(buf);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*result;
	char		*aux;
	char		*buf;
	long		i;

	aux = NULL;
	buf = NULL;
	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	temp = ft_fill_line(fd, aux, buf, temp);
	if (!temp || !*temp)
		return (NULL);
	if (*temp == '\n')
	{
		free(temp);
		temp = NULL;
		return (ft_strdup("\n"));
	}
	i = ft_newline(temp);
	result = ft_substr(temp, 0, i);
	aux = temp;
	temp = ft_substr(aux, i + 1, ft_strlen(aux));
	free(aux);
	return (result);
}
