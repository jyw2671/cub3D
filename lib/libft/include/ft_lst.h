/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:12:00 by yjung             #+#    #+#             */
/*   Updated: 2021/02/18 15:51:50 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LST_H
# define FT_LST_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# include "ft_lst_type.h"

void    ft_lstclear(t_list **lst, void (*del)(void*));
int     ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new_list);
t_list  *ft_lstnew(void *content);
t_list  *ft_lstlast(t_list *lst);

#endif
