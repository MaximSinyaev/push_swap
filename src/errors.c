/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 17:25:29 by aolen             #+#    #+#             */
/*   Updated: 2019/11/03 17:25:30 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

void	handle_error_args(t_opts *opts, t_stack_ptr **a, t_stack_ptr **b)
{
	if (opts)
	{
		opts->file = 0;
		opts->view = 0;
	}
	if (a)
		clean_stack_ptr(a);
	if (b)
		clean_stack_ptr(b);
	ft_putendl_fd("Error", 2);
	exit(2);
}

void	handle_error_stacks(t_opts *opts, t_stack **a)
{
	if (opts)
	{
		opts->file = 0;
		opts->view = 0;
	}
	if (a)
		del_list(a);
	ft_putendl_fd("Error", 2);
	exit(3);
}
