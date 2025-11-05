/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 22:58:57 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/06 06:26:12 by kesaitou         ###   ########.fr       */
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

int	push_nonlis(t_buff *for_lis, t_ring_buff *a, t_ring_buff *b)
{
	int	n;
	int	i;

	i = 0;
	n = for_lis->n_vals;
	while (i < n)
	{
		if (search_listab(for_lis, i, n) == 1)
			break ;
		if (for_lis->lis_tab[i] == 1)
			ra(a, 1);
		else
		{
			pb(a, b);
		}
		i++;
	}
	return (SUCCESS);
}

int	is_ascending(t_ring_buff *ring_a)
{
	int	i;

	i = 0;
	while (i < ring_a->size - 1)
	{
		if (VAL(ring_a, i) > VAL(ring_a, i + 1))
			return (0);
		i++;
	}
	return (1);
}

int	is_descending(t_ring_buff *ring_a)
{
	int	i;

	i = 0;
	while (i < ring_a->size - 1)
	{
		if (VAL(ring_a, i) < VAL(ring_a, i + 1))
			return (0);
		i++;
	}
	return (1);
}

int	sort_three(t_ring_buff *ring_a)
{
	if (is_ascending(ring_a))
		return (SUCCESS);
	if (VAL(ring_a, 0) < VAL(ring_a, 1))
	{
		if (rra(ring_a, 1) == ERROR)
			return (ERROR);
		if (!is_ascending(ring_a))
			if (sa(ring_a) == ERROR)
				return (ERROR);
	}
	else if (VAL(ring_a, 0) < VAL(ring_a, 2))
	{
		if (sa(ring_a) == ERROR)
			return (ERROR);
	}
	else
	{
		if (ra(ring_a, 1) == ERROR)
			return (ERROR);
		if (!is_ascending(ring_a))
			sa(ring_a);
	}
	return (SUCCESS);
}
