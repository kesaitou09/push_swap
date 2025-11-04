/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:44:37 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/04 16:13:47 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int	main(int ac, char **av)
{
	t_buff	ring_a;
	char	*buff;

	init_ring_buff(&ring_a);
	if (ac < 2)
		return (0);
	if (ac == 2)
	{
		if (parse_arg(&ring_a, av[1]) == ERROR)
			return ((write(2, "Error\n",7)), 1);
		if (create_ring(&ring_a) == ERROR)
			return (write(2, "Error\n", 7) ,1);
		buff = get_next_line(0);
		if (!buff)
			return (write(2, "Error\n", 7) ,1);
			
		
		
		
		
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}

