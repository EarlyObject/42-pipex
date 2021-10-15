/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 09:36:06 by asydykna          #+#    #+#             */
/*   Updated: 2021/09/15 12:38:13 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void
	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*dest;

	dest = b;
	if (!b)
		return (NULL);
	while (len > 0)
	{
		*dest = (unsigned char)c;
		dest++;
		len--;
	}
	return (b);
}
