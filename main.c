/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 00:41:39 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/05 21:11:58 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int	controll_process(t_ring_buff *ring_a, t_ring_buff *ring_b, char *av)
{
	if (parse_arg(ring_a, av) == ERROR)
		return (1);
	if (create_ring(ring_a) == ERROR)
		return ((free(ring_a ->buff)), 1);
	if (controll_sort(ring_a, ring_b) == ERROR)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_ring_buff	ring_a;
	t_ring_buff	ring_b;
	char		*joined;

	init_ring_buff(&ring_a);
	if (ac == 1)
		return (0);
	if (ac == 2)
	{
		if (controll_process(&ring_a, &ring_b, av[1]) == 1)
			return (write(2, "Error\n", 7) ,1);
	}
	else
	{
		joined = arg_join(ac, av);
		if (!joined)
			return (write(2, "Error\n", 7), 1);
		if (controll_process(&ring_a, &ring_b, joined) == 1)
			return (write(2, "Error\n", 7) ,1);
		free(joined);
	}
	return (0);
}
