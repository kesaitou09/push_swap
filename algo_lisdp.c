/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_lisdp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:17:23 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/07 11:05:29 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_lis *forlis)
{
	free(forlis->dp);
	free(forlis->prev);
	free(forlis->lis_tab);
}

int	init_forlis(t_lis *for_lis, int size)
{
	int	i;

	for_lis->n_vals = size;
	for_lis->max_len = 0;
	for_lis->end = 0;
	for_lis->dp = malloc(sizeof(int) * size);
	for_lis->prev = malloc(sizeof(int) * size);
	for_lis->lis_tab = malloc(sizeof(int) * size);
	if (!for_lis->dp || !for_lis->prev || !for_lis->lis_tab)
		return (free_all(for_lis), ERROR);
	i = 0;
	while (i < size)
	{
		for_lis->dp[i] = 1;
		for_lis->prev[i] = -1;
		for_lis->lis_tab[i] = 0;
		i++;
	}
	return (SUCCESS);
}

void	lis_dp(t_ring *a, t_lis *for_lis)
{
	int	i;
	int	j;

	i = 0;
	while (i < for_lis->n_vals)
	{
		j = 0;
		while (j < i)
		{
			if (ring_val(a, j) < ring_val(a, i) && (for_lis->dp[j]
					+ 1) >= for_lis->dp[i])
			{
				for_lis->dp[i] = for_lis->dp[j] + 1;
				for_lis->prev[i] = j;
			}
			j++;
		}
		if (for_lis->dp[i] > for_lis->max_len)
		{
			for_lis->max_len = for_lis->dp[i];
			for_lis->end = i;
		}
		i++;
	}
}

void	lis(t_ring *a, t_lis *for_lis)
{
	lis_dp(a, for_lis);
	mark_flag(for_lis);
}

int	search_listab(t_lis *for_lis, int i, int size)
{
	while (i < size)
	{
		if (for_lis->lis_tab[i] == 0)
		{
			return (0);
		}
		i++;
	}
	return (1);
}
