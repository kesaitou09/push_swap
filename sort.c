/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 22:58:57 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/04 17:07:24 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	mark_flag(t_buff *for_lis)
{
	int	k;

	k = for_lis->end;
	while (k != -1)
	{
		for_lis->lis_tab[k] = 1;
		k = for_lis->prev[k];
	}
}

int	push_nonlis(t_buff *for_lis, t_ring_buff *a, t_ring_buff *b, int *total)
{
	int	n;
	int	i;

	i = 0;
	n = for_lis->n_vals;
	while (i < n)
	{
		if (for_lis->lis_tab[i] == 1)
			ra(a, total, 1);
		else
		{
			pb(a, b, total);
		}
		// if (search_listab(for_lis, i + 1, n) == 0)
		// 	break ;
		i++;
	}
	return (SUCCESS);
}

int	sort_process(t_ring_buff *a, t_ring_buff *b)
{
	t_buff	for_lis;
	int		total;

	total = 0;
	if (init_forlis(&for_lis, a, a->size) == ERROR)
		return (ERROR);
	lis(a, &for_lis);
	if (make_stackb(a, b) == ERROR)
		return (ERROR);
	if (push_nonlis(&for_lis, a, b, &total) == ERROR)
		return (ERROR);
	sort_from_b(a, b, &total);
	return (SUCCESS);
}
