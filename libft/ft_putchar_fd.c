/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 13:12:29 by maxime            #+#    #+#             */
/*   Updated: 2023/02/18 13:23:42 by mlavail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Ecrit le caractère c sur le descripteur de fichier fd. */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
