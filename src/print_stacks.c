/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 20:31:39 by aolen             #+#    #+#             */
/*   Updated: 2019/11/03 20:31:40 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "bash_styles.h"

void	print_numbers(t_stack *a, t_stack *b, int i, int j)
{
	while (i > 0 || j > 0)
	{
		if (i > j)
		{
			ft_printf("%s%12d%2s%s%2s%s%14s%s\n", L_MAGENTA_BG, a->num,
					"", DEFAULT_BG, "", L_CYAN_BG, "", DEFAULT_BG);
			a = a->next;
			i--;
			continue ;
		}
		else if (j > i)
		{
			ft_printf("%s%14s%s  %s%12d%2s%s \n", L_MAGENTA_BG, "",
					DEFAULT_BG, L_CYAN_BG, b->num, "", DEFAULT_BG);
			b = b->next;
			j--;
			continue ;
		}
		ft_printf("%s%12d%2s%s  %s%12d%2s%s \n", L_MAGENTA_BG,
				a->num, "", DEFAULT_BG, L_CYAN_BG, b->num, "", DEFAULT_BG);
		i--;
		j--;
		a = a->next;
		b = b->next;
	}
}

void	print_stacks_with_operations(t_stack *a, t_stack *b, char *operation)
{
	int i;
	int j;

	i = lst_len(a);
	j = lst_len(b);
	ft_printf("\e[1;1H\e[2J");
	ft_printf("______________  ______________\n");
	print_numbers(a, b, i, j);
	ft_printf("%s______________%s%2s%s______________%s\n", L_MAGENTA_BG,
			DEFAULT_BG, "", L_CYAN_BG, DEFAULT_BG);
	ft_printf("%s%14s%s%2s%s%14s%s\n", MAGENTA_BG, "", DEFAULT_BG, "",
			CYAN_BG, "", DEFAULT_BG);
	ft_printf("%s%10s%4s%s  %s%10s%4s%s\n", MAGENTA_BG, "stack A", "",
			RESET, CYAN_BG, "stack B", "", RESET);
	ft_printf("%s______________%s%2s%s______________%s\n", MAGENTA_BG,
			DEFAULT_BG, "", CYAN_BG, DEFAULT_BG);
	ft_printf("Exec: %s\n", operation);
	sleep(1);
}

void	print_stacks(t_stack *a, t_stack *b)
{
	int i;
	int j;

	i = lst_len(a);
	j = lst_len(b);
	ft_printf("\e[1;1H\e[2J");
	ft_printf("______________  ______________\n");
	print_numbers(a, b, i, j);
	ft_printf("%s______________%s%2s%s______________%s\n", L_MAGENTA_BG,
			DEFAULT_BG, "", L_CYAN_BG, DEFAULT_BG);
	ft_printf("%s%14s%s%2s%s%14s%s\n", MAGENTA_BG, "", DEFAULT_BG, "",
			CYAN_BG, "", DEFAULT_BG);
	ft_printf("%s%10s%4s%s  %s%10s%4s%s\n", MAGENTA_BG, "stack A", "",
			RESET, CYAN_BG, "stack B", "", RESET);
	ft_printf("%s______________%s%2s%s______________%s\n", MAGENTA_BG,
			DEFAULT_BG, "", CYAN_BG, DEFAULT_BG);
}
