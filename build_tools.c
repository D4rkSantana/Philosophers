/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 16:38:15 by esilva-s          #+#    #+#             */
/*   Updated: 2022/12/09 16:36:52 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static t_fork	*search_fork(t_fork *forks, int index)
{
	t_fork	*aux;

	aux = first_fork(forks);
	while (aux != NULL)
	{
		if (aux->index == index)
			return (aux);
		aux = aux->next;
	}
	return (NULL);
}

static void	define_forks(t_data *data)
{
	t_philo	*aux;

	aux = first_philo(data->philos);
	while (aux != NULL)
	{
		aux->my_fork = search_fork(data->forks, aux->index);
		if (aux->index != data->args->nb_philos)
			aux->next_fork = search_fork(data->forks, aux->index + 1);
		else
		{
			aux->next_fork = search_fork(data->forks, aux->index);
			aux->my_fork = search_fork(data->forks, 1);
		}
		aux = aux->next;
	}
}

static void	data_acess(t_data *data)
{
	t_philo	*aux;

	aux = first_philo(data->philos);
	while (aux != NULL)
	{
		aux->data = data;
		aux->status = 1;
		aux = aux->next;
	}
}

static long	get_init_time(void)
{
	long			result;
	struct timeval	now;

	gettimeofday(&now, NULL);
	result = now.tv_sec * 1000;
	result += now.tv_usec / 1000;
	return (result);
}

void	configure(t_data *data)
{
	define_forks(data);
	data_acess(data);
	data->time_init = get_init_time();
}
