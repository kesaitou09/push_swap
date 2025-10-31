/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:11:35 by kesaitou          #+#    #+#             */
/*   Updated: 2025/10/31 11:18:46 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_ring_buff(t_ring_buff *ring_b)
{
	ring_b->buff = NULL;
	ring_b->ind = NULL;
	ring_b->head = 0;
	ring_b->cap = 0;
	ring_b->size = 0;
}
