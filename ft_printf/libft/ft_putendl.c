/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <aolen@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 17:56:01 by aolen             #+#    #+#             */
/*   Updated: 2019/09/07 15:33:41 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(const char *s)
{
	int i;

	if (!s)
		return ;
	i = 0;
	while (*(s + i))
	{
		ft_putchar(*(s + i));
		i += 1;
	}
	ft_putchar('\n');
	return ;
}