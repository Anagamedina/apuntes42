/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 19:22:59 by anamedin          #+#    #+#             */
/*   Updated: 2024/05/02 20:08:05 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

typedef struct s_list {
    void *content;
    struct s_list *next;
} t_list;

t_list *ft_lstnew(void *content)
{
    t_list *new = (t_list *)malloc(sizeof(t_list));
    if (!new)
        return (NULL);
    new->content = content;
    new->next = NULL;
    return (new);
}

void ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list *tmp;

    if (!*lst)
        *lst = new;
    else
    {
        tmp = *lst;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new;
    }
}

void ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list *tmp;
    while (*lst)
    {
        tmp = (*lst)->next;
        del((*lst)->content);
        free(*lst);
        *lst = tmp;
    }
}

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list *new_lst = NULL;
    t_list *curr = lst;
    t_list *new_node;

    while (curr)
    {
        new_node = ft_lstnew(f(curr->content));
        if (!new_node)
        {
            ft_lstclear(&new_lst, del);
            return (NULL);
        }
        ft_lstadd_back(&new_lst, new_node);
        curr = curr->next;
    }
    return (new_lst);
}

