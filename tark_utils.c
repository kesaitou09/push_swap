/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tark_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 05:22:05 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/06 06:43:18 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	my_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	idx_min_logical(t_ring_buff *a)
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

int	max_val(t_ring_buff *a)
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

int	same_sign(int a, int b)
{
	if ((a >= 0 && b >= 0) || (a < 0 && b < 0))
		return (1);
	return (0);
}
