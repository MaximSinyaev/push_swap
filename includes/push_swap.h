/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 17:37:03 by aolen             #+#    #+#             */
/*   Updated: 2019/11/03 17:37:03 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define PRINT_FLAG 1

# include "ft_printf.h"
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>


# ifndef INT32_MAX
#  define INT32_MAX __INT32_MAX__
# endif

typedef struct		s_stack
{
	int				num;
	int				cost;
	int				pos;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct		s_stack_ptr
{
	struct s_stack	*top;
	struct s_stack	*bot;
	int				len;
	int				max;
	int				min;
}					t_stack_ptr;

typedef struct		s_median
{
	int				value;
	int				pos_number;
	t_stack			*pos;
}					t_median;

typedef struct		s_opts
{
	int				view;
	int				file;
	char			*filename;
	int				start_pos;
}					t_opts;

void				handle_error(void);
void				handle_error_args(t_opts *opts, t_stack_ptr **a,
					t_stack_ptr **b);
void				handle_error_stacks(t_opts *opts, t_stack **a);

t_stack				*add_el(int content, t_stack **start);
int					del_list(t_stack **top);
int					lst_len(t_stack *begin);
t_stack				*lst_find(t_stack *top, int val);

void				sa(t_stack **a, int p_flag);
void				sb(t_stack **b, int p_flag);
void				ss(t_stack **a, t_stack **b, int p_flag);
void				print_stacks(t_stack *a, t_stack *b);
void				print_stacks_with_operations(t_stack *a, t_stack *b,
												char *operation);
void				pa(t_stack **a, t_stack **b, int p_flag);
void				pb(t_stack **a, t_stack **b, int p_flag);
void				ra(t_stack **a, int p_flag);
void				rb(t_stack **b, int p_flag);
void				rr(t_stack **a, t_stack **b, int p_flag);
void				rra(t_stack **a, int p_flag);
void				rrb(t_stack **b, int p_flag);
void				rrr(t_stack **a, t_stack **b, int p_flag);
int					check_stacks(t_stack *a, t_stack *b);
void				read_args(int i, int ac, char **av, t_stack **a);
void				read_args_from_file(t_opts *opts, t_stack_ptr *a);
void				refresh_stacks_info(t_stack_ptr *a, t_stack_ptr *b);
void				refresh_stack_info(t_stack_ptr *stack);
t_stack				*push_el(int content, t_stack **start);
int					ft_getopt(int ac, char **av, t_opts *opts);

struct s_median		*search_and_parse_median(t_stack_ptr *stack, int part_size);
int					check_order(t_stack_ptr *stack_ptr);
t_stack				*find_cheapest_element(t_stack_ptr *a, t_stack_ptr *b);
t_stack				*search_max(t_stack_ptr *stack);
void				sort_stack_r(t_stack_ptr *a, t_stack_ptr *b);

void				clean_stack_ptr(t_stack_ptr **stack_ptr);
void				clean_stack_ptrs(t_stack_ptr **stack_ptr1,
					t_stack_ptr **stack_ptr2);
void				clean_median(t_median **median_el);

void				print_initial_stacks(t_stack *a_top, t_stack *b_top,
					int v_flag);
void				print_result_stacks(t_stack *a_top, t_stack *b_top,
					int v_flag);
#endif
