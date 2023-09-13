/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:27:06 by mlavail           #+#    #+#             */
/*   Updated: 2023/02/18 13:28:43 by mlavail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* La fonction strdup() renvoie un pointeur sur une nouvelle 
 * chaîne de caractères qui est dupliquée depuis s.  */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*copy;
	int		i;
	int		size;

	size = 0;
	while (src[size])
		size++;
	copy = malloc(sizeof(*copy) * (size + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (src[i])
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
