/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 23:25:30 by esilva-s          #+#    #+#             */
/*   Updated: 2022/12/09 11:37:19 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_space(const char *c)
{
	if (*c == ' ' || *c == '\n' || *c == '\t')
		return (1);
	if (*c == '\v' || *c == '\f' || *c == '\r')
		return (1);
	return (0);
}

int	check_size(long nb)
{
	if (!(nb > 2147483647) && !(nb < -2147483648))
		return ((int)nb);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	long	result;
	long	negative;

	negative = 1;
	result = 0;
	while (ft_space(str))
		str++;
	if (*str == '-')
		negative = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && *str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - 48);
		str++;
	}
	result = result * negative;
	return (result);
}
