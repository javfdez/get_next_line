/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:18:56 by javferna          #+#    #+#             */
/*   Updated: 2021/10/06 16:59:51 by javferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define MAX_FD 12288

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);

#endif
