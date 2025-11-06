/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate_one.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaitou <ksaitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 00:06:25 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/06 13:40:59 by ksaitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_ring_buff *a, int print)
{
	int	tmp;
	int	tail;

	if (a->size < 2)
		return (ERROR);
	tmp = a->buff[a->head];
	a->head = (a->head + 1) % a->cap;
	tail = (a->head + a->size - 1) % a->cap;
	a->buff[tail] = tmp;
	if (print)
		write(1, "ra\n", 3);
	return (SUCCESS);
}

int	rb(t_ring_buff *b, int print)
{
	int	tmp;
	int	tail;

	if (b->size < 2)
		return (ERROR);
	tmp = b->buff[b->head];
	b->head = (b->head + 1) % b->cap;
	tail = (b->head + b->size - 1) % b->cap;
	b->buff[tail] = tmp;
	if (print)
		write(1, "rb\n", 3);
	return (SUCCESS);
}

int	rr(t_ring_buff *a, t_ring_buff *b, int print)
{
	if (ra(a, 0) == ERROR)
		return (ERROR);
	if (rb(b, 0) == ERROR)
		return (ERROR);
	if (print)
		write(1, "rr\n", 3);
	return (SUCCESS);
}
