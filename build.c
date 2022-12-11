/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 15:32:17 by esilva-s          #+#    #+#             */
/*   Updated: 2022/12/08 18:19:00 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static t_args	*init_args(void)
{
	t_args	*args;

	args = NULL;
	args = malloc(sizeof(t_args));
	args->nb_eat_end = -1;
	args->nb_philos = 0;
	args->time_dead = 0;
	args->time_eat = 0;
	args->time_sleep = 0;
	return (args);
}

static t_args	*build_args(int argc, char **argv)
{
	t_args	*args;

	args = NULL;
	args = init_args();
	args->nb_philos = ft_atoi(argv[1]);
	args->time_dead = ft_atoi(argv[2]);
	args->time_eat = ft_atoi(argv[3]);
	args->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		args->nb_eat_end = ft_atoi(argv[5]);
	if (args->nb_philos < 1 || args->time_dead < 1
		|| args->time_eat < 1 || args->time_sleep < 1)
	{
		free (args);
		return (NULL);
	}
	return (args);
}

static t_fork	*build_forks(int nb_philos)
{
	t_fork	*forks;
	int		index;

	forks = NULL;
	index = 1;
	forks = new_fork();
	while (index < nb_philos)
	{
		add_fork(&forks);
		index++;
	}
	return (forks);
}

static t_philo	*build_philos(int nb_philos)
{
	t_philo	*philos;
	int		index;

	philos = NULL;
	index = 1;
	philos = new_philo();
	while (index < nb_philos)
	{
		add_philo(&philos);
		index++;
	}
	return (philos);
}

t_data	*build(int argc, char **argv)
{
	t_data	*data;

	data = NULL;
	data = malloc(sizeof(t_data));
	data->finalize = 0;
	data->time_init = 0;
	pthread_mutex_init(&data->mutex, NULL);
	pthread_mutex_init(&data->print_m, NULL);
	data->args = build_args(argc, argv);
	if (data->args == NULL)
	{
		free (data);
		return (NULL);
	}
	data->forks = build_forks(data->args->nb_philos);
	data->philos = build_philos(data->args->nb_philos);
	configure(data);
	return (data);
}
