/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:27:38 by hfeufeu           #+#    #+#             */
/*   Updated: 2024/11/11 22:27:51 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	ft_lstsizec(t_buffer *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

t_buffer	*ft_lstlastc(t_buffer *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_buffer	*ft_lstnewc(char *content)
{
	t_buffer	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	ft_strlcpy(node->buff, content, BUFFER_SIZE);
	node->next = NULL;
	return (node);
}

void	ft_lstadd_backc(t_buffer **lst, t_buffer *new)
{
	t_buffer	*last;

	if (lst == NULL || new == NULL)
		return ;
	last = ft_lstlastc(*lst);
	if (last != NULL)
		last->next = new;
	else
		*lst = new;
}
