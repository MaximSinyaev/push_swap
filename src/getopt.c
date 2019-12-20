/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getopt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 17:58:35 by aolen             #+#    #+#             */
/*   Updated: 2019/12/15 17:58:35 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Func getopt
**	------------------
**	Get options from args
**
**	Returns number of args with options
*/

int	ft_getopt(int ac, char **av, t_opts *opts)
{
	int i;

	i = 0;
	while (++i < ac)
	{
		if (av[i][0] == '-')
		{
			if (av[i][1] == 'v')
				opts->view = 1;
			else if (av[i][1] == 'f')
			{
				opts->file = 1;
				opts->filename = ft_strdup(av[++i]);
			}
			else if (!ft_isdigit(av[i][1]))
				handle_error_args(opts, NULL, NULL);
			else
				break ;
		}
		else
			break ;
	}
	return (opts->file ? ac : i - 1);
}
