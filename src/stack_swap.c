/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 18:15:31 by aolen             #+#    #+#             */
/*   Updated: 2019/11/03 18:15:31 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*temp;
	t_stack *temp_next;
	t_stack *temp_prev;
	t_stack *temp_next_next;

	if (*stack && (*stack)->next)
	{
		temp = *stack;
		temp_next = (*stack)->next;
		temp_next_next = (*stack)->next->next;
		temp_prev = (*stack)->prev;
		temp->next = temp_next_next;
		temp->prev = temp_next;
		temp_next->next = temp;
		temp_next->prev = temp_prev;
		if (temp_next_next)
			temp_next_next->prev = temp;
		*stack = temp_next;
	}
}

void		sa(t_stack **a, int p_flag)
{
	swap(a);
	if (p_flag)
		ft_putendl("sa");
}

void		sb(t_stack **b, int p_flag)
{
	swap(b);
	if (p_flag)
		ft_putendl("sb");
}

void		ss(t_stack **a, t_stack **b, int p_flag)
{
	sa(a, 0);
	sb(b, 0);
	if (p_flag)
		ft_putendl("ss");
}
