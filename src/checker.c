/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 14:06:23 by aolen             #+#    #+#             */
/*   Updated: 2019/11/03 14:06:23 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"
#define PRINT_FLAG_CHECKER 0

void	read_instructions(t_stack **a, t_stack **b, char **line)
{
	if (ft_strequ("sa", *line))
		sa(a, PRINT_FLAG_CHECKER);
	else if (ft_strequ("sb", *line))
		sb(b, PRINT_FLAG_CHECKER);
	else if (ft_strequ("ss", *line))
		ss(a, b, PRINT_FLAG_CHECKER);
	else if (ft_strequ("pa", *line))
		pa(a, b, PRINT_FLAG_CHECKER);
	else if (ft_strequ("pb", *line))
		pb(a, b, PRINT_FLAG_CHECKER);
	else if (ft_strequ("ra", *line))
		ra(a, PRINT_FLAG_CHECKER);
	else if (ft_strequ("rb", *line))
		rb(b, PRINT_FLAG_CHECKER);
	else if (ft_strequ("rr", *line))
		rr(a, b, PRINT_FLAG_CHECKER);
	else if (ft_strequ("rra", *line))
		rra(a, PRINT_FLAG_CHECKER);
	else if (ft_strequ("rrb", *line))
		rrb(b, PRINT_FLAG_CHECKER);
	else if (ft_strequ("rrr", *line))
		rrr(a, b, PRINT_FLAG_CHECKER);
	else
		handle_error();
}

void	print_result(t_opts opts, t_stack_ptr *a, t_stack_ptr *b)
{
	print_result_stacks(a->top, b->top, opts.view);
	if (check_stacks((a->top), (b->top)))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int		main(int ac, char **av)
{
	t_stack_ptr *a;
	t_stack_ptr *b;
	t_opts		opts;
	char		*line;

	a = ft_memalloc(sizeof(*a));
	b = ft_memalloc(sizeof(*b));
	opts.start_pos = ft_getopt(ac, av, &opts);
	if (opts.file)
		read_args_from_file(&opts, a);
	else
		read_args(opts.start_pos, ac, av, &(a->top));
	if (!a->top)
		exit(0);
	print_initial_stacks(a->top, b->top, opts.view);
	while (get_next_line(0, &line))
	{
		read_instructions(&(a->top), &(b->top), &line);
		if (opts.view)
			print_stacks_with_operations((a->top), (b->top), line);
		free(line);
	}
	print_result(opts, a, b);
	clean_stack_ptrs(&a, &b);
	return (0);
}
