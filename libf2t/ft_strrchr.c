/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:15:21 by mlavail           #+#    #+#             */
/*   Updated: 2023/02/18 13:00:50 by mlavail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* La fonction strchr() renvoie un pointeur sur la première occurrence 
 * du caractère c dans la chaîne s. */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			*last;

	last = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			last = (char *)&s[i];
		i++;
	}
	if ((char)c == s[i])
		return ((char *)&s[i]);
	return (last);
}
