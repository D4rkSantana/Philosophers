/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:29:52 by esilva-s          #+#    #+#             */
/*   Updated: 2022/12/08 16:49:49 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static long	calcule_timeval(struct timeval *now)
{
	long	result;

	result = now->tv_sec * 1000;
	result += now->tv_usec / 1000;
	return (result);
}

long	time_now(long init)
{
	struct timeval	now;
	long			result;

	gettimeofday(&now, NULL);
	result = calcule_timeval(&now);
	result -= init;
	return (result);
}
