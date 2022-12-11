/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 22:50:38 by esilva-s          #+#    #+#             */
/*   Updated: 2022/12/08 18:25:43 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>

/* Struct of Forks */
typedef struct s_fork
{
	int				index;
	pthread_mutex_t	mutex;
	void			*next;
	void			*previus;
}	t_fork;

/* 
**	Struct of Philosophers and an Access to Data 
**	
**	status:
**	0 -> uninitialized
**	1 -> initialized
**	2 -> finished solitaire
**	3 -> finished meal
**	4 -> finished
*/
typedef struct s_philo
{
	int				index;
	long			last_food;
	int				status;
	pthread_t		*thread;
	pthread_mutex_t	mutex;
	t_fork			*my_fork;
	t_fork			*next_fork;
	void			*next;
	void			*previus;
	void			*data;
}	t_philo;

/* Program Definitions */
typedef struct s_args
{
	int	nb_philos;
	int	time_dead;
	int	time_eat;
	int	time_sleep;
	int	nb_eat_end;
}	t_args;

/* 
**	Struct containing all program 
**	information and the paths to the linked lists 
*/
typedef struct s_data
{
	int				finalize;
	long			time_init;
	pthread_mutex_t	mutex;
	pthread_mutex_t	print_m;
	t_args			*args;
	t_fork			*forks;
	t_philo			*philos;
}	t_data;

/* tools */
int		ft_atoi(const char *str);

/* check args*/
int		check_arguments(int argc, char **argv);

/* forks tools */
t_fork	*new_fork(void);
t_fork	*first_fork(t_fork *fork);
t_fork	*last_fork(t_fork *fork);
void	add_fork(t_fork **fork);

/* philos tools */
t_philo	*new_philo(void);
t_philo	*first_philo(t_philo *philo);
t_philo	*last_philo(t_philo *philo);
void	add_philo(t_philo **philo);

/* build and configure */
t_data	*build(int argc, char **argv);
void	configure(t_data *data);

/* time */
long	time_now(long init);

/* read and write mutex */
void	print_mutex(long t, int i, char *s, t_data *data);
void	write_int(int *var, pthread_mutex_t *mutex, int nb);
int		read_int(int *var, pthread_mutex_t *mutex);
void	write_long(long *var, pthread_mutex_t *mutex, long nb);
long	read_long(long *var, pthread_mutex_t *mutex);

/* routine */
void	*routine(void *args);

/* beholder */
int		beholder(t_data *data);

/* destroy */
void	destroy_threads(t_philo **philos);
void	destroy_all(t_data *data);

#endif /* PHILOSOPHERS_H */
