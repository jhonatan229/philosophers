/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 00:31:21 by coder             #+#    #+#             */
/*   Updated: 2021/12/08 00:32:43 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// transform, in my string s, n bytes in \0 
static void	ft_bzero(void *s, size_t n)
{
	size_t			count;
	unsigned char	*p;

	p = (unsigned char *)s;
	count = 0;
	while (count < n)
	{
		*p = 0;
		p++;
		count++;
	}
	return ;
}

//give me nmeb * size spaces in memory, put \0 in each space of memory
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*rslt;
	int		sizemax;

	sizemax = nmemb * size;
	//verify if the result of multiplication give me 0, if true, function return is null
	if (sizemax == 0)
		return (NULL);
	rslt = malloc(sizemax);
	//verify if the malloc works
	if (rslt == NULL)
		return (NULL);
	//call my function ft_bzero to put \0 in each space
	ft_bzero(rslt, sizemax);
	return (rslt);
}
