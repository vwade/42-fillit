/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 05:25:07 by viwade            #+#    #+#             */
/*   Updated: 2019/01/29 19:58:41 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void
	ft_del(void *ap, size_t len)
{
	ft_bzero(ap, len);
	ft_memdel(&ap);
}
