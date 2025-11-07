/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:44:37 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/07 11:05:04 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	make_sb(t_ring *ring_a, t_ring *ring_b)
{
	ring_b->cap = ring_a->cap;
	ring_b->buff = malloc(sizeof(int) * (ring_b->cap));
	if (!ring_b->buff)
		return (ERROR);
	ring_b->head = 0;
	ring_b->size = 0;
	return (SUCCESS);
}

int	do_operation(t_ring *ring_a, t_ring *ring_b, char *op)
{
	if (check_strcmp(op, "sa") == 0)
		sa(ring_a, 0);
	else if (check_strcmp(op, "sb") == 0)
		sb(ring_b, 0);
	else if (check_strcmp(op, "ss") == 0)
		ss(ring_a, ring_b, 0);
	else if (check_strcmp(op, "pa") == 0)
		pa(ring_a, ring_b, 0);
	else if (check_strcmp(op, "pb") == 0)
		pb(ring_a, ring_b, 0);
	else if (check_strcmp(op, "ra") == 0)
		ra(ring_a, 0);
	else if (check_strcmp(op, "rb") == 0)
		rb(ring_b, 0);
	else if (check_strcmp(op, "rr") == 0)
		rr(ring_a, ring_b, 0);
	else if (check_strcmp(op, "rra") == 0)
		rra(ring_a, 0);
	else if (check_strcmp(op, "rrb") == 0)
		rrb(ring_b, 0);
	else if (check_strcmp(op, "rrr") == 0)
		rrr(ring_a, ring_b, 0);
	else
		return (ERROR);
	return (SUCCESS);
}

int	parse_operation(t_ring *ring_a, t_ring *ring_b)
{
	char	*buff;

	while (1)
	{
		buff = get_next_line(0);
		if (!buff)
			break ;
		remove_nl(buff);
		if (do_operation(ring_a, ring_b, buff) == ERROR)
			return ((free(buff)), ERROR);
		free(buff);
	}
	if (ring_b->size == 0 && is_ascending(ring_a))
		return ((free(buff)), write(1, "OK\n", 3), SUCCESS);
	else
		return ((free(buff)), write(1, "KO\n", 3), SUCCESS);
}

int	manage_process_bonus(t_ring *ring_a, t_ring *ring_b, char *av)
{
	if (parse_arg(ring_a, av) == ERROR)
		return ((write(2, "Error\n", 7)), 1);
	if (create_ring(ring_a) == ERROR)
		return ((free(ring_a->buff)), write(2, "Error\n", 7), 1);
	if (make_sb(ring_a, ring_b) == ERROR)
		return ((free(ring_a->buff)), write(2, "Error\n", 7), 1);
	if (parse_operation(ring_a, ring_b) == ERROR)
		return (free(ring_a->buff), (free(ring_b->buff)), write(2, "Error\n",
				7), 1);
	return (free(ring_a->buff), (free(ring_b->buff)), 0);
}

int	main(int ac, char **av)
{
	t_ring	ring_a;
	t_ring	ring_b;
	char	*joined;

	init_ring_buff(&ring_a);
	if (ac < 2)
		return (0);
	if (ac == 2)
	{
		if (manage_process_bonus(&ring_a, &ring_b, av[1]) == 1)
			return (1);
	}
	else
	{
		joined = arg_join(ac, av);
		if (!joined)
			return (write(2, "Error\n", 7), 1);
		if (manage_process_bonus(&ring_a, &ring_b, joined) == 1)
			return (free(joined), 1);
		free(joined);
	}
	return (0);
}
