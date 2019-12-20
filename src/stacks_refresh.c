/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:24:11 by aolen             #+#    #+#             */
/*   Updated: 2019/11/19 12:24:13 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	refresh_stack_info(t_stack_ptr *stack)
{
	t_stack *temp_el;

	if (!stack->top)
	{
		stack->min = INT32_MAX;
		stack->len = 0;
		return ;
	}
	temp_el = stack->top;
	stack->len = 0;
	stack->max = stack->top->num;
	stack->min = stack->top->num;
	while (temp_el->next)
	{
		stack->max = stack->max > temp_el->num ? stack->max : temp_el->num;
		stack->min = stack->min < temp_el->num ? stack->min : temp_el->num;
		temp_el->pos = stack->len++;
		temp_el = temp_el->next;
	}
	temp_el->pos = stack->len;
	stack->len += 1;
	stack->bot = temp_el;
	stack->max = stack->max > temp_el->num ? stack->max : temp_el->num;
	stack->min = stack->min < temp_el->num ? stack->min : temp_el->num;
}

void	refresh_stacks_info(t_stack_ptr *a, t_stack_ptr *b)
{
	refresh_stack_info(a);
	refresh_stack_info(b);
}
