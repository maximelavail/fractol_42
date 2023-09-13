/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:42:49 by mlavail           #+#    #+#             */
/*   Updated: 2023/02/18 12:58:28 by mlavail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* La fonction malloc() alloue size octets, et renvoie un pointeur 
 * sur la mémoire allouée. Le contenu de la zone de mémoire n'est pas initialisé.
 * Si size est nulle, malloc renvoie soit NULL ou un unique pointeur qui pourra 
 * être passé ultérieurement à free() avec succès. */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	l;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	l = (nmemb * size);
	if (size != l / nmemb)
		return (NULL);
	ptr = malloc(l);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, l);
	return (ptr);
}
