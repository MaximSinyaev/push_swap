/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_output.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 13:06:25 by aolen             #+#    #+#             */
/*   Updated: 2019/12/15 13:06:26 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_initial_stacks(t_stack *a_top, t_stack *b_top, int v_flag)
{
	if (v_flag)
	{
		print_stacks((a_top), (b_top));
		ft_printf("Initial state\n");
		sleep(1);
	}
}

void	print_result_stacks(t_stack *a_top, t_stack *b_top, int v_flag)
{
	if (v_flag)
	{
		print_stacks((a_top), (b_top));
		ft_printf("Result\n");
		sleep(1);
	}
}
