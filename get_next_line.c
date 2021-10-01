/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:18:32 by javferna          #+#    #+#             */
/*   Updated: 2021/10/01 18:04:08 by javferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_newline(char *reading)
{
	int	i;

	if (!reading)
		return(NULL);
	i = 0;
	while (reading[i] && reading[i] != '\n')
		i++;
	return (i);
}

static void	ft_fill_result(char *reading, char *result, int i)
{
	static char	*temp;

	if (ft_newline(reading) == BUFFER_SIZE)


}

char	*get_next_line(int fd)
{
	char		reading[BUFFER_SIZE + 1];
	char		result[1];
	static char	*temp;
	int			i;
	int			j;

	if(!BUFFER_SIZE || !fd)
		return (NULL);
	*result = '\0';
	reading[BUFFER_SIZE] = '\0';
	i = 0;
	while (i != BUFFER_SIZE &&------)
	{
		i = read(fd, reading, BUFFER_SIZE);
		if (i == -1)
			return (NULL);
		j = ft_newline(reading);
		if (j)
			temp = ft_substr(reading, j + 1, BUFFER_SIZE - j + 1);
		ft_fill_result(reading, result, i);
	}
	return (result);
}
