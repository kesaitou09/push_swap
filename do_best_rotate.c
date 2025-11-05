/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 02:17:15 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/06 06:21:26 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	double_rotate(t_ring_buff *a, t_ring_buff *b, t_move *m)
{
	while (m->a_cost > 0 && m->b_cost > 0)
	{
		rr(a, b);
		m->a_cost--;
		m->b_cost--;
	}
	while (m->a_cost < 0 && m->b_cost < 0)
	{
		rrr(a, b);
		m->a_cost++;
		m->b_cost++;
	}
}

void	apply_move(t_ring_buff *a, t_ring_buff *b, t_move m)
{
	double_rotate(a, b, &m);
	while (m.a_cost > 0)
	{
		ra(a, 1);
		m.a_cost--;
	}
	while (m.a_cost < 0)
	{
		rra(a, 1);
		m.a_cost++;
	}
	while (m.b_cost > 0)
	{
		rb(b, 1);
		m.b_cost--;
	}
	while (m.b_cost < 0)
	{
		rrb(b, 1);
		m.b_cost++;
	}
	pa(a, b);
}

void	rotate_a_to(t_ring_buff *a, int pos)
{
	int	ca;

	if (a->size <= 1)
		return ;
	ca = calc_cost(pos, a->size);
	while (ca > 0)
	{
		ra(a, 1);
		ca--;
	}
	while (ca < 0)
	{
		rra(a, 1);
		ca++;
	}
}
