/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 22:58:57 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/06 00:22:37 by kesaitou         ###   ########.fr       */
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
		if (for_lis->lis_tab[i] == 1)
			ra(a, 1);
		else
		{
			pb(a, b);
		}
		// if (search_listab(for_lis, i + 1, n) == 0)
		// 	break ;
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

int	sort_less_than_six(t_ring_buff *ring_a, t_ring_buff *ring_b)
{
	int	n;

	if (ring_a->size <= 3)
	{
		if (sort_three(ring_a) == ERROR)
			return (ERROR);
	}
	else if (ring_a->size <= 5)
	{
		n = ring_a->size - 3;
		while (n--)
		{
			if (pb(ring_a, ring_b) == ERROR)
				return (ERROR);
		}
		if (sort_three(ring_a) == ERROR)
			return (ERROR);
		sort_from_b(ring_a, ring_b);
	}
	return (SUCCESS);
}

int	controll_sort(t_ring_buff *ring_a, t_ring_buff *ring_b)
{
	if (is_ascending(ring_a))
		return (SUCCESS);
	if (ring_a->size <= 5)
	{
		if (make_stackb(ring_a, ring_b) == ERROR)
			return (ERROR);
		sort_less_than_six(ring_a, ring_b);
	}
	else
	{
		if (sort_process(ring_a, ring_b) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}

int	sort_process(t_ring_buff *ring_a, t_ring_buff *ring_b)
{
	t_buff	for_lis;

	if (init_forlis(&for_lis, ring_a, ring_a->size) == ERROR)
		return (ERROR);
	if (make_stackb(ring_a, ring_b) == ERROR)
		return (ERROR);
	lis(ring_a, &for_lis);
	if (push_nonlis(&for_lis, ring_a, ring_b) == ERROR)
		return (ERROR);
	sort_from_b(ring_a, ring_b);
	return (SUCCESS);
}
