/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_include.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 22:00:47 by viwade            #+#    #+#             */
/*   Updated: 2019/01/14 21:25:57 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_INCLUDE_H
# define LIBFT_INCLUDE_H
# include "../libft.h"

void	print_bits(int octal);
void	print_64bits(uint64_t octal);
void	print_64bits_recursive(uint64_t octal);
size_t	ft_lstlen(t_list *lst);
void	**ft_lst2arr(t_list *lst);
void	ft_error(const char *message);
size_t	ft_arrlen(char **ar);

#endif
