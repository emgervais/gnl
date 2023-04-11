/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egervais <egervais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:12:10 by egervais          #+#    #+#             */
/*   Updated: 2023/02/14 19:17:21 by egervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <limits.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define ERROR -1

int		ft_strchr(const char *string, int c);
size_t	ft_strlen(const char *s);
char	*get_next_line(int fd);
void	ft_strcpy(char *s1, const char *s2);

#endif