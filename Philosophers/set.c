/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarg <igarg@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 10:01:32 by igarg             #+#    #+#             */
/*   Updated: 2021/11/29 10:10:30 by igarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	set_philo_dop(t_seating *p)
{
	int	i;

	i = 0;
	while (i < p->count)
	{
		p->philo[i].name = i + 1;
		p->philo[i].fork_one = i;
		if (i - 1 < 0)
			p->philo[i].fork_two = p->count - 1;
		else
			p->philo[i].fork_two = i - 1;
		p->fork[i].id = i + 1;
		pthread_mutex_init(&p->fork[i].mutex_taken, NULL);
		i++;
	}
}

int	set_philo(t_seating *p)
{
	p->philo = malloc(sizeof(t_philo[p->count]));
	if (!p->philo)
	{
		free(p->stream);
		return (0);
	}
	p->fork = malloc(sizeof(t_fork[p->count]));
	if (!p->philo)
	{
		free(p->stream);
		free(p->philo);
		return (0);
	}
	set_philo_dop(p);
	return (1);
}

int	set_arg(char **argv, t_seating *p)
{
	p->count = ft_atoi(argv[1]);
	p->time_die = ft_atoi(argv[2]) * 1000;
	p->time_eat = ft_atoi(argv[3]) * 1000;
	p->time_slip = ft_atoi(argv[4]) * 1000;
	p->num_philo = 0;
	p->stop_life = 0;
	p->stream = malloc(sizeof(pthread_t[p->count]));
	if (p->stream == NULL)
		return (0);
	if (argv[5])
		p->quantity_day = ft_atoi(argv[5]);
	else
		p->quantity_day = -1;
	set_philo(p);
	return (1);
}
