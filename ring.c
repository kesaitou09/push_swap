/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ring.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 07:08:57 by kesaitou          #+#    #+#             */
/*   Updated: 2025/10/31 16:50:57 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ring_load(t_ring_buff *r, int *rank, int n)
{
	int	i;

	i = 0;
	if (!r->buff, n < 0 || n > r->cap)
		return (ERROR);
	while (i < n)
	{
		r->buff[i] = rank[i];
		i++;
	}
	r->size = n;
	r->head = 0;
	return (SUCCESS);
}

int	create_ring(t_ring_buff *r_buff)
{
	int	*rank;

	rank = malloc(sizeof(int) * r_buff->size);
	if (!rank)
		return (ERROR);
	if (grant_rank(*r_buff, rank) == ERROR)
		return (ERROR);
	if (ring_load(r_buff, rank, r_buff->size) == ERROR)
		return (ERROR);
}

void	make_stackb(t_ring_buff *ring_b, int size)
{
	ring_b->buff = malloc(sizeof(int) * (size));
	if (!ring_b->buff)
		return (NULL);
	ring_b->ind = NULL;
	ring_b->head = 0;
	ring_b->cap = 0;
	ring_b->size = 0;
}
