/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ring.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 07:08:57 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/04 15:41:52 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	create_ring(t_ring_buff *ring_a)
{
	int	*rank;

	rank = malloc(sizeof(int) * ring_a->size);
	if (!rank)
		return (ERROR);
	if (grant_rank(*ring_a, rank) == ERROR)
		return (ERROR);
	if (ring_load(ring_a, rank, ring_a->size) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int	grant_rank(t_ring_buff ring_a, int *rank)
{
	size_t	i;
	int		r;

	i = 0;
	r = 0;
	if (rank_helper(ring_a, rank, i, r) == ERROR)
		return (ERROR);
	return (1);
}

int	rank_helper(t_ring_buff ring_a, int *rank, int i, int r)
{
	int	j;
	int	vi;
	int	vj;

	while (i < ring_a.size)
	{
		vi = ring_a.buff[(ring_a.head + i) % ring_a.cap];
		j = 0;
		r = 0;
		while (j < ring_a.size)
		{
			vj = ring_a.buff[(ring_a.head + j) % ring_a.cap];
			if (i != j && vi == vj)
				return (ERROR);
			if (vj < vi)
				r++;
			j++;
		}
		rank[i] = r;
		i++;
	}
	return (1);
}

int	ring_load(t_ring_buff *ring_a, int *rank, int n)
{
	int	i;

	i = 0;
	if (!ring_a->buff || n < 0 || n > ring_a->cap)
		return (ERROR);
	while (i < n)
	{
		ring_a->buff[i] = rank[i];
		i++;
	}
	ring_a->head = 0;
	ring_a->size = n;
	return (SUCCESS);
}

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
