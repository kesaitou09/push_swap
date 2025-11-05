/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate_two.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 06:36:27 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/06 06:36:38 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rra(t_ring_buff *a, int how)
{
	int	tmp;
	int	tail;

	tail = (a->head + a->size - 1) % a->cap;
	tmp = a->buff[tail];
	if (a->size < 2)
		return (SUCCESS);
	a->head = (a->head - 1 + a->cap) % a->cap;
	a->buff[a->head] = tmp;
	if (how)
		write(1, "rra\n", 4);
	return (SUCCESS);
}

int	rrb(t_ring_buff *b, int how)
{
	int	tmp;
	int	tail;

	tail = (b->head + b->size - 1) % b->cap;
	tmp = b->buff[tail];
	if (b->size < 2)
		return (SUCCESS);
	b->head = (b->head - 1 + b->cap) % b->cap;
	b->buff[b->head] = tmp;
	if (how)
		write(1, "rrb\n", 4);
	return (SUCCESS);
}

int	rrr(t_ring_buff *a, t_ring_buff *b)
{
	if (a->size < 2 || b->size < 2)
		return (SUCCESS);
	rra(a, 0);
	rrb(b, 0);
	write(1, "rrr\n", 4);
	return (SUCCESS);
}
