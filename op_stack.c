/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 02:17:15 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/05 21:51:43 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	my_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

static int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

static int	idx_min_logical(t_ring_buff *a)
{
	int	i;
	int	imin;
	int	vmin;
	int	v;

	imin = 0;
	vmin = VAL(a, 0);
	i = 1;
	while (i < a->size)
	{
		v = VAL(a, i);
		if (v < vmin)
		{
			vmin = v;
			imin = i;
		}
		i++;
	}
	return (imin);
}

static int	max_val(t_ring_buff *a)
{
	int	i;
	int	vmax;
	int	v;

	vmax = VAL(a, 0);
	i = 1;
	while (i < a->size)
	{
		v = VAL(a, i);
		if (v > vmax)
			vmax = v;
		i++;
	}
	return (vmax);
}

static int	same_sign(int a, int b)
{
	if ((a >= 0 && b >= 0) || (a < 0 && b < 0))
		return (1);
	return (0);
}

static int	merged_cost(int a_cost, int b_cost)
{
	if (same_sign(a_cost, b_cost) == 1)
		return (max(my_abs(a_cost), my_abs(b_cost)));
	return (my_abs(a_cost) + my_abs(b_cost));
}

static int	calc_cost(int idx, int size)
{
	if (idx <= size / 2)
		return (idx);
	return (idx - size);
}

static void	init_tmove(t_move *best)
{
	best->a_cost = 0;
	best->b_cost = 0;
	best->id_sb = 0;
	best->pos_a = 0;
	best->cost = INT_MAX;
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

void	apply_move(t_ring_buff *a, t_ring_buff *b, t_move m)
{
	while (m.a_cost > 0 && m.b_cost > 0)
	{
		rr(a, b);
		m.a_cost--;
		m.b_cost--;
	}
	while (m.a_cost < 0 && m.b_cost < 0)
	{
		rrr(a, b);
		m.a_cost++;
		m.b_cost++;
	}
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

int	pos_in_a_for(t_ring_buff *a, int b)
{
	int	i;
	int	imin;
	int	vmin;
	int	vmax;
	int	prev;
	int	cur;

	if (a->size == 0)
		return (0);
	if (a->size == 1)
		return ((VAL(a, 0) < b) ? 1 : 0);
	imin = idx_min_logical(a);
	vmin = VAL(a, imin);
	vmax = max_val(a);
	if (b < vmin || b > vmax)
		return (imin);
	i = 0;
	while (i < a->size)
	{
		prev = VAL(a, (i - 1 + a->size) % a->size);
		cur = VAL(a, i);
		if (prev < b && b < cur)
			return (i);
		i++;
	}
	return (imin);
}

static void	rotate_a_to(t_ring_buff *a, int pos)
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

void	insert_top_b_into_a_minops(t_ring_buff *a, t_ring_buff *b)
{
	int	bval;
	int	pos;

	if (b->size == 0)
		return ;
	bval = b->buff[b->head];
	pos = pos_in_a_for(a, bval);
	rotate_a_to(a, pos);
	pa(a, b);
}

void	finish_rotate_min_to_top(t_ring_buff *a)
{
	int	pos;

	if (a->size == 0)
		return ;
	pos = idx_min_logical(a);
	rotate_a_to(a, pos);
}

void	sort_from_b(t_ring_buff *a, t_ring_buff *b)
{
	t_move	m;
	t_move	best;

	init_tmove(&best);
	while (b->size > 0)
	{
		m = best_move(a, b, best);
		apply_move(a, b, m);
	}
	finish_rotate_min_to_top(a);
}
