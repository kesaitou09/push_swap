/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ring_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 10:36:00 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/07 10:43:25 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ring_ind(t_ring *ring, size_t i)
{
	return ((ring->head + i) % ring->cap);
}

int	ring_val(t_ring *ring, size_t i)
{
	return (ring->buff[ring_ind(ring, i)]);
}
