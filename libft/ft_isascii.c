/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:37:47 by mlavail           #+#    #+#             */
/*   Updated: 2023/02/18 13:12:32 by mlavail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* vérifie si c est un unsigned char sur 7 bits, entrant 
 * dans le jeu de caractères ASCII. */

#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
