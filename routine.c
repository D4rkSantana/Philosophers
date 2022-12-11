/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 17:11:21 by esilva-s          #+#    #+#             */
/*   Updated: 2022/12/09 18:50:44 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	eating(t_philo *philo)
{
	long	now;
	t_data	*data;

	data = philo->data;
	if (read_int(&data->finalize, &data->mutex) != 1)
	{	
		usleep(1000);
		pthread_mutex_lock(&philo->my_fork->mutex);
		now = time_now(data->time_init);
		print_mutex(now, philo->index, "has taken a fork", data);
		pthread_mutex_lock(&philo->next_fork->mutex);
		now = time_now(data->time_init);
		print_mutex(now, philo->index, "has taken a fork", data);
		if (read_int(&data->finalize, &data->mutex) != 1)
		{
			now = time_now(data->time_init);
			write_long(&philo->last_food, &philo->mutex, now);
			print_mutex(now, philo->index, "is eating", data);
			usleep(data->args->time_eat * 1000);
		}
		pthread_mutex_unlock(&philo->next_fork->mutex);
		pthread_mutex_unlock(&philo->my_fork->mutex);
	}
}

void	thinking(t_philo *philo)
{
	long	now;
	t_data	*data;

	data = philo->data;
	if (read_int(&data->finalize, &data->mutex) != 1)
	{
		now = time_now(data->time_init);
		print_mutex(now, philo->index, "is thinking", data);
	}
}

void	sleeping(t_philo *philo)
{
	long	now;
	t_data	*data;

	data = philo->data;
	if (read_int(&data->finalize, &data->mutex) != 1)
	{
		now = time_now(data->time_init);
		print_mutex(now, philo->index, "is sleeping", data);
		usleep(data->args->time_sleep * 1000);
	}
}

void	*routine(void *args)
{
	t_philo	*philo;
	t_data	*data;
	int		cicle;

	philo = (t_philo *)args;
	data = philo->data;
	cicle = 0;
	if (philo->index % 2 == 0)
		usleep(1500);
	while (cicle != data->args->nb_eat_end
		&& read_int(&data->finalize, &data->mutex) != 1)
	{
		eating(philo);
		if (read_int(&data->finalize, &data->mutex) != 1)
			cicle++;
		if (cicle == data->args->nb_eat_end)
		{
			write_int(&philo->status, &philo->mutex, 3);
			return (NULL);
		}
		sleeping(philo);
		thinking(philo);
	}
	write_int(&philo->status, &philo->mutex, 4);
	return (NULL);
}
