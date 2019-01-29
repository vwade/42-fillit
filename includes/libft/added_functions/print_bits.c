/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastro <bcastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 21:59:40 by viwade            #+#    #+#             */
/*   Updated: 2019/01/28 19:38:10 by bcastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void
	print_bits(int octal)
{
	unsigned char ndx;

	ndx = 0x80;
	if (octal == -1)
		return ;
	while (ndx)
	{
		ft_putchar(((unsigned char)octal & ndx) ? '1' : '0');
		ndx = ndx >> 1;
	}
}
