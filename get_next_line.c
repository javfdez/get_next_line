/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:18:32 by javferna          #+#    #+#             */
/*   Updated: 2021/10/06 01:01:48 by javferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_newline(char *temp)
{
	int	i;

	if (!temp)
		return (-1);
	i = 0;
	while (temp[i] && temp[i] != '\n')
		i++;
	if (temp[i] == '\n')
		return (i);
	return (-1);
}

static char	*ft_strjoin_gnl(char *temp, char *buf)
{
	char	*new_temp;
	int		i;
	int		j;

	if (!temp && !buf)
		return (NULL);
	i = 0;
	j = 0;
	if (temp)
		i = ft_strlen(temp);
	if (buf)
		j = ft_strlen(buf);
	new_temp = malloc((i + j + 1) * sizeof(char));
	if (!new_temp)
		return (NULL);
	ft_memcpy(new_temp, temp, i);
	ft_memcpy(new_temp + i, buf, j);
	new_temp[i + j] = '\0';
	if (temp)
		free(temp);
	return (new_temp);
}

static char	*ft_fill_result(char **temp)
{
	int		pos;
	char	*ret;
	char	*aux;

	if (!*temp || !**temp)
		return (NULL);
	aux = *temp;
	pos = ft_newline(*temp);
	if (pos == -1)
		pos = ft_strlen(*temp);
	ret = ft_substr_gnl(*temp, 0, pos + 1);
	*temp = ft_substr_gnl(*temp, pos + 1, ft_strlen(*temp));
	free(aux);
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*buf;
	int			r;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	r = 1;
	while (r && ft_newline(temp) == -1)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r == -1)
		{
			free(buf);
			return(NULL);
		}
		buf[r] = '\0';
		temp = ft_strjoin_gnl(temp, buf);
	}
	free(buf);
	buf = ft_fill_result(&temp);
	return (buf);
}
