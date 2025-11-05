/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 06:33:05 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/06 06:44:45 by kesaitou         ###   ########.fr       */
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
	int	succ_a;

	succ_a = swap_top(ring_a);
	if (succ_a == SUCCESS)
	{
		write(1, "sa\n", 3);
	}
	return (SUCCESS);
}

int	sb(t_ring_buff *ring_b)
{
	int	succ_b;

	succ_b = swap_top(ring_b);
	if (succ_b == SUCCESS)
	{
		write(1, "sb\n", 3);
	}
	return (SUCCESS);
}

int	ss(t_ring_buff *ring_a, t_ring_buff *ring_b)
{
	int	succ_a;
	int	succ_b;

	succ_a = swap_top(ring_a);
	succ_b = swap_top(ring_b);
	if (succ_a == SUCCESS && succ_b == SUCCESS)
	{
		write(1, "ss\n", 3);
	}
	return (SUCCESS);
}
