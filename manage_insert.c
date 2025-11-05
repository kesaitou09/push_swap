/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 06:16:52 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/06 06:21:07 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_tmove(t_move *best)
{
	best->a_cost = 0;
	best->b_cost = 0;
	best->id_sb = 0;
	best->pos_a = 0;
	best->cost = INT_MAX;
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
