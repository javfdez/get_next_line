/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:18:32 by javferna          #+#    #+#             */
/*   Updated: 2021/09/30 12:58:36 by javferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_newline(char *reading)
{
	int	i;

	i = 0;
	while (reading[i] && reading[i != '\n'])
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

	reading = malloc((BUFFER_SIZE + 1) +  sizeof(char)); //free this
	if (!reading)
		return (NULL);
	while ()
	{
		i = read(fd, reading, BUFFER_SIZE);
		if (i == -1)
			return (NULL);
		reading[i] = '\0';
		j = ft_newline(reading);
		aux = ft_substr(reading, 0, j); //free this
		if (j != i)
			result = ft_strjoin (aux, reading);


	}

}
