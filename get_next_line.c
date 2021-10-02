/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:18:32 by javferna          #+#    #+#             */
/*   Updated: 2021/10/02 20:43:23 by javferna         ###   ########.fr       */
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

char	*get_next_line(int fd)
{
	char		*buf;
	char		*aux;
	static char	*aux2;
	static char	*temp;
	long		i;

	if (BUFFER_SIZE < 1)
		return (NULL);
	buf = malloc((BUFFER_SIZE + (long)1) * sizeof(char));
	if (!buf)
		return (NULL);
	i = BUFFER_SIZE;
	while(i == BUFFER_SIZE)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
			return (NULL);
		buf[i] = '\0';
		aux = temp;
		if(!temp)
			temp = ft_strdup(buf);
		else
			temp = ft_strjoin(aux, buf);
		i = ft_newline(buf);
		free(aux);
	}
	if (!*temp)
		return (NULL);
	i = ft_newline(temp);
	aux = ft_substr(temp, 0, i);
	aux2 = temp;
	temp = ft_substr(aux2, i + 1, ft_strlen(aux2));
	free (aux2);
	free (buf);
	return (aux);
}
