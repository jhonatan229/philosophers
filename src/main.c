/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 00:42:03 by coder             #+#    #+#             */
/*   Updated: 2021/12/14 01:03:51 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
	t_philo philo;
	if (argc < 5)
		return (1);
	memset(&philo, 0, sizeof(t_philo));
	set_args_to_struct(&philo, argv);
	start_struct(&philo);
	creating_philos(&philo);
	// printf("args %i, char %li", 2, philo.t_die);
	start_dinner(&philo);
	free_all(&philo);
	printf("congrats!!\n");
	return (0);
}
