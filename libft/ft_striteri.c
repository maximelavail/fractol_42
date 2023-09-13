/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 13:11:58 by maxime            #+#    #+#             */
/*   Updated: 2023/02/18 12:57:28 by mlavail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 	Applique la fonction f à chaque caractère 
 *  	de la chaine passée en paramètre en précisant 
 *  	son index en premier argument. Chaque caractère est passé 
 *  	par adresse à la fonction f afin de pouvoir être modifié. */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			(*f)(i, &s[i]);
			i++;
		}
	}
}
