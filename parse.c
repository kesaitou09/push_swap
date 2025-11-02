/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 12:05:40 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/02 08:00:44 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\f' || c == '\r'
		|| c == '\v');
}

static void	atoll_helper(char ***av, long long *lim, int *sign)
{
	*sign = 1;
	*lim = (long long)INT_MAX;
	if (***av == '+' || ***av == '-')
	{
		if (***av == '-')
		{
			*sign = -1;
			*lim = (long long)INT_MAX + 1;
		}
		(**av)++;
	}
}

long long	ft_atoll(char **av, int *err)
{
	long long	result;
	long long	lim;
	int			sign;
	int			digit;

	result = 0;
	digit = 0;
	while (ft_isspace(**av))
		(*av)++;
	atoll_helper(&av, &lim, &sign);
	while (**av >= '0' && **av <= '9')
	{
		digit = **av - '0';
		if (result > lim / 10 || result == lim / 10 && digit > (lim % 10))
			return (*err = 1, 0);
		result = result * 10 + digit;
		(*av)++;
	}
	return (result * sign);
}

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

int	init_buff(t_ring_buff *r_buff, char *av, size_t size)
{
	int		i;
	int		err;
	int		digit;

	i = 0;
	err = 0;
	digit = 0;
	if (size == 0)
		return (ERROR);
	while (i < size)
	{
		digit = ft_atoll(&av, &err);
		if (err)
			return (ERROR);
		r_buff->buff[((r_buff->head + i) % r_buff ->cap)] = digit;
		i++;
	}
	return (SUCCESS);
}

int	parse_ac1(t_ring_buff *r_buff, char *av)
{
	size_t	size;

	size = 0;
	if (token_checker(av, &size) == ERROR)
		return (ERROR);
	r_buff->cap = size;
	r_buff ->head = 0;
	r_buff->buff = malloc(sizeof(int) * size);
	if (!r_buff->buff)
		return (ERROR);
	if (init_buff(r_buff, av, size) == ERROR)
		return (free(r_buff->buff), r_buff->buff = NULL, ERROR);
	r_buff->size = size;
	return (SUCCESS);
}

int	grant_rank(t_ring_buff r_buff, int *rank)
{
	size_t	i;
	int		r;

	i = 0;
	r = 0;
	if (rank_helper(r_buff, rank, i, r) == ERROR)
		return (ERROR);
	return (1);
}

int	rank_helper(t_ring_buff r_buff, int *rank, size_t i, size_t r)
{
	size_t	j;
	int		vi;
	int		vj;

	while (i < r_buff.size)
	{
		vi = r_buff.buff[(r_buff.head + i) % r_buff.cap];
		j = 0;
		r = 0;
		while (j < r_buff.size)
		{
			vj = r_buff.buff[(r_buff.head + j) % r_buff.cap];
			if (i != j && vi == vj)
				return (0);
			if (vj < vi)
				r++;
			j++;
		}
		rank[i] = r;
		i++;
	}
	return (1);
}
