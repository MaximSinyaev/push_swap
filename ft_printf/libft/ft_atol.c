/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 17:10:41 by aolen             #+#    #+#             */
/*   Updated: 2019/11/03 17:10:41 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int		ft_atol(const char *str)
{
	int		i;
	long	numbers;
	int		sign;

	i = 0;
	sign = 1;
	numbers = 0;
	while (ft_isspace(str[i]))
		i++;
	if ((str[i] == '-') && (str[i + 1] - '0' < 10)
		&& (str[i + 1] - '0' >= 0))
		i -= (sign = -1);
	else if (str[i] == '+' && ((str[i + 1] - '0' < 10)
							&& (str[i + 1] - '0' >= 0)))
		i++;
	while ((str[i] - '0' < 10) && (str[i] - '0' >= 0))
		numbers = numbers * 10 + (str[i++] - '0');
	return (numbers * sign);
}
