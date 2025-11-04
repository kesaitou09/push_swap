/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 12:05:40 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/04 11:22:31 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	token_checker(char *av, size_t *size)
{
	while (*av)
	{
		while (ft_isspace(*av))
			av++;
		if (!*av)
			break ;
		if ((*av == '+' || *av == '-') && *av && !ft_isdigit(*(av + 1)))
			return (ERROR);
		if (*av == '+' || *av == '-')
			av++;
		if (!ft_isdigit(*av))
			return (ERROR);
		while (*av >= '0' && *av <= '9')
			av++;
		if (*av && !ft_isspace(*av))
			return (ERROR);
		(*size)++;
	}
	if (*size == 0)
		return (ERROR);
	return (SUCCESS);
}

int	init_ring(t_ring_buff *ring_a, char *av, size_t size)
{
	size_t	i;
	int		err;
	int		digit;

	i = 0;
	err = 0;
	digit = 0;
	if (size == 0)
		return (ERROR);
	ring_a->cap = size;
	ring_a->head = 0;
	ring_a->buff = malloc(sizeof(int) * size);
	if (!ring_a->buff)
		return (ERROR);
	while (i < size)
	{
		digit = ft_atoll(&av, &err);
		if (err)
			return (ERROR);
		ring_a->buff[((ring_a->head + i) % ring_a->cap)] = digit;
		i++;
	}
	return (SUCCESS);
}

int	parse_arg(t_ring_buff *ring_a, char *av)
{
	size_t	size;

	size = 0;
	if (token_checker(av, &size) == ERROR)
		return (ERROR);
	if (init_ring(ring_a, av, size) == ERROR)
		return (free(ring_a->buff), ring_a->buff = NULL, ERROR);
	ring_a->size = size;
	return (SUCCESS);
}
