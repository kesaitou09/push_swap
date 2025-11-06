/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaitou <ksaitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:44:37 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/06 13:47:29 by ksaitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void remove_nl(char *s)
{
    size_t n;
    if (!s) 
		return;
    n = ft_strlen(s);
    if (n != 0 && s[n - 1] == '\n')
        s[n - 1] = '\0';
}

static int	make_stackb(t_ring_buff *ring_a, t_ring_buff *ring_b)
{
	ring_b->cap = ring_a->cap;
	ring_b->buff = malloc(sizeof(int) * (ring_b->cap));
	if (!ring_b->buff)
		return (ERROR);
	ring_b->head = 0;
	ring_b->size = 0;
	return (SUCCESS);
}

int	do_operation(t_ring_buff *ring_a, t_ring_buff *ring_b, char *op)
{
	remove_nl(op);
	if (ft_strcmp(op, "sa") == 0)
		sa(ring_a, 0);
	else if (ft_strcmp(op, "sb") == 0)
		sb(ring_b, 0);
	else if (ft_strcmp(op, "ss") == 0)
		ss(ring_a, ring_b, 0);
	else if (ft_strcmp(op, "pa") == 0)
		pa(ring_a, ring_b, 0);
	else if (ft_strcmp(op, "pb") == 0)
		pb(ring_a, ring_b, 0);
	else if (ft_strcmp(op, "ra") == 0)
		ra(ring_a, 0);
	else if (ft_strcmp(op, "rb") == 0)
		rb(ring_b, 0);
	else if (ft_strcmp(op, "rr") == 0)
		rr(ring_a, ring_b, 0);
	else if (ft_strcmp(op, "rra") == 0)
		rra(ring_a, 0);
	else if (ft_strcmp(op, "rrb") == 0)
		rrb(ring_a, 0);
	else if (ft_strcmp(op, "rrr") == 0)
		rrr(ring_a, ring_b, 0);
	else
		return (write(2, "Error\n", 7), ERROR);
	return (SUCCESS);
}

int	manage_process_bonus(t_ring_buff *ring_a, t_ring_buff *ring_b, char *av)
{
	if (parse_arg(ring_a, av) == ERROR)
		return ((write(2, "Error\n", 7)), 1);
	if (create_ring(ring_a) == ERROR)
		return (write(2, "Error\n", 7), 1);
	if (make_stackb(ring_a, ring_b) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int	get_input_ope(t_ring_buff *ring_a, t_ring_buff *ring_b)
{
	char	*buff;

	while (1)
	{
		buff = get_next_line(0);
		if (!buff)
			break ;
		if (do_operation(ring_a, ring_b, buff) == ERROR)
			return ((free(buff)), ERROR);
	}
	if (ring_b->size == 0 && is_ascending(ring_a))
		return (write(1, "OK\n", 3), ERROR);
	else
		return (write(1, "KO\n", 3), ERROR);
	return (SUCCESS);
}
int	main(int ac, char **av)
{
	t_ring_buff	ring_a;
	t_ring_buff	ring_b;
	char		*joined;

	init_ring_buff(&ring_a);
	if (ac < 2)
		return (0);
	if (ac == 2)
	{
		if (manage_process_bonus(&ring_a, &ring_b, av[1]) == ERROR)
			return (write(2, "Error\n", 7), 1);
		(get_input_ope(&ring_a, &ring_b));
	}
	else
	{
		joined = arg_join(ac, av);
		if (!joined)
			return (write(2, "Error\n", 7), 1);
		if (manage_process_bonus(&ring_a, &ring_b, joined) == 1)
		{
			free(joined);
			return (write(2, "Error\n", 7), 1);
		}
		get_input_ope(&ring_a, &ring_b);
		free(joined);
	}
	return (0);
}
