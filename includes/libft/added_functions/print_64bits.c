/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_64bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastro <bcastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 21:59:40 by viwade            #+#    #+#             */
/*   Updated: 2019/01/28 19:48:32 by bcastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef t_list	t_list_t;

static void
	del(void *ap, size_t len)
{
	ft_bzero(ap, len);
	ft_memdel(&ap);
}

void
	print_64bits(uint64_t llu)
{
	unsigned char	ndx;
	t_list_t		*queue;
	t_list_t		*next;

	ndx = 0x80;
	queue = ft_lstnew(&llu, sizeof(llu));
	while ((ndx = ndx >> 1))
		if ((llu = llu >> 8))
			ft_lstadd(&queue, ft_lstnew(&llu, sizeof(llu)));
		else
			ft_lstadd(&queue, ft_lstnew(&(unsigned char){0}, sizeof(char)));
	next = queue;
	while (next)
	{
		ndx = 0x80;
		llu = next ? ((uint64_t *)(next->content))[0] : 0;
		while (ndx)
		{
			ft_putchar(((unsigned char)llu & ndx) ? '1' : '0');
			ndx = ndx >> 1;
		}
		if ((next = next->next))
			ft_putchar('\n');
	}
	ft_lstdel(&queue, &del);
}
