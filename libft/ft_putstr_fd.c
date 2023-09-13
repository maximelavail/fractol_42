/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 13:12:58 by maxime            #+#    #+#             */
/*   Updated: 2023/02/18 13:15:05 by mlavail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Ecrit la chaine s sur le descripteur de fichier fd. */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	if (s == NULL)
		return ;
	write(fd, s, ft_strlen(s));
}
