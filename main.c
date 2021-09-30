/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 14:29:57 by javferna          #+#    #+#             */
/*   Updated: 2021/09/30 16:05:34 by javferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	test(void)
{
	system("leaks a.out");
}

int main(void)
{
	int		fd;
	int		i;
	char	*str;

	//atexit(test);
	fd = open("test.txt", O_RDONLY);
	i = -1;
	while(++i < 3)
	{
		str = get_next_line(fd);
		printf("%s\n", str);
	}
	return (0);
}
