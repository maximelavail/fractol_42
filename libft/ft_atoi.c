/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 07:22:23 by mlavail           #+#    #+#             */
/*   Updated: 2023/02/18 12:53:35 by mlavail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* La fonction atoi() convertit le début de la chaîne pointée 
 * par nptr en entier de type int. */

#include <stdint.h>
#include "libft.h"

int	ft_atoi(const char *str)
{
	int	nb;
	int	sign;

	sign = 1;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	nb = 0;
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + *str - '0';
		str++;
	}
	return (nb * sign);
}
