/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:38:33 by mlavail           #+#    #+#             */
/*   Updated: 2023/02/18 13:02:12 by mlavail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* strjoin() crée une chaîne composée de l'élément str1 concaténé 
 * avec l'élément str2. La chaîne renvoyée est allouée à l'extérieur 
 * de la mémoire de travail. Sa durée de validité correspond donc à la durée 
 * de la clause. 
 * Si l'espace de travail disponible est insuffisant, strjoin ne s'exécute pas 
 * et une erreur est générée. */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		len1;
	int		len2;
	char	*str;

	if (s1 && s2)
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
		if (str == NULL)
			return (NULL);
		i = -1;
		while (s1[++i])
			str[i] = s1[i];
		i = -1;
		while (s2[++i])
		{
			str[len1] = s2[i];
			len1++;
		}
		str[len1] = '\0';
		return (str);
	}
	return (NULL);
}
