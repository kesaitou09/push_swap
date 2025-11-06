/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 21:51:54 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/05 21:48:32 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	_size;
	void	*arr;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	_size = nmemb * size;
	arr = malloc(_size);
	if (!arr)
		return (NULL);
	ft_memset(arr, 0, _size);
	return (arr);
}

// int main(void)
//{
//     void *p = ft_calloc(2, 2);
//     if (!p) return 1;
//     free(p);
//     return 0;
// }
