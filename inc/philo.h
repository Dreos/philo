/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloisel <lloisel@student.42.fr >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:08:50 by lloisel           #+#    #+#             */
/*   Updated: 2022/10/06 18:40:41 by lloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#ifndef PHILO_H
# define PHILO_H



typedef struct s_bag
{
    int         nb_p;
    int         nb_eat;
    struct s_philo p[250];
    pthread_mutex_t forks[250];
    pthread_mutex_t write;
    int    state;
    long long   ttd;
    long long   tts;
    long long   tte;
    long long   ttt;
} t_bag;

typedef struct s_philo
{
    int nb;
    int nb_eat;
    int finish;
    int left;
    int right;
    long long eat_time;
    t_bag *b;
    pthread_t *t;
    long long   tts;
    long long   tte;
    long long   ttt;
}   t_philo;

long long	t_diff(long long first, long long second);
long long	get_time(void);
long long ft_atoi(char *nptr);
int is_number(char *s);
void error(char *s);
t_bag   *init_bag(int argc,char **argv);
void sleep_x(long long time, t_bag *b);



#endif