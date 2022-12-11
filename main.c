/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 15:06:29 by esilva-s          #+#    #+#             */
/*   Updated: 2022/12/09 17:00:15 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	print_died(long t, int i, t_data *data)
{
	pthread_mutex_lock(&data->print_m);
	printf("%ld Philosopher %d is died\n", t, i);
	pthread_mutex_unlock(&data->print_m);
}

static void	build_threads(t_data *data)
{
	t_philo	*aux;

	if (data->args->nb_philos < 2)
	{
		print_died(data->args->time_dead, 1, data);
		write_int(&data->philos->status, &data->philos->mutex, 2);
		return ;
	}
	aux = first_philo(data->philos);
	while (aux != NULL)
	{
		pthread_create(aux->thread, NULL, routine, (void *) aux);
		aux = aux->next;
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (check_arguments(argc, argv))
		return (0);
	data = build(argc, argv);
	if (data == NULL)
		return (0);
	build_threads(data);
	beholder(data);
	destroy_all(data);
	return (0);
}
