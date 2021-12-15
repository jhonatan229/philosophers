/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 00:42:03 by coder             #+#    #+#             */
/*   Updated: 2021/12/15 18:03:01 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo	philo;

	if (argc < 5)
		return (1);
	memset(&philo, 0, sizeof(t_philo));
	set_args_to_struct(&philo, argv);
	if (valid_args(&philo))
		return (1);
	start_struct(&philo);
	creating_philos(&philo);
	start_dinner(&philo);
	free_all(&philo);
	return (0);
}
