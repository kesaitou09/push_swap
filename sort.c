#include "push_swap.h"
void    free_all(t_buff *forlis)
{
    free(forlis ->dp);
    free(forlis ->prev);
    free(forlis ->phys);
    free(forlis ->lis_tab);
}

int	init_forlis(t_buff *for_lis, t_ring_buff *a, int size)
{
	int	i;
	int	to_phys;

    for_lis ->max_len = 0;
    for_lis ->end = 0;
	for_lis->dp = malloc(sizeof(int) * size);
	for_lis->prev = malloc(sizeof(int) * size);
	for_lis->phys = malloc(sizeof(int) * size);
	for_lis->lis_tab = ft_calloc(sizeof(char), size);
	if (!for_lis->dp || !for_lis->prev || !for_lis->phys || !for_lis->lis_tab)
		return (free_all(for_lis), ERROR);
	i = 0;
	while (i < size)
	{
        to_phys = IND(a, i);
		for_lis->dp[i] = 1;
		for_lis->prev[i] = -1;
		for_lis->phys[to_phys] = a->buff[to_phys];
		i++;
	}
	return (SUCCESS);
}

void    lis_dp(t_ring_buff *a, t_buff *for_lis)
{
	int	i;
	int	j;
 
	i = 0;
	while (i < a->size)
	{
		j = 0;
		while (j < i)
		{
			if (for_lis->phys[j] < for_lis->phys[i] && for_lis->dp[j]
				+ 1 > for_lis->dp[i])
			{
				for_lis->dp[i] = for_lis->dp[j] + 1;
				for_lis->prev[i] = j;
			}
            j++;
		}
        if (for_lis ->dp[i] > for_lis ->max_len)
        {
            for_lis ->max_len = for_lis ->dp[i];
            for_lis ->end = i;
        }
        i++;
	}
}

void    mark_flag(t_buff *for_lis, int size)
{
    int k;
    int r;

    k = for_lis ->end;
    while (k !=)
    {
        /* code */
    }
    
    
    
}
int	lis(t_ring_buff *a, t_ring_buff *b, t_buff *for_lis)
{

    lis_dp(a, for_lis);
    mark_flag(for_lis, a ->size);
    return (1);
    
    
    
    
    
    
    
}



int	sort_process(t_ring_buff *a, t_ring_buff *b)
{
	t_buff for_lis;


	if (init_forlis(&for_lis, a, a->size) == ERROR)
		return (ERROR);
    lis(a, b, &for_lis);







    for (int i = 0; i < a ->size; i++)
    {
        ft_printf("%d,",for_lis.dp[i]);
    }
    ft_printf("\n");
    for (int i = 0; i < a ->size; i++)
    {
        ft_printf("%d,",for_lis.prev[i]);
    }
    
    return (SUCCESS);
	// lis(a, b, &for_lis);
}

