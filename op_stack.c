/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaitou <ksaitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 02:17:15 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/03 11:59:34 by ksaitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	push_nonlis(t_buff *for_lis, t_ring_buff *a, t_ring_buff *b, int *total)
{
	int	n;
	int	key;

	n = a->size;
	while (n--)
	{
		key = a->buff[a->head];
		if (for_lis->lis_tab[key])
			ra(a, total);
		else
			pb(a, b, total);
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

/* 必要なら定義してください
#define IND(s, li) (((s)->head + (li)) % (s)->cap)
#define VAL(s, li) ((s)->buff[ IND((s), (li)) ])
*/

/* 最小値の論理インデックス（a->size > 0 前提） */
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

/* 最大値（a->size > 0 前提） */
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

/* b を A に昇順で挿す論理インデックス
   - 通常: prev<b<cur を満たす i
   - 例外: b<min(A) または b>max(A) は min の直前（= min の index） */
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
	vmin = VAL(a, imin);          /* ★必ず取得する */
	vmax = max_val(a);

	/* 例外: 範囲外は最小の直前 */
	if (b < vmin || b > vmax)
		return (imin);

	/* 通常: prev<b<cur を満たす i を探索（循環） */
	i = 0;
	while (i < a->size)
	{
		prev = VAL(a, (i - 1 + a->size) % a->size);
		cur = VAL(a, i);
		if (prev < b && b < cur)
			return (i);
		i++;
	}
	/* 安全側フォールバック（理論上は到達しない） */
	return (imin);
}

/* 先頭(論理0)へ最短で寄せる符号付き回転数（+ra / -rra） */
static int	rot_cost(int idx, int n)
{
	if (idx <= n / 2)
		return (idx);
	return (idx - n); /* 例: n=10, idx=8 → -2 */
}

/* A を pos が先頭に来るまで最短回転 */
static void	rotate_a_to(t_ring_buff *a, int pos, int *total)
{
	int	ca;

	if (a->size <= 1)
		return ;
	ca = rot_cost(pos, a->size);
	while (ca > 0)
	{
		ra(a, total);
		ca--;
	}
	while (ca < 0)
	{
		rra(a, total);
		ca++;
	}
}

/* B の先頭を “追加手ゼロ” の位置に挿入（まず動く版） */
void	insert_top_b_into_a_minops(t_ring_buff *a, t_ring_buff *b, int *total)
{
	int	bval;
	int	pos;

	if (b->size == 0)
		return ;
	bval = b->buff[b->head];           /* B 先頭の値（物理 head） */
	pos = pos_in_a_for(a, bval);       /* pa直後に円整列が崩れない位置 */
	rotate_a_to(a, pos, total);               /* A 側の回転を最短化 */
	pa(a, b, total);                          /* 追加の修正手不要で挿入 */
}

/* 仕上げ：A の最小を先頭へ */
void	finish_rotate_min_to_top(t_ring_buff *a, int *total)
{
	int	pos;

	if (a->size == 0)
		return ;
	pos = idx_min_logical(a);
	rotate_a_to(a, pos, total);
}

/* ここに来るまでに：LIS を A に残し、非 LIS をすべて B に pb 済み */
void	sort_from_b_simple(t_ring_buff *a, t_ring_buff *b, int *total)
{
	while (b->size > 0)
		insert_top_b_into_a_minops(a, b, total);
	finish_rotate_min_to_top(a, total);
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
