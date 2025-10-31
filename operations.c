/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 00:06:25 by kesaitou          #+#    #+#             */
/*   Updated: 2025/10/31 15:52:28 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_top(t_ring_buff *r)
{
	int	i;
	int	j;
	int	tmp;

	if (r->size < 2)
		return (ERROR);
	i = r->head;
	j = (r->head + 1) % r->cap;
	tmp = r->buff[i];
	r->buff[i] = r->buff[j];
	r->buff[j] = tmp;
	return (SUCCESS);
}

int	sa(t_ring_buff *ring_a)
{
	swap_top(ring_a);
	write(1, "sa\n", 3);
	return (SUCCESS);
}

int	sb(t_ring_buff *ring_b)
{
	swap_top(ring_b);
	write(1, "sb\n", 3);
	return (SUCCESS);
}

int	ss(t_ring_buff *ring_a, t_ring_buff *ring_b)
{
	int	succ_a;
	int	succ_b;

	succ_a = swap_top(ring_a);
	succ_b = swap_top(ring_b);
	if (succ_a || succ_b)
		write(1, "ss\n", 3);
	return (SUCCESS);
}

int	pa(t_ring_buff *ring_a, t_ring_buff *ring_b)
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
	write(1, "pa\n", 3);
	return (SUCCESS);
}

int	pb(t_ring_buff *a, t_ring_buff *b)
{
	int	x;

	if (b->size == 0)
		return (ERROR);
	x = a->buff[a->head];
	a->head = (a->head + 1) % a->cap;
	a->size--;
	b->head = (b->head - 1 + b->cap) % a->cap;
	b->buff[b->head] = x;
	b->size++;
	write(1, "pb\n", 3);
	return (SUCCESS);
}

int	ra(t_ring_buff *a)
{
	if (a->size < 2)
		return (SUCCESS);
	a->head = (a->head + 1) % a->cap;
	write(1, "ra\n", 3);
	return (0);
}

int	rb(t_ring_buff *b)
{
	if (b->size < 2)
		return (SUCCESS);
	b->head = (b->head + 1) % b->cap;
	write(1, "rb\n", 3);
	return (SUCCESS);
}

int	rra(t_ring_buff *a)
{
	if (a->size < 2)
		return (SUCCESS);
	a->head = (a->head - 1 + a->cap) % a->cap;
	write(1, "rra\n", 4);
	return (SUCCESS);
}

int	rrb(t_ring_buff *b)
{
	if (b->size < 2)
		return (SUCCESS);
	b->head = (b->head - 1 + b->cap) % b->cap;
	write(1, "rrb\n", 4);
	return (SUCCESS);
}