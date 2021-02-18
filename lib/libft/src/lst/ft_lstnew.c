/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:10:38 by yjung             #+#    #+#             */
/*   Updated: 2021/02/18 15:16:33 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_lstnew -  returns a new element with initialized
*/

t_list	*ft_lstnew(void *content)
{
	t_list	*result;

	if (!(result = malloc(sizeof(t_list))))
		return (0);
	result->content = content;
	result->next = 0;
	return (result);
}
