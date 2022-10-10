/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloisel <lloisel@student.42.fr >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:03:07 by lloisel           #+#    #+#             */
/*   Updated: 2022/10/06 18:44:04 by lloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
void print_action(t_philo p,char *s)
{
    pthread_mutex_lock(&(p.b->write));

    if(p.b->state)
    {
        pritnf("%ll ",get_time());
        printf("%d %s \n",p.nb ,s);
    }
    pthread_mutex_unlock(&(p.b->write));
}
void take_forks(t_philo *p)
{
    if(!p->b->state)
        return;
    pthread_mutex_lock(&(p->b->forks[p->left]));
    print_action(*p,"has taken a fork");
    if(!p->b->state)
        return;
    pthread_mutex_lock(&(p->b->forks[p->right]));
    print_action(*p,"has taken a fork");
}

void release_forks(t_philo *p)
{
    pthread_mutex_unlock(&(p->b->forks[p->left]));
    pthread_mutex_unlock(&(p->b->forks[p->right]));
}

void eat(t_philo *p)
{
    take_forks(p);
    p->eat_time = get_time();
    print_action(*p,"is eating");
    release_forks(p);
}
void sleep(t_philo p)
{
    sleep_x(p->tts,p-b)

}
void think(t_philo *p)
{

}
void *exec(void *data)
{
    t_philo *p;

    p = (t_philo *) data;
    printf("numero %d \n",p->nb);
    return (NULL);
}

int join_destroy(t_bag *b)
{
    int i;
    pthread_t *t;

    i = 0;
    while(i < b->nb_p)
    {
        t = b->p[i].t;
        pthread_join(*t,NULL);
        i++;
    }
    i = 0;
    while(i < b->nb_p)
    {
        pthread_mutex_destroy(&(b->forks[i]));
        i++;
    }
    pthread_mutex_destroy(&(b->write));
    return(0);
}

int init_thread(t_bag *b)
{
    int i;
    pthread_t *t;

    i = 0;
    while(i < b->nb_p)
    {
        t = b->p[i].t;
        if(pthread_create(t,NULL,exec,&(b->p[i])))
            return(1);
        i++;
    }
    join_destroy(b);
    return(0);
}

int main(int argc,char **argv)
{
    return (0);
}