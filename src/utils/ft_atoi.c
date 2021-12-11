/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 00:39:19 by coder             #+#    #+#             */
/*   Updated: 2021/12/11 00:39:42 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//function add one place in my var num that is in function ft_atoi
int static	ft_addnum(int *num, char c)
{
	//add one place if my c is number, and return 0 if is true
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
	//my pointer nptr going to next position if the charactere is \n, space, \t, \b, \f and \v
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	//verify if my position contai - or +, simboling a number negative or sinal
	if (*nptr == '+' || *nptr == '-')
	{
		//verify if my position is -, if true, my var sinal get -1
		if (*nptr == '-')
			sinal = -1;
		nptr++;
	}
	//a while that stay in loop if my refurn of addnum function is 0
	while (ft_addnum(&num, *nptr) == 0)
		nptr++;
	// return my num * sinal (transforming the num in negative if sinal is -1)
	return (num * sinal);
}