/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaitou <ksaitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 22:58:57 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/02 21:35:58 by ksaitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    free_all(t_buff *forlis)
{
    free(forlis ->dp);
    free(forlis ->prev);
    free(forlis ->phys);
    free(forlis ->lis_tab);
}

int	init_forlis(t_buff *for_lis, t_ring_buff *a, int size)
{
	int	i;
	int	to_phys;

	for_lis ->n_vals = size;
    for_lis ->max_len = 0;
    for_lis ->end = 0;
	for_lis->dp = malloc(sizeof(int) * size);
	for_lis->prev = malloc(sizeof(int) * size);
	for_lis->phys = malloc(sizeof(int) * size);
	for_lis->lis_tab = ft_calloc(sizeof(char), size);
	if (!for_lis->dp || !for_lis->prev || !for_lis->phys || !for_lis->lis_tab)
		return (free_all(for_lis), ERROR);
	i = 0;
	while (i < size)
	{
        to_phys = IND(a, i);
		for_lis->dp[i] = 1;
		for_lis->prev[i] = -1;
		for_lis->phys[i] = a->buff[to_phys];
		i++;
	}
	return (SUCCESS);
}

void    lis_dp(t_ring_buff *a, t_buff *for_lis)
{
	int	i;
	int	j;
 
	i = 0;
	while (i < for_lis ->n_vals)
	{
		j = 0;
		while (j < i)
		{
			if (for_lis->phys[j] < for_lis->phys[i] && (for_lis->dp[j] + 1) > for_lis->dp[i])
			{
				for_lis->dp[i] = for_lis->dp[j] + 1;
				for_lis->prev[i] = j;
			}
            j++;
		}
        if (for_lis ->dp[i] > for_lis ->max_len)
        {
            for_lis ->max_len = for_lis ->dp[i];
            for_lis ->end = i;
        }
        i++;
	}
}

void    mark_flag(t_buff *for_lis)
{
    int k;
    int r;

    k = for_lis ->end;
    while (k != -1)
    {
		r = for_lis ->phys[k];
		if (r >= 0 && r < for_lis -> n_vals)
			for_lis ->lis_tab[r] = 1;
		k = for_lis ->prev[k];
    }
	
}
void	lis(t_ring_buff *a, t_ring_buff *b, t_buff *for_lis)
{

    lis_dp(a, for_lis);
    mark_flag(for_lis);
}


int	sort_process(t_ring_buff *a, t_ring_buff *b)
{
	t_buff for_lis;

	if (init_forlis(&for_lis, a, a->size) == ERROR)
		return (ERROR);
    lis(a, b, &for_lis);
	if (make_stackb(a, b) == ERROR)
		return (ERROR);
	if (push_nonlis(&for_lis, a, b) == ERROR)
		return (ERROR);
	sort_from_b_simple(a, b);

	// for (int i = 0; i < a ->size; i++)
	// {
	// 	ft_printf("%d,",a ->buff[i]);
	// }
	// 	ft_printf("stack a\n");
	// for (int i = 0; i < b ->size; i++)
	// {
	// 	int ind = IND(b, i);
	// 	ft_printf("%d,",b ->buff[ind]);
	// }
	// 	ft_printf("stack b\n");
	// for (int i = 0; i < a ->size; i++)
	// {
	// 	int ind = IND(a, i);
	// 	ft_printf("%d,",a ->buff[ind]);
	// }
	
	
	
	
	








	//ーーーーーーテストーーーーーーーーーーーーー//

	// ft_printf("\nrank")
	// ft_printf("\ndp\n");
    // for (int i = 0; i < a ->size; i++)
    // {
    //     ft_printf("%d,",for_lis.dp[i]);
    // }
    // ft_printf("\nprev\n");
    // for (int i = 0; i < a ->size; i++)
    // {
    //     ft_printf("%d,",for_lis.prev[i]);
    // }
	// ft_printf("\ntab\n");
	// for (int i = 0; i < a ->size; i++)
	// {
	// 	ft_printf("%d,",for_lis.lis_tab[i]);
	// }
	
    
    return (SUCCESS);
	// lis(a, b, &for_lis);
}

