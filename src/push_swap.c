/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:42:38 by aolen             #+#    #+#             */
/*   Updated: 2019/11/06 12:42:41 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		split_stack_part_2(t_stack_ptr *a, t_stack_ptr *b,
		t_median *median, int *k)
{
	if (a->top->num <= median->value)
	{
		pb(&(a->top), &(b->top), PRINT_FLAG);
		if (b->top->num > b->max)
			b->max = b->top->num;
		if (b->top->num < b->min)
			b->min = b->top->num;
		++(*k);
	}
	else
	{
		if (b->top && (b->top->num < (b->max + b->min) / 2))
			rr(&(a->top), &(b->top), PRINT_FLAG);
		else
			ra(&(a->top), PRINT_FLAG);
	}
}

/*
** Func split_stack:
**		Split stack A moving part_size elements to stack B, that bigger
**		or equal to median value*
**			*median value - value that equal to part_size value
**			in sorted stack in descending order
*/

void			split_stack(t_stack_ptr *a, t_stack_ptr *b, int part_size)
{
	int			i;
	int			k;
	t_median	*median;

	i = -1;
	k = 0;
	median = search_and_parse_median(a, part_size);
	part_size = part_size > 1 ? median->pos_number : (a->len) / 2;
	while (++i < a->len && k < part_size)
		split_stack_part_2(a, b, median, &k);
	clean_median(&median);
	refresh_stack_info(a);
	refresh_stack_info(b);
}

/*
** Func restore_order:
** -----------------------------
**		Restore order of stack A by moving min element in head of stack A
*/

static void		restore_order(t_stack_ptr *stack)
{
	if (ABS(stack->top->num - stack->min) > ABS(stack->bot->num - stack->min))
		while (stack->top->num != stack->min)
			rra(&stack->top, PRINT_FLAG);
	else
		while (stack->top->num != stack->min)
			ra(&stack->top, PRINT_FLAG);
}

int				main(int ac, char **av)
{
	t_stack_ptr		*a;
	t_stack_ptr		*b;
	t_opts			opts;

	a = ft_memalloc(sizeof(*a));
	b = ft_memalloc(sizeof(*b));
	opts.start_pos = ft_getopt(ac, av, &opts);
	if (opts.file)
		read_args_from_file(&opts, a);
	else
		read_args(opts.start_pos, ac, av, &(a->top));
	if (opts.view)
		handle_error_args(&opts, &a, &b);
	if (!a->top || ((a->top) && !a->top->next) || check_stacks(a->top, b->top))
		exit(0);
	refresh_stacks_info(a, b);
	while (a->len > 3)
		split_stack(a, b, 0);
	sort_stack_r(a, b);
	restore_order(a);
	clean_stack_ptrs(&a, &b);
	return (0);
}
