/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:08:50 by aolen             #+#    #+#             */
/*   Updated: 2019/11/06 13:08:50 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"
#include <limits.h>

static int	check_arg(char *arg)
{
	long	temp;
	char	*double_convert;
	char	*ptr;
	int		i;
	int		len;

	ptr = arg;
	i = -1;
	len = ft_strlen(arg);
	if (len > 19)
		handle_error();
	while (arg[++i])
		if (!ft_isdigit(arg[i]))
		{
			if (i == 0 && (*arg == '+' || *arg == '-') && len > 1 && len < 19)
				continue ;
			handle_error();
		}
	temp = ft_atol(ptr);
	double_convert = ft_ltoa(temp);
	if (temp > INT_MAX || temp < INT_MIN)
		handle_error();
	ft_strdel(&double_convert);
	return ((int)temp);
}

static int	check_repeats(t_stack *a)
{
	t_stack	*temp;
	t_stack *list_iter;

	temp = a;
	while (temp)
	{
		list_iter = a;
		while (list_iter)
		{
			if ((list_iter != temp) && (list_iter->num == temp->num))
				return (1);
			list_iter = list_iter->next;
		}
		temp = temp->next;
	}
	return (0);
}

void		read_args(int i, int ac, char **av, t_stack **a)
{
	int		j;
	char	**splited_args;

	while (++i < ac)
	{
		j = -1;
		splited_args = ft_strsplit(av[i], ' ');
		while (splited_args[++j])
		{
			push_el(check_arg(splited_args[j]), a);
			free(splited_args[j]);
		}
		free(splited_args);
	}
	if (check_repeats(*a))
		handle_error_stacks(NULL, a);
}

void		read_args_from_file(t_opts *opts, t_stack_ptr *a)
{
	int		fd;
	int		j;
	char	*line;
	char	**splited_args;

	fd = opts->file ? open(opts->filename, O_RDONLY) : 0;
	while ((j = get_next_line(fd, &line)) > 0)
	{
		j = -1;
		splited_args = ft_strsplit(line, ' ');
		while (splited_args[++j])
		{
			push_el(check_arg(splited_args[j]), &(a->top));
			free(splited_args[j]);
		}
		free(splited_args);
		free(line);
	}
	if (check_repeats(a->top))
		handle_error_args(opts, &a, NULL);
	free(opts->filename);
	if (j < 0)
		handle_error();
}
