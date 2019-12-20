/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 11:53:37 by aolen             #+#    #+#             */
/*   Updated: 2019/11/19 11:53:37 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		middle_el(t_stack *stack)
{
	int i;
	int middle;

	i = 0;
	middle = lst_len(stack) / 2;
	while (i < middle)
	{
		stack = stack->next;
		++i;
	}
	return (stack->num);
}

static void		fill_lists(t_stack *stack, t_stack **less, t_stack **greater,
							t_stack **median)
{
	*less = NULL;
	*greater = NULL;
	(*median)->num = middle_el(stack);
	while (stack)
	{
		if (stack->num != (*median)->num)
		{
			if (stack->num > (*median)->num)
				add_el(stack->num, greater);
			else
				add_el(stack->num, less);
		}
		stack = stack->next;
	}
}

t_stack			*find_median(t_stack *stack, int pos, t_stack *median)
{
	t_stack *less;
	t_stack *greater;
	int		less_len;
	int		greater_len;

	fill_lists(stack, &less, &greater, &median);
	less_len = lst_len(less);
	greater_len = lst_len(greater);
	if (pos != less_len + 1)
	{
		if (less_len >= pos)
			median->num = find_median(less, pos, median)->num;
		else if (pos == less_len + (lst_len(stack) - less_len - greater_len))
			;
		else
			median->num = find_median(greater, pos - less_len - (lst_len(stack)
			- less_len - greater_len), median)->num;
	}
	del_list(&less);
	del_list(&greater);
	return (median);
}

t_median		*search_and_parse_median(t_stack_ptr *stack, int part_size)
{
	t_median *median;

	median = ft_memalloc(sizeof(*median));
	if (part_size <= 0)
		median->pos_number = (lst_len(stack->top) + 1) / 2;
	else
		median->pos_number = part_size;
	median->pos = ft_memalloc(sizeof(*median->pos));
	median->pos = find_median(stack->top, median->pos_number, median->pos);
	median->value = median->pos->num;
	return (median);
}
