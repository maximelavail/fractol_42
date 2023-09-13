/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 13:13:44 by maxime            #+#    #+#             */
/*   Updated: 2023/02/18 13:28:11 by mlavail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Ecrit la chaine s sur le descripteur de fichier fd suivi d’un ’\n’. */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	char	new_line;

	new_line = '\n';
	write(fd, s, ft_strlen(s));
	write(fd, &new_line, 1);
}
