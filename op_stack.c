/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 02:17:15 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/02 12:04:42 by kesaitou         ###   ########.fr       */
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

int	search_spot(t_ring_buff *a, t_ring_buff *b)
{
	int	i;
	int	ind_a;
	int	min_lc;

	i = 0;
	while (i < a->size)
	{
		if (a->buff[ind_a - 1] < b->buff[b->head]
			&& b->buff[b->head] < a->buff[ind_a + 1])
			pa(a, b);
		if (b->buff[b->head] < locate_min(a, &min_lc) || b ->buff[b ->head] > locate_max(a))
		{
			
		}
	}
	return (SUCCESS);
}

int	locate_min(t_ring_buff *a, int *min_lc)
{
	int	i;
	int	ind;
	int	min;

	i = 1;
	ind = IND(a, 0);
	min = a->buff[ind];
	while (i < a->size)
	{
		if (a->buff[ind] < min)
		{
			min = a->buff[ind];
			*min_lc = ind;
		}
		ind = IND(a, ++i);
	}
	return (min);
}
int	locate_max(t_ring_buff *a)
{
	int	i;
	int	ind;
	int	max;

	i = 1;
	ind = IND(a, 0);
	max = a->buff[ind];
	while (i < a->size)
	{
		if (a->buff[ind] < max)
			max = a->buff[ind];
		ind = IND(a, ++i);
	}
	return (max);
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
