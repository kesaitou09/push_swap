/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 00:06:25 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/04 00:17:37 by kesaitou         ###   ########.fr       */
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

int	sa(t_ring_buff *ring_a, int *total)
{
	int	succ_a;

	succ_a = swap_top(ring_a);
	if (succ_a == SUCCESS)
	{
		write(1, "sa\n", 3);
		(*total)++;
	}
	return (SUCCESS);
}

int	sb(t_ring_buff *ring_b, int *total)
{
	int	succ_b;

	succ_b = swap_top(ring_b);
	if (succ_b == SUCCESS)
	{
		write(1, "sb\n", 3);
		(*total)++;
	}
	return (SUCCESS);
}

int	ss(t_ring_buff *ring_a, t_ring_buff *ring_b, int *total)
{
	int	succ_a;
	int	succ_b;

	succ_a = swap_top(ring_a);
	succ_b = swap_top(ring_b);
	if (succ_a == SUCCESS || succ_b == SUCCESS)
	{
		write(1, "ss\n", 3);
		(*total)++;
	}
	return (SUCCESS);
}

int	pa(t_ring_buff *ring_a, t_ring_buff *ring_b, int *total)
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
	(*total)++;
	write(1, "pa\n", 3);
	return (SUCCESS);
}

int	pb(t_ring_buff *a, t_ring_buff *b, int *total)
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
	(*total)++;
	write(1, "pb\n", 3);
	return (SUCCESS);
}

int	ra(t_ring_buff *a, int *total, int how)
{
	int	tmp;
	int	tail;

	if (a->size < 2)
		return (SUCCESS);
	tmp = a->buff[a->head];
	a->head = (a->head + 1) % a->cap;
	tail = (a->head + a->size - 1) % a->cap;
	a->buff[tail] = tmp;
	(*total)++;
	if (how)
		write(1, "ra\n", 3);
	return (0);
}

int	rb(t_ring_buff *b, int *total, int how)
{
	int	tmp;
	int	tail;

	if (b->size < 2)
		return (SUCCESS);
	tmp = b->buff[b->head];
	b->head = (b->head + 1) % b->cap;
	tail = (b->head + b->size - 1) % b->cap;
	b->buff[tail] = tmp;
	(*total)++;
	if (how)
		write(1, "ra\n", 3);
	return (0);
}

int	rr(t_ring_buff *a, t_ring_buff *b, int *total)
{
	ra(a, total, 0);
	rb(b, total, 0);
	write(1, "rr\n", 3);
	return (SUCCESS);
}

int	rra(t_ring_buff *a, int *total, int how)
{
	int	tmp;
	int	tail;

	tail = (a->head + a->size - 1) % a->cap;
	tmp = a->buff[tail];
	if (a->size < 2)
		return (SUCCESS);
	a->head = (a->head - 1 + a->cap) % a->cap;
	a->buff[a->head] = tmp;
	(*total)++;
	if (how)
		write(1, "rra\n", 4);
	return (SUCCESS);
}

int	rrb(t_ring_buff *b, int *total, int how)
{
	int	tmp;
	int	tail;

	tail = (b->head + b->size - 1) % b->cap;
	tmp = b->buff[tail];
	if (b->size < 2)
		return (SUCCESS);
	b->head = (b->head - 1 + b->cap) % b->cap;
	b->buff[b->head] = tmp;
	(*total)++;
	if (how)
		write(1, "rrb\n", 4);
	return (SUCCESS);
}

int	rrr(t_ring_buff *a, t_ring_buff *b, int *total)
{
	if (a->size < 2 || b->size < 2)
		return (SUCCESS);
	rra(a, total, 0);
	rrb(b, total, 0);
	write(1, "rrr\n", 4);
	return (SUCCESS);
}
