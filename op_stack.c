/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 02:17:15 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/03 22:05:47 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// int	push_nonlis(t_buff *for_lis, t_ring_buff *a, t_ring_buff *b, int *total)
// {
// 	int	n;
// 	int	i;

// 	i = 0;
// 	n = for_lis->n_vals;
// 	while (n--)
// 	{
// 		if (for_lis->lis_tab[IND(a, i++)])
// 			ra(a, total);
// 		else
// 			pb(a, b, total);
// 	}
// 	return (SUCCESS);
// }

// int	push_nonlis(t_buff *for_lis, t_ring_buff *a, t_ring_buff *b, int *total)
// {
// 	int	n;
// 	int	phys;
// 	int	logical;

// 	n = for_lis->n_vals;
// 	while (n--)
// 	{
// 		phys = a->head;
// 		logical = for_lis->phys_to_logi[phys];
// 		if (for_lis->lis_tab[logical])
// 			ra(a, total);
// 		else
// 			pb(a, b, total);
// 	}
// 	return (SUCCESS);
// }

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

static int	rot_cost(int idx, int n)
{
	if (idx <= n / 2)
		return (idx);
	return (idx - n);
}

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
