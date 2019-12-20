/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:59:57 by aolen             #+#    #+#             */
/*   Updated: 2019/11/05 15:59:58 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		reverse_rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last_el;

	last_el = *stack;
	if (last_el && last_el->next)
	{
		while (last_el->next)
			last_el = last_el->next;
		temp = *stack;
		*stack = last_el;
		last_el->next = temp;
		last_el->prev->next = NULL;
		last_el->prev = NULL;
		temp->prev = *stack;
	}
}

void			rra(t_stack **a, int p_flag)
{
	reverse_rotate(a);
	if (p_flag)
		ft_printf("rra\n");
}

void			rrb(t_stack **b, int p_flag)
{
	reverse_rotate(b);
	if (p_flag)
		ft_printf("rrb\n");
}

void			rrr(t_stack **a, t_stack **b, int p_flag)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (p_flag)
		ft_printf("rrr\n");
}
