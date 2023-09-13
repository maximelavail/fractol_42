/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:29:11 by mlavail           #+#    #+#             */
/*   Updated: 2023/02/18 13:03:04 by mlavail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Cette fonction permet de tester si un caractère est alpha-numérique ou non */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9')
		|| ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')))
	{
		return (1);
	}
	return (0);
}
