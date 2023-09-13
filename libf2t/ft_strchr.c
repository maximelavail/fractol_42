/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 07:05:03 by mlavail           #+#    #+#             */
/*   Updated: 2023/02/18 13:19:58 by mlavail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* La fonction strchr() renvoie un pointeur sur la première occurrence 
 * du caractère c dans la chaîne s. */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}
