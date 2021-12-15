/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 00:31:21 by coder             #+#    #+#             */
/*   Updated: 2021/12/15 18:02:43 by coder            ###   ########.fr       */
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
	if (sizemax == 0)
		return (NULL);
	rslt = malloc(sizemax);
	if (rslt == NULL)
		return (NULL);
	ft_bzero(rslt, sizemax);
	return (rslt);
}
