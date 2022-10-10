/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloisel <lloisel@student.42.fr >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 04:12:39 by lloisel           #+#    #+#             */
/*   Updated: 2022/10/06 18:34:38 by lloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int init_forks(t_bag *b)
{
    
    int i;

    i = 0;
    while (i < b->nb_p)
    {

        if(pthread_mutex_init(&(b->forks[i]),NULL))
            return(1);
        i++;
    }

    return (0);
}

int init_philos(t_bag *b)
{
    int i ;

    i = 0;
    while(i < b->nb_p)
    {
        b->p[i].nb = i;
        b->p[i].nb_eat = 0;
        b->p[i].finish = 0;
        b->p[i].left = i;
        b->p[i].right = i + 1 % b->nb_p;
        b->p[i].eat_time = 0;
        b->p[i].b = b;
        b->p[i].tts = b->tts;
        b->p[i].tte = b->tte;
        b->p[i].ttt = b->ttt;
        b->p[i].t = NULL;
    }
    return(0);
}
t_bag   *init_bag(int argc,char **argv)
{
    t_bag *b;

    b = (t_bag*)malloc(sizeof(t_bag));
    if(!b)
        return(error("malloc t_bag failed"),NULL);
    b->nb_p = ft_atoi(argv[1]);
     b->ttd = ft_atoi(argv[2]);
    b->tte = ft_atoi(argv[3]);;
    b->tts = ft_atoi(argv[4]);;
    if(argc == 6)
        b->nb_eat = ft_atoi(argv[5]);
    else
        b->nb_eat = 0;
    if(init_forks(b))
        return (error("init forks failed"),NULL);
    if(init_philos(b))
        return (error("init philos failed"),NULL);
    pthread_mutex_init(&(b->write),NULL);
    b->state = 1;
    return(b);
}
