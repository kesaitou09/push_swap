/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ring.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaitou <ksaitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 07:08:57 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/03 02:28:38 by ksaitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ring_load(t_ring_buff *r, int *rank, int n)
{
	int	i;

	i = 0;
	if (!r->buff || n < 0 || n > r->cap)
		return (ERROR);
	while (i < n)
	{
		r->buff[i] = rank[i];
		i++;
	}
	r ->head = 0;
	r->size = n;
	
	return (SUCCESS);
}



int	make_stackb(t_ring_buff *ring_a , t_ring_buff *ring_b)
{
	ring_b->cap = ring_a ->cap;
	ring_b->buff = malloc(sizeof(int) * (ring_b ->cap));
	if (!ring_b->buff)
		return (ERROR);
	ring_b->ind = NULL;
	ring_b->head = 0;
	ring_b->size = 0;
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
	return (SUCCESS);
}