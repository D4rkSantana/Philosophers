/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:47:05 by esilva-s          #+#    #+#             */
/*   Updated: 2022/12/04 00:07:27 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_fork	*new_fork(void)
{
	t_fork	*fork;

	fork = NULL;
	fork = malloc(sizeof(t_fork));
	fork->index = 1;
	pthread_mutex_init(&fork->mutex, NULL);
	fork->next = NULL;
	fork->previus = NULL;
	return (fork);
}

t_fork	*first_fork(t_fork *fork)
{
	t_fork	*aux;

	aux = fork;
	while (aux->previus != NULL)
		aux = aux->previus;
	return (aux);
}

t_fork	*last_fork(t_fork *fork)
{
	t_fork	*aux;

	aux = fork;
	while (aux->next != NULL)
		aux = aux->next;
	return (aux);
}

void	add_fork(t_fork **fork)
{
	t_fork	*new;
	t_fork	*aux;

	new = new_fork();
	aux = last_fork(*fork);
	aux->next = new;
	new->previus = aux;
	new->index = aux->index +1;
}

t_fork	*make_forks(int nb_philos)
{
	t_fork	*result;
	int		i;

	result = NULL;
	result = new_fork();
	i = 1;
	while (i < nb_philos)
	{
		add_fork(&result);
		i++;
	}
	return (result);
}
