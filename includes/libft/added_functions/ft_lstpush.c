/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 06:17:09 by viwade            #+#    #+#             */
/*   Updated: 2019/01/15 06:44:48 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_include.h"

void    ft_lstpush(t_list **list, t_list *new)
{
    while (list[0]->next)
        list[0] = list[0]->next;
    if (list[0]->content)
        list[0]->next = new;
    else
    {
        free(list[0]);
        list[0] = new;
    }

}
