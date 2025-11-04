/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 10:34:43 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/04 10:43:25 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_two(void *ptr1, void *ptr2)
{
	free(ptr1);
	free(ptr2);
}

char	*arg_join(int ac, char **av)
{
	char	*newstr;
	char	*joined;
	int		i;

	i = 1;
	joined = ft_strdup("");
	if (!joined)
		return (NULL);
	while (i < ac)
	{
		newstr = ft_strjoin(joined, av[i++]);
		if (!newstr)
			return ((free_two(joined, newstr)), NULL);
		joined = newstr;
		newstr = ft_strjoin(joined, " ");
		if (!newstr)
			return ((free_two(joined, newstr)), NULL);
		joined = newstr;
	}
	return (joined);
}

int	ft_isspace(char c)
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
		if (result > lim / 10 || (result == lim / 10 && digit > (lim % 10)))
			return (*err = 1, 0);
		result = result * 10 + digit;
		(*av)++;
	}
	return (result * sign);
}
