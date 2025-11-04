/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:44:37 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/04 18:51:51 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_arg(char *buff)
{
	if (!ft_strcmp(buff, "sa\n") || !ft_strcmp(buff, "sb\n") || !ft_strcmp(buff,
			"ss\n"))
		return (SUCCESS);
	if (!ft_strcmp(buff, "pa\n") || !ft_strcmp(buff, "pb\n"))
		return (SUCCESS);
	if (!ft_strcmp(buff, "ra\n") || !ft_strcmp(buff, "rb\n") || !ft_strcmp(buff,
			"rr\n"))
		return (SUCCESS);
	if (!ft_strcmp(buff, "rra\n") || !ft_strcmp(buff, "rrb\n")
		|| !ft_strcmp(buff, "rrr\n"))
		return (SUCCESS);
	else
		return (ERROR);
}

int	do_operation()
{
	
	
	
	
	
	
	
}

int	controll_process_bonus(t_ring_buff *ring_a, char *av)
{
	if (parse_arg(&ring_a, av) == ERROR)
			return ((write(2, "Error\n", 7)), 1);
	if (create_ring(&ring_a) == ERROR)
		return (write(2, "Error\n", 7), 1);
	
	
	
	
	
	
	
	
}

int	main(int ac, char **av)
{
	t_ring_buff	ring_a;
	char		*buff;
	char		*joined;

	init_ring_buff(&ring_a);
	if (ac < 2)
		return (0);
	if (ac == 2)
	{
		if (controll_process_bonus(&ring_a, av[1]) == ERROR)
			return (write(2, "Error\n", 7), 1);
		while (1)
		{
			buff = get_next_line(0);
			if (!buff)
				break ;
			if (check_arg(buff) == ERROR)
				return (write(2, "Error\n", 7), 1);
		}
	}
	else
	{
		joined = arg_join(ac, av);
		if (!joined)
			return ()				
		
		
	}
	
}
