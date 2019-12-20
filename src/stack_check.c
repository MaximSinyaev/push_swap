/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:25:17 by aolen             #+#    #+#             */
/*   Updated: 2019/11/05 18:25:17 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_sort(t_stack *stack)
{
	if (!stack->next)
		return (1);
	while (stack && stack->next)
	{
		if (stack->num > stack->next->num)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int			check_stacks(t_stack *a, t_stack *b)
{
	if (b)
		return (0);
	if (!check_sort(a))
		return (0);
	return (1);
}
