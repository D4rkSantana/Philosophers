/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   beholder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:44:47 by esilva-s          #+#    #+#             */
/*   Updated: 2022/12/09 16:59:41 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static long	check_dead(t_data *data, t_philo *philo, long *now)
{
	*now = 0;
	pthread_mutex_lock(&philo->mutex);
	*now = time_now(data->time_init);
	if ((*now - philo->last_food) >= data->args->time_dead)
	{
		write_int(&data->finalize, &data->mutex, 1);
		pthread_mutex_unlock(&philo->mutex);
		return (*now);
	}
	pthread_mutex_unlock(&philo->mutex);
	return (0);
}

static void	print_died(long t, int i, t_data *data)
{
	pthread_mutex_lock(&data->print_m);
	printf("%ld Philosopher %d is died\n", t, i);
	pthread_mutex_unlock(&data->print_m);
}

static int	loop_aux(t_data *data)
{
	t_philo	*aux;
	long	now;
	int		finish_eat;

	finish_eat = 0;
	aux = first_philo(data->philos);
	while (aux != NULL)
	{
		usleep(1000);
		if (check_dead(data, aux, &now))
		{
			usleep(6000);
			print_died(now, aux->index, data);
			return (1);
		}
		if (read_int(&aux->status, &aux->mutex) == 3)
			finish_eat++;
		aux = aux->next;
	}
	if (finish_eat == data->args->nb_philos)
		return (1);
	return (0);
}

int	beholder(t_data *data)
{
	usleep(1000);
	while (data->args->nb_philos > 1)
	{
		if (loop_aux(data))
			return (1);
	}
	return (0);
}
