/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:27:38 by hfeufeu           #+#    #+#             */
/*   Updated: 2024/11/13 00:02:38 by hfeufeu          ###   ########.fr       */
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

t_buffer *ft_lstnewc(char *content, size_t size)
{
    t_buffer *new;

    new = (t_buffer *)malloc(sizeof(t_buffer));
    if (!new)
        return (NULL);
    if (!new->buff)
    {
        free(new);
        return (NULL);
    }
    ft_strlcpy(new->buff, content, size + 1);
	new->size = ft_strlen(content);
    new->next = NULL;
    return (new);
}

void	ft_lstclearc(t_buffer **lst, void (*del)(void*))
{
	t_buffer	*sack;

	if (lst == NULL || del == NULL)
		return ;
	while (*lst)
	{
		sack = (*lst)->next;
		del((*lst)->buff);
		free(*lst);
		*lst = sack;
	}
	(*lst) = NULL;
}
