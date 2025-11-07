/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate_two.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 06:36:27 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/07 10:42:01 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rra(t_ring *a, int print)
{
	int	tmp;
	int	tail;

	if (a->size < 2)
		return (ERROR);
	tail = (a->head + a->size - 1) % a->cap;
	tmp = a->buff[tail];
	a->head = (a->head - 1 + a->cap) % a->cap;
	a->buff[a->head] = tmp;
	if (print)
		write(1, "rra\n", 4);
	return (SUCCESS);
}

int	rrb(t_ring *b, int print)
{
	int	tmp;
	int	tail;

	if (b->size < 2)
		return (ERROR);
	tail = (b->head + b->size - 1) % b->cap;
	tmp = b->buff[tail];
	b->head = (b->head - 1 + b->cap) % b->cap;
	b->buff[b->head] = tmp;
	if (print)
		write(1, "rrb\n", 4);
	return (SUCCESS);
}

int	rrr(t_ring *a, t_ring *b, int print)
{
	if (a->size < 2 || b->size < 2)
		return (ERROR);
	rra(a, 0);
	rrb(b, 0);
	if (print)
		write(1, "rrr\n", 4);
	return (SUCCESS);
}
