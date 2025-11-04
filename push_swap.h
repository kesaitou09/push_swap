/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:49:40 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/04 16:10:33 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/includes/ft_printf.h"
# include "libft/includes/libft.h"
#include "libft/includes/get_next_line.h"
# include <limits.h>

# define IND(r, i) (((r)->head + (i)) % (r)->cap)
# define VAL(s, li) ((s)->buff[IND((s), (li))])

typedef struct s_ring_buff
{
	int		*buff;
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
	int		id_sb;
	int		pos_a;
	int		a_cost;
	int		b_cost;
	int		cost;
}			t_move;

int			parse_arg(t_ring_buff *ring_a, char *av);
int			controll_process(t_ring_buff *ring_a, t_ring_buff *ring_b,
				char *av);
int			token_checker(char *av, size_t *size);
int			ft_isspace(char c);
long long	ft_atoll(char **av, int *err);

int			init_ring(t_ring_buff *ring_a, char *av, size_t size);
void		init_ring_buff(t_ring_buff *ring_a);
int			grant_rank(t_ring_buff ring_a, int *rank);
int			create_ring(t_ring_buff *ring_a);
int			ring_load(t_ring_buff *ring_a, int *rank, int n);
int			make_stackb(t_ring_buff *ring_a, t_ring_buff *ring_b);
int			rank_helper(t_ring_buff ring_a, int *rank, int i, int r);

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

void		lis(t_ring_buff *a, t_buff *for_lis);
void		mark_flag(t_buff *for_lis);
int			search_listab(t_buff *for_lis, int i, int size);
int			sort_process(t_ring_buff *a, t_ring_buff *b);
void		lis_dp(t_ring_buff *a, t_buff *for_lis);
int			init_forlis(t_buff *for_lis, t_ring_buff *a, int size);
int			push_nonlis(t_buff *for_lis, t_ring_buff *a, t_ring_buff *b,
				int *total);

void		print_stack_a(t_ring_buff *a);
void		print_stack_b(t_ring_buff *a);
void		print_dp_prev_listab(t_ring_buff *a, t_buff for_lis);

void		sort_from_b(t_ring_buff *a, t_ring_buff *b, int *total);
void		finish_rotate_min_to_top(t_ring_buff *a, int *total);
void		insert_top_b_into_a_minops(t_ring_buff *a, t_ring_buff *b,
				int *total);
int			pos_in_a_for(t_ring_buff *a, int b);
char		*arg_join(int ac, char **av);
void		apply_move(t_ring_buff *a, t_ring_buff *b, t_move m, int *total);
t_move		best_move(t_ring_buff *a, t_ring_buff *b, t_move best);

#endif