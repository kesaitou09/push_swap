/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:49:40 by kesaitou          #+#    #+#             */
/*   Updated: 2025/10/31 16:51:04 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/includes/ft_printf.h"
# include "libft/includes/libft.h"
# include <limits.h>

# define IND(r, i) (((r)->head + (i) % (r)->cap))

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
int			create_ring(t_ring_buff *r_buff);
int			ring_load(t_ring_buff *r, int *rank, int n);
void		make_stackb(t_ring_buff *ring_b, int size);
int			rrb(t_ring_buff *b);
int			rra(t_ring_buff *a);
int			rb(t_ring_buff *b);
int			ra(t_ring_buff *a);
int			pb(t_ring_buff *a, t_ring_buff *b);
int			pa(t_ring_buff *ring_a, t_ring_buff *ring_b);
int			ss(t_ring_buff *ring_a, t_ring_buff *ring_b);
int			sb(t_ring_buff *ring_b);
int			sa(t_ring_buff *ring_a);
int			swap_top(t_ring_buff *r);

#endif