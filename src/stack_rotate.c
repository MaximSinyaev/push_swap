/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:33:50 by aolen             #+#    #+#             */
/*   Updated: 2019/11/05 15:33:50 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last_el;

	last_el = *stack;
	if (last_el && last_el->next)
	{
		while (last_el->next)
			last_el = last_el->next;
		temp = (*stack);
		(*stack) = (*stack)->next;
		temp->next = NULL;
		temp->prev = last_el;
		last_el->next = temp;
		(*stack)->prev = NULL;
	}
}

void		ra(t_stack **a, int p_flag)
{
	rotate(a);
	if (p_flag)
		ft_printf("ra\n");
}

void		rb(t_stack **b, int p_flag)
{
	rotate(b);
	if (p_flag)
		ft_printf("rb\n");
}

void		rr(t_stack **a, t_stack **b, int p_flag)
{
	rotate(a);
	rotate(b);
	if (p_flag)
		ft_printf("rr\n");
}
