/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 06:33:51 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/07 10:42:01 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pa(t_ring *ring_a, t_ring *ring_b, int print)
{
	int	x;

	if (ring_b->size == 0)
		return (ERROR);
	x = ring_b->buff[ring_b->head];
	ring_b->head = (ring_b->head + 1) % ring_b->cap;
	ring_b->size--;
	ring_a->head = (ring_a->head - 1 + ring_a->cap) % ring_a->cap;
	ring_a->buff[ring_a->head] = x;
	ring_a->size++;
	if (print)
		write(1, "pa\n", 3);
	return (SUCCESS);
}

int	pb(t_ring *a, t_ring *b, int print)
{
	int	x;

	if (a->size == 0)
		return (ERROR);
	x = a->buff[a->head];
	a->head = (a->head + 1) % a->cap;
	a->size--;
	b->head = (b->head - 1 + b->cap) % b->cap;
	b->buff[b->head] = x;
	b->size++;
	if (print)
		write(1, "pb\n", 3);
	return (SUCCESS);
}
