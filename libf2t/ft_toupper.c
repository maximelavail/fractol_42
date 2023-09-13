/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 06:57:31 by mlavail           #+#    #+#             */
/*   Updated: 2023/02/18 13:25:22 by mlavail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* toupper() convertit la lettre c en majuscule si c'est possible. */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
