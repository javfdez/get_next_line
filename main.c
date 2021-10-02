/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 14:29:57 by javferna          #+#    #+#             */
/*   Updated: 2021/10/02 20:29:43 by javferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(void)
{
	int		fd;
	char	*str;

	fd = open("test.txt", O_RDONLY);
	while((str = get_next_line(fd)))
	{
		printf("result: %s\n", str);
		free(str);
	}
	close(fd);
	return (0);
}
