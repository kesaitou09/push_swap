/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 02:17:15 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/04 01:38:43 by kesaitou         ###   ########.fr       */
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

static int	same_sign(int a, int b)
{
	if ((a >= 0 && b >= 0) || (a < 0 && b < 0))
		return (1);
	return (0);
}

static int	merged_cost(int ca, int cb)
{
	if (same_sign(ca, cb) == 1)
		return (max(my_abs(ca), my_abs(cb)));
	return (my_abs(ca) + my_abs(cb));
}

static int	rot_cost(int idx, int n)
{
	if (idx <= n / 2)
		return (idx);
	return (idx - n);
}

static int	idx_min_logical(const t_ring_buff *a)
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

static int	max_val(const t_ring_buff *a)
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

t_move	best_move(const t_ring_buff *a, const t_ring_buff *b)
{
	t_move	best;
	int		id_sb;
	int		bval;
	int		pos;
	int		ca;
	int		cb;
	int		c;

	best.ib = 0;
	best.pos_a = 0;
	best.ca = 0;
	best.cb = 0;
	best.cost = 2147483647;
	id_sb = 0;
	while (id_sb < b->size)
	{
		bval = VAL(b, id_sb);
		pos = pos_in_a_for(a, bval);
		ca = rot_cost(pos, a->size);
		cb = rot_cost(id_sb, b->size);
		c = merged_cost(ca, cb);
		if (c < best.cost)
		{
			best.ib = id_sb;
			best.pos_a = pos;
			best.ca = ca;
			best.cb = cb;
			best.cost = c;
		}
		id_sb++;
	}
	return (best);
}

void	apply_move(t_ring_buff *a, t_ring_buff *b, t_move m, int *total)
{
	while (m.ca > 0 && m.cb > 0)
	{
		rr(a, b, total);
		m.ca--;
		m.cb--;
	}
	while (m.ca < 0 && m.cb < 0)
	{
		rrr(a, b, total);
		m.ca++;
		m.cb++;
	}
	while (m.ca > 0)
	{
		ra(a, total, 1);
		m.ca--;
	}
	while (m.ca < 0)
	{
		rra(a, total, 1);
		m.ca++;
	}
	while (m.cb > 0)
	{
		rb(b, total, 1);
		m.cb--;
	}
	while (m.cb < 0)
	{
		rrb(b, total, 1);
		m.cb++;
	}
	pa(a, b, total);
}

int	pos_in_a_for(const t_ring_buff *a, int b)
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

static void	rotate_a_to(t_ring_buff *a, int pos, int *total)
{
	int	ca;

	if (a->size <= 1)
		return ;
	ca = rot_cost(pos, a->size);
	while (ca > 0)
	{
		ra(a, total, 1);
		ca--;
	}
	while (ca < 0)
	{
		rra(a, total, 1);
		ca++;
	}
}

void	insert_top_b_into_a_minops(t_ring_buff *a, t_ring_buff *b, int *total)
{
	int	bval;
	int	pos;

	if (b->size == 0)
		return ;
	bval = b->buff[b->head];
	pos = pos_in_a_for(a, bval);
	rotate_a_to(a, pos, total);
	pa(a, b, total);
}

void	finish_rotate_min_to_top(t_ring_buff *a, int *total)
{
	int	pos;

	if (a->size == 0)
		return ;
	pos = idx_min_logical(a);
	rotate_a_to(a, pos, total);
}

void	sort_from_b(t_ring_buff *a, t_ring_buff *b, int *total)
{
	t_move	m;

	while (b->size > 0)
	{
		m = best_move(a, b);
		apply_move(a, b, m, total);
	}
	finish_rotate_min_to_top(a, total);
}
