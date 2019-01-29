/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_include.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastro <bcastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 22:00:47 by viwade            #+#    #+#             */
/*   Updated: 2019/01/28 19:42:01 by bcastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_INCLUDE_H
# define LIBFT_INCLUDE_H
# include "../libft.h"

void	print_bits(int octal);
void	print_64bits(uint64_t octal);
void	print_64bits_recursive(uint64_t octal);
int		ft_astrcmp(char **s1, char **s2);
void	ft_del(void *ap, size_t len);
size_t	ft_lstlen(t_list *lst);
void	ft_lstpush(t_list **list, t_list *new);
void	ft_lstpop(t_list **list);
void	**ft_lst2arr(t_list *lst);
void	ft_error(const char *message);
size_t	ft_arrlen(char **ar);
char	*ft_strjoin_free(char const *s1, char const *s2);

#endif
