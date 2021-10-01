/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:18:32 by javferna          #+#    #+#             */
/*   Updated: 2021/10/01 19:17:57 by javferna         ###   ########.fr       */
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
}

char	*get_next_line(int fd)
{
	char		reading[BUFFER_SIZE + 1];
	char		result[1];
	static char	*temp;
	int			i;


	return (result);
}
