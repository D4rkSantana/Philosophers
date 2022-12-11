/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:17:32 by esilva-s          #+#    #+#             */
/*   Updated: 2022/12/08 18:19:47 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	destroy_forks(t_fork **forks)
{
	t_fork	*aux;
	t_fork	*next;

	aux = first_fork(*forks);
	while (aux != NULL)
	{
		next = aux->next;
		pthread_mutex_destroy(&aux->mutex);
		free(aux);
		aux = next;
	}
}

static void	destroy_philos(t_philo **philos)
{
	t_philo	*aux;
	t_philo	*next;

	aux = first_philo(*philos);
	while (aux != NULL)
	{
		next = aux->next;
		free(aux->thread);
		pthread_mutex_destroy(&aux->mutex);
		free(aux);
		aux = next;
	}
}

void	destroy_threads(t_philo **philos)
{
	t_philo	*aux;

	aux = first_philo(*philos);
	while (aux != NULL)
	{
		if (read_int(&aux->status, &aux->mutex) > 2)
			pthread_join(*aux->thread, NULL);
		aux = aux->next;
	}
}

void	wait_finish(t_data *data)
{
	t_philo	*aux;
	int		count;

	count = 0;
	while (1)
	{
		count = 0;
		aux = first_philo(data->philos);
		while (aux != NULL)
		{
			if (read_int(&aux->status, &aux->mutex) > 1)
				count++;
			aux = aux->next;
		}
		if (count == data->args->nb_philos)
			return ;
	}
}

void	destroy_all(t_data *data)
{
	wait_finish(data);
	free(data->args);
	destroy_threads(&data->philos);
	destroy_forks(&data->forks);
	destroy_philos(&data->philos);
	pthread_mutex_destroy(&data->mutex);
	pthread_mutex_destroy(&data->print_m);
	free(data);
}
