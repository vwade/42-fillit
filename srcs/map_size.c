/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 13:12:11 by viwade            #+#    #+#             */
/*   Updated: 2019/01/18 07:44:02 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"



/*

n = 4

 str = "0000000000000000"

max x = range[0 thru n-1] = i % n
max y = range[0 thru n-1] = i / n

new coord k;

//	CONVERSION OF STRING INDEX TO X/Y COORDINATE

coord.x = i % n
coord.y = i / n

//	CONVERSION OF X/Y COORDINATE TO STRING INDEX

i = (coord.x) + (coord.y * (n)

*/
