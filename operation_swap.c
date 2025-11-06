/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaitou <ksaitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 06:33:05 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/06 13:38:55 by ksaitou          ###   ########.fr       */
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

int	sa(t_ring_buff *ring_a, int print)
{
	int	succ_a;

	succ_a = swap_top(ring_a);
	if (succ_a == SUCCESS && print)
	{
		write(1, "sa\n", 3);
	}
	else
		return (ERROR);
	return (SUCCESS);
}

int	sb(t_ring_buff *ring_b, int print)
{
	int	succ_b;

	succ_b = swap_top(ring_b);
	if (succ_b == SUCCESS && print)
	{
		write(1, "sb\n", 3);
	}
	else
		return (ERROR);
	return (SUCCESS);
}

int	ss(t_ring_buff *ring_a, t_ring_buff *ring_b, int print)
{
	int	succ_a;
	int	succ_b;

	succ_a = swap_top(ring_a);
	succ_b = swap_top(ring_b);
	if (succ_a == SUCCESS && succ_b == SUCCESS && print)
	{
		write(1, "ss\n", 3);
	}
	else
		return (ERROR);
	return (SUCCESS);
}
