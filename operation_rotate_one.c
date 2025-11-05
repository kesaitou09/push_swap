/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate_one.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 00:06:25 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/06 06:36:25 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_ring_buff *a, int how)
{
	int	tmp;
	int	tail;

	if (a->size < 2)
		return (SUCCESS);
	tmp = a->buff[a->head];
	a->head = (a->head + 1) % a->cap;
	tail = (a->head + a->size - 1) % a->cap;
	a->buff[tail] = tmp;
	if (how)
		write(1, "ra\n", 3);
	return (0);
}

int	rb(t_ring_buff *b, int how)
{
	int	tmp;
	int	tail;

	if (b->size < 2)
		return (SUCCESS);
	tmp = b->buff[b->head];
	b->head = (b->head + 1) % b->cap;
	tail = (b->head + b->size - 1) % b->cap;
	b->buff[tail] = tmp;
	if (how)
		write(1, "rb\n", 3);
	return (0);
}

int	rr(t_ring_buff *a, t_ring_buff *b)
{
	ra(a, 0);
	rb(b, 0);
	write(1, "rr\n", 3);
	return (SUCCESS);
}
