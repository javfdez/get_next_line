/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:18:32 by javferna          #+#    #+#             */
/*   Updated: 2021/10/05 03:23:45 by javferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_newline(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		return (i + 1);
	return (0);
}

static char	*ft_fill_result(char *buf, int i)
{
	static char	*temp;
	char		*aux;
	char		*aux2;

	if (!i)
	{
		aux = temp;
		if (!temp)
			temp = ft_strdup(buf);
		else
			temp = ft_strjoin(temp, buf);
		free(aux);
		return (temp);
	}
	if (!temp)
	{
		temp = ft_substr(buf, i + 1, BUFFER_SIZE + 1);
		return (ft_substr(buf, 0, i));
	}
	aux2 = ft_substr(buf, 0, i);
	aux = ft_strjoin(temp, aux2);
	free(aux2);
	free(temp);
	temp = ft_substr(buf, i + 1, BUFFER_SIZE + 1);
	return (aux);
}

char	*get_next_line(int fd)
{
	char	*buf;
	char	*result;
	int		i;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	buf[BUFFER_SIZE] = '\0';
	result = NULL;
	i = 0;
	while (!i)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1 || i == 0 || !*buf)
			break ;
		i = ft_newline(buf);
		result = ft_fill_result(buf, i);
	}
	free(buf);
	return (result);
}
