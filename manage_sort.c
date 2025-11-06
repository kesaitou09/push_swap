/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 06:25:38 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/06 07:23:22 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	make_stackb(t_ring_buff *ring_a, t_ring_buff *ring_b)
{
	ring_b->cap = ring_a->cap;
	ring_b->buff = malloc(sizeof(int) * (ring_b->cap));
	if (!ring_b->buff)
		return (ERROR);
	ring_b->head = 0;
	ring_b->size = 0;
	return (SUCCESS);
}

int	sort_five(t_ring_buff *ring_a, t_ring_buff *ring_b)
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

int	manage_sort(t_ring_buff *ring_a, t_ring_buff *ring_b)
{
	if (is_ascending(ring_a))
		return (SUCCESS);
	if (ring_a->size <= 5)
	{
		if (make_stackb(ring_a, ring_b) == ERROR)
			return (ERROR);
		if (sort_five(ring_a, ring_b) == ERROR)
			return (free(ring_b->buff), ERROR);
	}
	else
	{
		if (sort_process(ring_a, ring_b) == ERROR)
			return (free(ring_b->buff), ERROR);
	}
	free(ring_b->buff);
	return (SUCCESS);
}

int	sort_process(t_ring_buff *ring_a, t_ring_buff *ring_b)
{
	t_buff	for_lis;

	if (init_forlis(&for_lis, ring_a->size) == ERROR)
		return (ERROR);
	if (make_stackb(ring_a, ring_b) == ERROR)
		return ((free_all(&for_lis)), ERROR);
	lis(ring_a, &for_lis);
	if (push_nonlis(&for_lis, ring_a, ring_b) == ERROR)
		return (ERROR);
	free_all(&for_lis);
	sort_from_b(ring_a, ring_b);
	return (SUCCESS);
}
