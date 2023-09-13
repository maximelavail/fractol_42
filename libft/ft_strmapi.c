/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 13:05:45 by maxime            #+#    #+#             */
/*   Updated: 2023/02/18 13:11:11 by mlavail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Applique la fonction f à chaque caractère de la chaine de caractères 
 * passée en paramètre en précisant son index pour créer une nouvelle chaine 
 * résultant des applications successives de f. */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*map;
	unsigned int	i;

	i = 0;
	map = ft_strdup(s);
	if (!map || !s || !f)
		return (NULL);
	while (map[i])
	{
		map[i] = f(i, map[i]);
		i++;
	}
	return (map);
}
