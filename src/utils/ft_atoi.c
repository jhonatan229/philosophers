/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 00:39:19 by coder             #+#    #+#             */
/*   Updated: 2021/12/15 17:58:39 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//function add one place in my var num that is in function ft_atoi
int static	ft_addnum(int *num, char c)
{
	if (c >= '0' && c <= '9')
	{
		if (*num != 0)
			*num *= 10;
		*num += c - '0';
		return (0);
	}
	return (1);
}

//trasform a string in number if the string contain numeric charactere
int	ft_atoi(const char *nptr)
{
	int	sinal;
	int	num;

	num = 0;
	sinal = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sinal = -1;
		nptr++;
	}
	while (ft_addnum(&num, *nptr) == 0)
		nptr++;
	return (num * sinal);
}
