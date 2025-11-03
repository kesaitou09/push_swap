/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 00:41:39 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/04 00:56:58 by kesaitou         ###   ########.fr       */
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
	char        *joined;

	init_ring_buff(&ring_a);
	if (ac == 1)
		return (0);
	if (ac == 2)
	{
		if (parse_ac1(&ring_a, av[1]) == ERROR)
			return (1);
		if (create_ring(&ring_a) == ERROR)
			return (1);
		if (sort_process(&ring_a, &ring_b) == ERROR)
			return (1);
	}
	else
	{
		joined = join_args_with_spaces(ac - 1, &av[1]);
		if (!joined)
			return (1);
		if (parse_ac1(&ring_a, joined) == ERROR)
		{
			free(joined);
			return (1);
		}
		if (create_ring(&ring_a) == ERROR)
			return (1);
		if (sort_process(&ring_a, &ring_b) == ERROR)
			return (1);
		free(joined);
	}
	// for (int  i = 0; i < r_buff.size; i++)
	// {
	// 	ft_printf("%d,",rank[i]);
	// }
	return (0);
}