/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 20:21:50 by aolen             #+#    #+#             */
/*   Updated: 2019/11/03 20:21:50 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **st1, t_stack **st2)
{
	t_stack *temp;

	if (*st2)
	{
		temp = (*st2)->next;
		(*st2)->next = *st1;
		if (temp)
			temp->prev = NULL;
		if (*st1)
			(*st1)->prev = *st2;
		*st1 = *st2;
		*st2 = temp;
	}
}

void		pa(t_stack **a, t_stack **b, int p_flag)
{
	push(a, b);
	if (p_flag)
		ft_printf("pa\n");
}

void		pb(t_stack **a, t_stack **b, int p_flag)
{
	push(b, a);
	if (p_flag)
		ft_printf("pb\n");
}
