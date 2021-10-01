/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:18:32 by javferna          #+#    #+#             */
/*   Updated: 2021/10/01 15:32:26 by javferna         ###   ########.fr       */
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

static void	ft_fill_result(char *reading, char *result, int i)
{
	int		i;
	char	*aux;
	char	*aux2;

	i = ft_newline(reading);
	if (i == BUFFER_SIZE)
	{
	}
}

char	*get_next_line(int fd)
{
	char		*reading;
	char		*result;
	int			i;

	reading = malloc((BUFFER_SIZE + 1) + sizeof(char)); //free this
	if (!reading)
		return (NULL);
	result = malloc((1) + sizeof(char));
	if (!result)
		return (NULL);
	reading[BUFFER_SIZE] = '\0';
	result[0] = '\0';
	while ()
	{
		i = read(fd, reading, BUFFER_SIZE);
		if (i == -1)
			return (NULL);
		ft_fill_result(reading, result, i);
	}
	return (result);
}

