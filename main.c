/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaitou <ksaitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 12:03:03 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/01 19:46:51 by ksaitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_ring_buff(t_ring_buff *r_buff)
{
	r_buff->buff = NULL;
	r_buff->ind = NULL;
	r_buff->cap = 0;
	r_buff->head = 0;
	r_buff->size = 0;
}

int	main(int ac, char **av)
{
	t_ring_buff	ring_a;
	t_ring_buff	ring_b;

	init_ring_buff(&ring_a);
	if (ac == 1)
		return (0);
	if (ac == 2)
	{
		if (parse_ac1(&ring_a, av[1]) == ERROR)
			return (1);
		if (create_ring(&ring_a) == ERROR)
			return (1);
		make_stackb(&ring_b, ring_a.size);
		sort_process(&ring_a, &ring_b);
	}
	else
	{
		return (0);
	}
	// for (int  i = 0; i < r_buff.size; i++)
	// {
	// 	ft_printf("%d,",rank[i]);
	// }
	return (0);
}
