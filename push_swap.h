/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:49:40 by kesaitou          #+#    #+#             */
/*   Updated: 2025/10/31 10:51:34 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/includes/ft_printf.h"
# include "libft/includes/libft.h"
# include <limits.h>

#define IND(r, i) (((r) ->head + (i) % (r) ->cap))

typedef struct s_ring_buff
{
	int		*buff;
	int		*ind;
	int		cap;
	int		head;
	int		size;

}			t_ring_buff;

void		init_ring_buff(t_ring_buff *r_buff);
int			parse_ac1(t_ring_buff *r_buff, char *av);
int			init_buff(t_ring_buff *r_buff, char *av, size_t size);
int			token_checker(char *av, size_t *size);
long long	ft_atoll(char **av, int *err);
int			grant_rank(t_ring_buff r_buff, int *rank);

#endif