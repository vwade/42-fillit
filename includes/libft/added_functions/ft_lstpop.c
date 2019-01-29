/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastro <bcastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 06:24:16 by viwade            #+#    #+#             */
/*   Updated: 2019/01/28 19:44:48 by bcastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_include.h"

static void
	del(void *ap, size_t len)
{
	ft_bzero(ap, len);
	ft_memdel(&ap);
}

void
	ft_lstpop(t_list **list)
{
	while (list[0]->next)
		list[0] = list[0]->next;
	ft_lstdel(&list[0], del);
}
