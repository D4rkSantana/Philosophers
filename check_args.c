/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 23:21:25 by esilva-s          #+#    #+#             */
/*   Updated: 2022/12/03 18:52:51 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	check_number(char *arg)
{
	int	count;

	count = 0;
	while (arg[count] != '\0')
	{
		if (arg[count] > 47 && arg[count] < 58)
			count++;
		else
			return (1);
	}
	return (0);
}

int	check_arguments(int argc, char **argv)
{
	int	count;

	if (argc != 5 && argc != 6)
	{
		printf("wrong number of arguments\n");
		return (1);
	}
	count = 1;
	while (argv[count] != NULL)
	{
		if (check_number(argv[count]))
		{
			printf("wrong characteres on arguments\n");
			return (1);
		}
		count++;
	}
	return (0);
}
