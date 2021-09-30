/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:18:32 by javferna          #+#    #+#             */
/*   Updated: 2021/09/30 16:03:20 by javferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_newline(char *reading)
{
	int	i;

	i = 0;
	while (reading[i] && reading[i] != '\n')
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	static char	*reading;
	char		*result;
	char		*aux;
	int			i;
	int			j;

		result = NULL;
	j = 0;
	i = 0;
	while (j == i)
	{
		reading = malloc((BUFFER_SIZE + 1) +  sizeof(char));
		if (!reading)
			return (NULL);
		i = read(fd, reading, BUFFER_SIZE);
		if (i == -1)
			return (NULL);
		reading[i] = '\0';
		j = ft_newline(reading);
		aux = ft_substr(reading, 0, j);
		if (!result)
			result = ft_strdup(aux);
		else
			result = ft_strjoin (result, aux);
		free(aux);
		free(reading);
	}
	return (result);
}
