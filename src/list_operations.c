/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 17:38:39 by aolen             #+#    #+#             */
/*   Updated: 2019/11/03 17:38:39 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

t_stack		*add_el(int content, t_stack **start)
{
	t_stack	*first_el;

	if (!*start)
	{
		*start = ft_memalloc(sizeof(**start));
		(*start)->num = content;
		(*start)->next = NULL;
		(*start)->prev = NULL;
	}
	else
	{
		first_el = ft_memalloc(sizeof(**start));
		first_el->num = content;
		first_el->next = *start;
		first_el->prev = NULL;
		(*start)->prev = first_el;
		*start = first_el;
	}
	return (*start);
}

t_stack		*push_el(int content, t_stack **start)
{
	t_stack	*first_el;

	if (!*start)
	{
		*start = ft_memalloc(sizeof(**start));
		(*start)->num = content;
		(*start)->next = NULL;
		(*start)->prev = NULL;
	}
	else
	{
		first_el = *start;
		while (first_el->next)
			first_el = first_el->next;
		first_el->next = ft_memalloc(sizeof(**start));
		first_el->next->num = content;
		first_el->next->next = NULL;
		first_el->next->prev = first_el;
	}
	return (*start);
}

int			lst_len(t_stack *begin)
{
	int i;

	i = 0;
	while (begin)
	{
		++i;
		begin = begin->next;
	}
	return (i);
}

int			del_list(t_stack **top)
{
	t_stack *temp;

	while (*top)
	{
		temp = (*top)->next;
		free(*top);
		*top = temp;
	}
	*top = NULL;
	return (0);
}

t_stack		*lst_find(t_stack *top, int val)
{
	while (top)
	{
		if (top->num == val)
			return (top);
	}
	return (NULL);
}
