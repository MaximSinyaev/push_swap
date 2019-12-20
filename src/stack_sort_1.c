/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 12:41:25 by aolen             #+#    #+#             */
/*   Updated: 2019/12/15 12:41:26 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Func check_order:
** -----------------------------
**		Checks if stack A is sorted in ascending order
**
**		Returns: 1 if sorted, else 0
*/

int			check_order(t_stack_ptr *stack_ptr)
{
	t_stack *stack_el;
	t_stack	*min;
	int		min_val;
	int		i;

	stack_el = stack_ptr->top->next;
	min = stack_ptr->top;
	while (stack_el)
	{
		if (stack_el->num < min->num)
			min = stack_el;
		stack_el = stack_el->next;
	}
	min_val = min->num;
	stack_el = min->next ? min->next : stack_ptr->top;
	i = -1;
	while (++i < stack_ptr->len)
	{
		if (stack_el->num < min->num && stack_el->num != min_val)
			return (-1);
		stack_el = stack_el->next ? stack_el->next : stack_ptr->top;
		min = min->next ? min->next : stack_ptr->top;
	}
	return (0);
}

/*
** Func count_steps:
** -----------------------------
**		Count cost of moving each element from stack b to stack a
*/

static int	count_steps(t_stack_ptr *a, t_stack *el)
{
	t_stack	*temp;
	int		steps[2];

	steps[0] = 0;
	temp = a->top;
	if (el->num > a->max || el->num < a->min)
		while (temp->num != a->min)
		{
			++steps[0];
			temp = temp->next;
		}
	else
	{
		temp = temp->next;
		while (temp && ((el->num > temp->num) || (el->num < temp->prev->num)))
		{
			++steps[0];
			temp = temp->next;
		}
	}
	steps[1] = a->len - steps[0];
	if (ABS(steps[1]) < ABS(steps[0]))
		return (-steps[1]);
	else
		return (steps[0]);
}

/*
** Func search_max:
** -----------------------------
**		Searching position of max element in stack
**		*stack pointer to stack in which search needed
**
**		Returns pointer to element with max value
*/

t_stack		*search_max(t_stack_ptr *stack)
{
	t_stack *temp_el;

	temp_el = stack->top;
	while (temp_el)
	{
		if (temp_el->num == stack->max)
			return (temp_el);
		temp_el = temp_el->next;
	}
	return (temp_el);
}

t_stack		*find_cheapest_element(t_stack_ptr *a, t_stack_ptr *b)
{
	int		i;
	int		min_steps;
	t_stack	*temp;
	t_stack	*el_with_min_cost;

	i = -1;
	temp = b->top;
	min_steps = b->len + a->len + 1;
	el_with_min_cost = b->top;
	while (++i < b->len)
	{
		temp->cost = count_steps(a, temp);
		temp->pos = temp->pos < (b->len + 1) / 2 ? temp->pos :
					temp->pos - b->len;
		if (ABS(temp->cost) + ABS(temp->pos) < min_steps)
		{
			el_with_min_cost = temp;
			min_steps = ABS(temp->cost) + ABS(temp->pos);
		}
		temp = temp->next;
	}
	return (el_with_min_cost);
}
