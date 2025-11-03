/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:49:40 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/04 01:36:23 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/includes/ft_printf.h"
# include "libft/includes/libft.h"
# include <limits.h>

# define IND(r, i) (((r)->head + (i)) % (r)->cap)
# define VAL(s, li) ((s)->buff[IND((s), (li))])

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
	int		*lis_tab;
	int		max_len;
	int		end;
	int		n_vals;
}			t_buff;

typedef struct s_move
{
	int		ib;
	int		pos_a;
	int		ca;
	int		cb;
	int		cost;
}			t_move;

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

int			rr(t_ring_buff *a, t_ring_buff *b, int *total);
int			rb(t_ring_buff *b, int *total, int how);
int			ra(t_ring_buff *a, int *total, int how);
int			pb(t_ring_buff *a, t_ring_buff *b, int *total);
int			pa(t_ring_buff *ring_a, t_ring_buff *ring_b, int *total);
int			ss(t_ring_buff *ring_a, t_ring_buff *ring_b, int *total);
int			sb(t_ring_buff *ring_b, int *total);
int			sa(t_ring_buff *ring_a, int *total);
int			rrb(t_ring_buff *b, int *total, int how);
int			rra(t_ring_buff *a, int *total, int how);
int			rrr(t_ring_buff *a, t_ring_buff *b, int *total);
int			swap_top(t_ring_buff *r);

int			sort_process(t_ring_buff *a, t_ring_buff *b);
void		lis_dp(t_ring_buff *a, t_buff *for_lis);
int			init_forlis(t_buff *for_lis, t_ring_buff *a, int size);
int			push_nonlis(t_buff *for_lis, t_ring_buff *a, t_ring_buff *b,
				int *total);
// int					search_spot(t_ring_buff *a, t_ring_buff *b);

//-----debug-------//
// void				random_op(t_ring_buff *a, t_ring_buff *b, t_buff *for_lis);
void		print_stack_a(t_ring_buff *a, t_buff *for_lis);
void		print_stack_b(t_ring_buff *a, t_buff *for_lis);
void		print_dp_prev_listab(t_ring_buff *a, t_buff for_lis);

//-------------test-------------------//
void		sort_from_b(t_ring_buff *a, t_ring_buff *b, int *total);
void		finish_rotate_min_to_top(t_ring_buff *a, int *total);
void		insert_top_b_into_a_minops(t_ring_buff *a, t_ring_buff *b,
				int *total);
int			pos_in_a_for(const t_ring_buff *a, int b);
char		*join_args_with_spaces(int n, char **args);
void		apply_move(t_ring_buff *a, t_ring_buff *b, t_move m, int *total);
t_move		best_move(const t_ring_buff *a, const t_ring_buff *b);

#endif