/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 12:43:22 by aolen             #+#    #+#             */
/*   Updated: 2019/12/15 12:43:23 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		push_element_on_top_rr(t_stack_ptr *a, t_stack_ptr *b,
		t_stack *el_with_min_cost)
{
	while (b->top != el_with_min_cost)
	{
		if (el_with_min_cost->cost > -1)
		{
			rr(&(a->top), &(b->top), PRINT_FLAG);
			a->bot = a->bot->next;
			b->bot = b->bot->next;
			(el_with_min_cost->cost)--;
		}
		else
		{
			rb(&(b->top), PRINT_FLAG);
			b->bot = b->bot->next;
		}
	}
}

static void		push_element_on_top_rrr(t_stack_ptr *a, t_stack_ptr *b,
										t_stack *el_with_min_cost)
{
	while (b->top != el_with_min_cost)
	{
		if (el_with_min_cost->cost < 0)
		{
			b->bot = b->bot->prev;
			a->bot = a->bot->prev;
			rrr(&(a->top), &(b->top), PRINT_FLAG);
			(el_with_min_cost->cost)++;
		}
		else
		{
			b->bot = b->bot->prev;
			rrb(&(b->top), PRINT_FLAG);
		}
	}
}

static void		push_min_on_top_a(t_stack_ptr *a)
{
	if (search_max(a)->pos < a->len / 2)
		while (a->top->num != a->min)
		{
			ra(&a->top, PRINT_FLAG);
			a->bot = a->bot->next;
		}
	else
		while (a->top->num != a->min)
		{
			a->bot = a->bot->prev;
			rra(&a->top, PRINT_FLAG);
		}
}

static void		push_suitable_on_top_a(t_stack_ptr *a, t_stack_ptr *b)
{
	if (b->top->cost >= 0)
		while (a->top->num < b->top->num || a->bot->num > b->top->num)
		{
			ra(&a->top, PRINT_FLAG);
			a->bot = a->bot->next;
		}
	else
		while (a->top->num < b->top->num || a->bot->num > b->top->num)
		{
			a->bot = a->bot->prev;
			rra(&a->top, PRINT_FLAG);
		}
}

/*
** Func sort_stack_r:
** -----------------------------
**	Sorts stack in ascending order using insert sort method
**	by pushing elements the cheapest element from stack b to a in
**	it's position
**		*a pointer to stack A
**		*b pointer to stack B
*/

void			sort_stack_r(t_stack_ptr *a, t_stack_ptr *b)
{
	t_stack *el_with_min_cost;

	if (check_order(a) != 0)
		sa(&a->top, PRINT_FLAG);
	while (b->top)
	{
		el_with_min_cost = find_cheapest_element(a, b);
		if (el_with_min_cost->pos >= 0)
			push_element_on_top_rr(a, b, el_with_min_cost);
		else
			push_element_on_top_rrr(a, b, el_with_min_cost);
		if (b->top->num < a->min || b->top->num > a->max)
			push_min_on_top_a(a);
		else
			push_suitable_on_top_a(a, b);
		pa(&a->top, &b->top, PRINT_FLAG);
		refresh_stack_info(a);
		refresh_stack_info(b);
	}
}
