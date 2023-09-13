/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:46:46 by mlavail           #+#    #+#             */
/*   Updated: 2023/02/18 13:09:46 by mlavail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* vérifie s'il s'agit d'un caractère imprimable, y compris l'espace. */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}
