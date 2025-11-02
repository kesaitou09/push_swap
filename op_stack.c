/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaitou <ksaitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 02:17:15 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/02 21:37:52 by ksaitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	push_nonlis(t_buff *for_lis, t_ring_buff *a, t_ring_buff *b)
{
	int	n;
	int	key;

	n = a->size;
	while (n--)
	{
		key = a->buff[a->head];
		if (for_lis->lis_tab[key])
			ra(a);
		else
			pb(a, b);
	}
	return (SUCCESS);
}

// int	search_spot(t_ring_buff *a, int b)
// {
// 	int	i;
// 	int	ind;
// 	int	min_lc;

// 	i = 0;
// 	while (i < a->size)
// 	{
// 		ind = VAL(a, i) if (a->buff[ind - 1] < b && b < a->buff[ind + 1]) pa(a,
// 				b);
// 		if (b < locate_min(a, &min_lc) || b > locate_max(a))
// 		{
// 		}
// 	}
// 	return (SUCCESS);
// }

// int	locate_min(t_ring_buff *a, int *min_lc)
// {
// 	int	i;
// 	int	ind;
// 	int	min;

// 	i = 1;
// 	ind = IND(a, 0);
// 	min = a->buff[ind];
// 	while (i < a->size)
// 	{
// 		if (a->buff[ind] < min)
// 		{
// 			min = a->buff[ind];
// 			*min_lc = ind;
// 		}
// 		ind = IND(a, ++i);
// 	}
// 	return (min);
// }
// int	locate_max(t_ring_buff *a)
// {
// 	int	i;
// 	int	ind;
// 	int	max;

// 	i = 1;
// 	ind = IND(a, 0);
// 	max = a->buff[ind];
// 	while (i < a->size)
// 	{
// 		if (a->buff[ind] < max)
// 			max = a->buff[ind];
// 		ind = IND(a, ++i);
// 	}
// 	return (max);
// }

//------------------test-----------------//

static int	idx_min_logical(const t_ring_buff *a)
{
	int	imin;
	int	vmin;
	int	v;

	imin = 0;
	vmin = VAL(a, 0);
	for (int i = 1; i < a->size; i++)
	{
		v = VAL(a, i);
		if (v < vmin)
		{
			vmin = v;
			imin = i;
		}
	}
	return (imin);
}

static int	max_val(const t_ring_buff *a)
{
	int	vmax;
	int	v;

	vmax = VAL(a, 0);
	for (int i = 1; i < a->size; i++)
	{
		v = VAL(a, i);
		if (v > vmax)
			vmax = v;
	}
	return (vmax);
}

int	pos_in_a_for(const t_ring_buff *a, int b)
{
	int	vmax;
	int	prev;
	int	cur;
	int	vmin;
	int	imin;

	if (a->size == 0)
		return (0);
	if (a->size == 1)
		return ((VAL(a, 0) < b) ? 1 : 0);
	imin = idx_min_logical(a);
	vmax = max_val(a);
	// 例外: 範囲外は最小の直前（= min の位置）に挿す
	if (b < vmin || b > vmax)
		return (imin);
	// 通常: prev<b<cur を満たす i を探索（循環に注意）
	for (int i = 0; i < a->size; i++)
	{
		prev = VAL(a, (i - 1 + a->size) % a->size);
		cur = VAL(a, i);
		if (prev < b && b < cur)
			return (i);
	}
	// フォールバック（理論上到達しないが安全側で最小の直前）
	return (imin);
}

static inline int	rot_cost(int idx, int n)
{
	return ((idx <= n / 2) ? idx : idx - n);
}

static void	rotate_a_to(t_ring_buff *a, int pos)
{
	int	ca;

	ca = rot_cost(pos, a->size);
	while (ca > 0)
	{
		ra(a);
		ca--;
	}
	while (ca < 0)
	{
		rra(a);
		ca++;
	}
}

// 使い方（b は B の先頭だとする）
void	insert_top_b_into_a_minops(t_ring_buff *a, t_ring_buff *b)
{
	int	bval;

	bval = b->buff[b->head];
	int pos = pos_in_a_for(a, bval); // “pa直後に円整列が壊れない位置”
	rotate_a_to(a, pos);             // ★ここまでで A 側の回転手数が最小
	pa(a, b);                        // ★これで追加の修正手が不要（=最小手）
}

void	finish_rotate_min_to_top(t_ring_buff *a)
{
	if (a->size == 0)
		return ;
	rotate_a_to(a, idx_min_logical(a));
}

// ここに来るまでに：LIS を A に残し、非 LIS をすべて B へ pb 済み
void	sort_from_b_simple(t_ring_buff *a, t_ring_buff *b)
{
	while (b->size > 0)
	{
		insert_top_b_into_a_minops(a, b);
	}
	finish_rotate_min_to_top(a);
}

// void	random_op(t_ring_buff *a, t_ring_buff *b, t_buff *for_lis)
// {
// 	// rra(a);
// 	// pa(a,b);
// 	print_stack_a(a, for_lis);
// 	print_stack_b(b, for_lis);
// 	// rrb(b);
// 	// rrr(a,b);
// 	// pa(a,b);
// 	// pb(a,b);
// }

// void	print_stack_a(t_ring_buff *a, t_buff *for_lis)
// {
// 	int	i;
// 	int	n;
// 	int	head;

// 	i = 0;
// 	n = a ->size;
// 	ft_printf("----stack__a-----\n");
// 	while (n--)
// 	{
// 		head = (a ->head + i) % a ->cap;
// 		ft_printf("%d,",a ->buff[head]);
// 		i++;
// 	}
// 	ft_printf("\n");
// }

// void	print_stack_b(t_ring_buff *b, t_buff *for_lis)
// {
// 	int	i;
// 	int	n;
// 	int head;

// 	i = 0;
// 	n = b ->size;
// 	ft_printf("----stack__b-----\n");
// 	while (n--)
// 	{
// 		head = (b ->head + i) % b ->cap;
// 		ft_printf("%d,",b ->buff[head]);
// 		i++;
// 	}
// 	ft_printf("\n");
// }
