/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloisel <lloisel@student.42.fr >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 00:37:33 by lloisel           #+#    #+#             */
/*   Updated: 2022/10/06 13:57:03 by lloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_arg(int argc,char **argv)
{
    int i;

    i = 1;

    while(i <= argc)
    {
        if(!is_number(argv[i]))
            return(error("one argument is not a number"),0);
        i++;
    }
    return(1);
}