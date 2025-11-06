/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:49:40 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/07 03:55:58 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/includes/ft_printf.h"
# include "libft/includes/get_next_line.h"
# include "libft/includes/libft.h"
# include <limits.h>

# define IND(ring, i) (((ring)->head + (i)) % (ring)->cap)
# define VAL(ring, i) ((ring)->buff[IND((ring), (i))])

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
int			manage_process(t_ring_buff *ring_a, t_ring_buff *ring_b, char *av);
int			token_checker(char *av, size_t *size);
int			ft_isspace(char c);
long long	ft_atoll(char **av, int *err);

int			init_ring(t_ring_buff *ring_a, char *av, size_t size);
void		init_ring_buff(t_ring_buff *ring_a);
int			grant_rank(t_ring_buff ring_a, int *rank);
int			create_ring(t_ring_buff *ring_a);
void		ring_load(t_ring_buff *ring_a, int *rank, int n);
int			make_stackb(t_ring_buff *ring_a, t_ring_buff *ring_b);
int			rank_helper(t_ring_buff ring_a, int *rank, int i, int r);
void		free_all(t_buff *forlis);

int			rr(t_ring_buff *a, t_ring_buff *b, int print);
int			rb(t_ring_buff *b, int print);
int			ra(t_ring_buff *a, int print);
int			pb(t_ring_buff *a, t_ring_buff *b, int print);
int			pa(t_ring_buff *ring_a, t_ring_buff *ring_b, int print);
int			ss(t_ring_buff *ring_a, t_ring_buff *ring_b, int print);
int			sb(t_ring_buff *ring_b, int print);
int			sa(t_ring_buff *ring_a, int print);
int			rrb(t_ring_buff *b, int print);
int			rra(t_ring_buff *a, int print);
int			rrr(t_ring_buff *a, t_ring_buff *b, int print);
int			swap_top(t_ring_buff *r);

void		lis(t_ring_buff *a, t_buff *for_lis);
void		mark_flag(t_buff *for_lis);
int			sort_process(t_ring_buff *a, t_ring_buff *b);
void		lis_dp(t_ring_buff *a, t_buff *for_lis);
int			init_forlis(t_buff *for_lis, int size);
int			push_nonlis(t_buff *for_lis, t_ring_buff *a, t_ring_buff *b);

void		print_stack_a(t_ring_buff *a);
void		print_stack_b(t_ring_buff *a);
void		print_dp_prev_listab(t_ring_buff *a, t_buff for_lis);

int			manage_sort(t_ring_buff *ring_a, t_ring_buff *ring_b);
int			sort_five(t_ring_buff *ring_a, t_ring_buff *ring_b);
int			sort_three(t_ring_buff *ring_a);
int			is_ascending(t_ring_buff *ring_a);
int			is_descending(t_ring_buff *ring_a);

int			search_position(t_ring_buff *ring_a, int b);
void		rotate_a_to(t_ring_buff *a, int pos);
void		double_rotate(t_ring_buff *a, t_ring_buff *b, t_move *m);

int			same_sign(int a, int b);
int			max_val(t_ring_buff *a);
int			idx_min_logical(t_ring_buff *a);
int			max(int a, int b);
int			my_abs(int x);

int			calc_cost(int idx, int size);
int			merged_cost(int a_cost, int b_cost);
void		sort_from_b(t_ring_buff *a, t_ring_buff *b);
void		finish_rotate_min_to_top(t_ring_buff *a);
int			pos_in_a_for(t_ring_buff *a, int b);
char		*arg_join(int ac, char **av);
void		apply_move(t_ring_buff *a, t_ring_buff *b, t_move m);
t_move		best_move(t_ring_buff *a, t_ring_buff *b, t_move best);
int			search_listab(t_buff *for_lis, int i, int size);
void		remove_nl(char *s);
int			check_strcmp(const char *s1, const char *s2);

#endif