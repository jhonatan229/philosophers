/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 00:46:13 by coder             #+#    #+#             */
/*   Updated: 2021/12/15 17:54:34 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(char *str)
{
	int	count;

	count = 0;
	if (str == 0)
		return (1);
	while (str[count])
	{
		if (str[count] < '0' && str[count] > '9')
			return (1);
		count++;
	}
	return (0);
}
