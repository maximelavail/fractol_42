/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 07:03:35 by mlavail           #+#    #+#             */
/*   Updated: 2023/02/18 13:25:42 by mlavail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* tolower() convertit la lettre c en minuscule si c'est possible. */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
