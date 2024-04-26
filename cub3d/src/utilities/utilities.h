/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beeren <beeren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 02:47:27 by beeren            #+#    #+#             */
/*   Updated: 2024/03/28 03:16:17 by beeren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITIES_H
# define UTILITIES_H

# include "stdlib.h"

int		ft_atoi(char *nptr);
int		ft_is_digit(int c);
char	**ft_split(char *string, char delimiter);
char	*ft_strchr(char *s, int c);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(char *s);
int		ft_strlcpy(char *dest, char *src, int n);
int		ft_strlen(char *string);
int		ft_strncmp(char *s1, char *s2, int n);
char	*ft_strncpy(char *dest, char *src, int n);
char	*ft_strtrim_start(char *s1, char *set);
char	*ft_strtrim(char *s1, char *set);
char	*ft_substr(char *s, int start, int len);
void	ft_putstr_fd(char *s, int fd);
void	ft_no_malloc(char **pointer);

#endif