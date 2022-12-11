/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 01:38:21 by esilva-s          #+#    #+#             */
/*   Updated: 2022/12/09 16:22:48 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_mutex(long t, int i, char *s, t_data *data)
{
	if (read_int(&data->finalize, &data->mutex) != 1)
	{
		pthread_mutex_lock(&data->print_m);
		printf("%ld Philosopher %d %s\n", t, i, s);
		pthread_mutex_unlock(&data->print_m);
	}
}

void	write_int(int *var, pthread_mutex_t *mutex, int nb)
{
	pthread_mutex_lock(mutex);
	*var = nb;
	pthread_mutex_unlock(mutex);
}

int	read_int(int *var, pthread_mutex_t *mutex)
{
	int	result;

	pthread_mutex_lock(mutex);
	result = *var;
	pthread_mutex_unlock(mutex);
	return (result);
}

void	write_long(long *var, pthread_mutex_t *mutex, long nb)
{
	pthread_mutex_lock(mutex);
	*var = nb;
	pthread_mutex_unlock(mutex);
}

long	read_long(long *var, pthread_mutex_t *mutex)
{
	long	result;

	pthread_mutex_lock(mutex);
	result = *var;
	pthread_mutex_unlock(mutex);
	return (result);
}
