/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 05:24:40 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/06 06:19:20 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	merged_cost(int a_cost, int b_cost)
{
	if (same_sign(a_cost, b_cost) == 1)
		return (max(my_abs(a_cost), my_abs(b_cost)));
	return (my_abs(a_cost) + my_abs(b_cost));
}

int	calc_cost(int idx, int size)
{
	if (idx <= size / 2)
		return (idx);
	return (idx - size);
}

t_move	best_move(t_ring_buff *a, t_ring_buff *b, t_move best)
{
	int	id_sb;
	int	bval;
	int	pos;
	int	c;

	id_sb = 0;
	while (id_sb < b->size)
	{
		bval = VAL(b, id_sb);
		pos = pos_in_a_for(a, bval);
		c = merged_cost(calc_cost(pos, a->size), calc_cost(id_sb, b->size));
		if (c < best.cost)
		{
			best.id_sb = id_sb;
			best.pos_a = pos;
			best.a_cost = calc_cost(pos, a->size);
			best.b_cost = calc_cost(id_sb, b->size);
			best.cost = c;
		}
		id_sb++;
	}
	return (best);
}

int	pos_in_a_for(t_ring_buff *a, int b)
{
	if (a->size == 0)
		return (0);
	if (a->size == 1)
	{
		if (VAL(a, 0) < b)
			return (1);
		else
			return (0);
	}
	return (search_position(a, b));
}

int	search_position(t_ring_buff *ring_a, int b)
{
	int	i;
	int	cur;
	int	prev;
	int	idx_min;

	i = 0;
	idx_min = idx_min_logical(ring_a);
	if (b < VAL(ring_a, idx_min) || b > max_val(ring_a))
		return (idx_min);
	while (i < ring_a->size)
	{
		prev = VAL(ring_a, (i - 1 + ring_a->size) % ring_a->size);
		cur = VAL(ring_a, i);
		if (prev < b && b < cur)
			return (i);
		i++;
	}
	return (idx_min);
}
