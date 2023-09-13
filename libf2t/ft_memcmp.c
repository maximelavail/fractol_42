/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:35:54 by mlavail           #+#    #+#             */
/*   Updated: 2023/02/18 13:27:40 by mlavail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* La fonction memcmp() compare les n premiers octets 
 * des zones mémoire s1 et s2. */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	const unsigned char	*s1 = str1;
	const unsigned char	*s2 = str2;

	while (n--)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}
