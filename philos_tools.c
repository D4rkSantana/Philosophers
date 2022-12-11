/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:28:51 by esilva-s          #+#    #+#             */
/*   Updated: 2022/12/08 16:53:04 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philo	*new_philo(void)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	philo->thread = malloc(sizeof(pthread_t));
	pthread_mutex_init(&philo->mutex, NULL);
	philo->status = 1;
	philo->index = 1;
	philo->last_food = 0;
	philo->my_fork = NULL;
	philo->next_fork = NULL;
	philo->next = NULL;
	philo->previus = NULL;
	philo->data = NULL;
	return (philo);
}

t_philo	*first_philo(t_philo *philo)
{
	t_philo	*aux;

	aux = philo;
	while (aux->previus != NULL)
		aux = aux->previus;
	return (aux);
}

t_philo	*last_philo(t_philo *philo)
{
	t_philo	*aux;

	aux = philo;
	while (aux->next != NULL)
		aux = aux->next;
	return (aux);
}

void	add_philo(t_philo **philo)
{
	t_philo	*new;
	t_philo	*aux;

	new = new_philo();
	aux = last_philo(*philo);
	aux->next = new;
	new->previus = aux;
	new->index = aux->index +1;
}
