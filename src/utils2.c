/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloisel <lloisel@student.42.fr >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 22:55:01 by lloisel           #+#    #+#             */
/*   Updated: 2022/10/06 18:44:04 by lloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

long long	t_diff(long long first, long long second)
{
	return (first - second);
}
void sleep_x(long long time, t_bag *b)
{
	long long end;

	end  = get_time() + time;
	while(b->state && get_time() < end)
	{
		usleep(500);
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

void error(char *s)
{
	int l;
	
	l = ft_strlen(s);
	write(2,"Error : ",8); 
	write(2,s,l);
}