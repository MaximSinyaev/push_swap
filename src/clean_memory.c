/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 13:25:16 by aolen             #+#    #+#             */
/*   Updated: 2019/12/15 13:25:17 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clean_stack_ptr(t_stack_ptr **stack_ptr)
{
	t_stack		*temp_el;
	t_stack_ptr	*stack;

	stack = *stack_ptr;
	if (stack && stack->top)
	{
		temp_el = stack->top;
		while (temp_el)
		{
			temp_el = temp_el->next;
			free(stack->top);
			stack->top = temp_el;
		}
	}
	free(*stack_ptr);
}

void	clean_stack_ptrs(t_stack_ptr **stack_ptr1, t_stack_ptr **stack_ptr2)
{
	clean_stack_ptr(stack_ptr1);
	clean_stack_ptr(stack_ptr2);
}

void	clean_median(t_median **median_el)
{
	if (*median_el)
		free((*median_el)->pos);
	free(*median_el);
}
