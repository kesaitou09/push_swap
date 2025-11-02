/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:49:40 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/02 14:19:14 by kesaitou         ###   ########.fr       */
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

typedef struct s_buff
{
	int		*dp;
	int		*prev;
	int		*phys;
	char	*lis_tab;
	int		max_len;
	int		end;
	int		n_vals;
}			t_buff;

int			parse_ac1(t_ring_buff *r_buff, char *av);
int			token_checker(char *av, size_t *size);
long long	ft_atoll(char **av, int *err);

int			init_buff(t_ring_buff *r_buff, char *av, size_t size);
void		init_ring_buff(t_ring_buff *r_buff);
int			grant_rank(t_ring_buff r_buff, int *rank);
int			create_ring(t_ring_buff *r_buff);
int			ring_load(t_ring_buff *r, int *rank, int n);
int			make_stackb(t_ring_buff *ring_a, t_ring_buff *ring_b);
int			rank_helper(t_ring_buff r_buff, int *rank, size_t i, size_t r);

int			rb(t_ring_buff *b);
int			ra(t_ring_buff *a);
int			pb(t_ring_buff *a, t_ring_buff *b);
int			pa(t_ring_buff *ring_a, t_ring_buff *ring_b);
int			ss(t_ring_buff *ring_a, t_ring_buff *ring_b);
int			sb(t_ring_buff *ring_b);
int			sa(t_ring_buff *ring_a);
int			rrb(t_ring_buff *b);
int			rra(t_ring_buff *a);
int			rrr(t_ring_buff *a, t_ring_buff *b);
int			swap_top(t_ring_buff *r);

int			sort_process(t_ring_buff *a, t_ring_buff *b);
void		lis_dp(t_ring_buff *a, t_buff *for_lis);
int			init_forlis(t_buff *for_lis, t_ring_buff *a, int size);
int			push_nonlis(t_buff *for_lis, t_ring_buff *a, t_ring_buff *b);
int			search_spot(t_ring_buff *a, t_ring_buff *b);

//-----debug-------//
void		random_op(t_ring_buff *a, t_ring_buff *b, t_buff *for_lis);
#endif