/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 19:22:59 by anamedin          #+#    #+#             */
/*   Updated: 2024/05/03 22:27:25 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void    *multiply(void *content)
{
    int result = 2 * atoi((char *)content);

    t_list *new_node = ft_lstnew(&result, sizeof(int));
    if (!new_node)
        return NULL;

    return (void *)new_node;
}
t_list  *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list *new_lst = NULL;
    t_list *tmp = lst;

    while (tmp)
    {
        t_list *new_node = (t_list *)f(tmp->content);
        if (!new_node)
        {
            ft_free(&new_lst);
            return NULL;
        }
        ft_lstadd_back(&new_lst, new_node);
        tmp = tmp->next;
    }
    return new_lst;
}
int main(void)
{
    t_list *lista = ft_lstnew(strdup(""));
    t_list *node1 = ft_lstnew(strdup("10"));
    t_list *node2 = ft_lstnew(strdup("25"));
    t_list *node3 = ft_lstnew(strdup("40"));
    t_list *node4 = ft_lstnew(strdup("75"));

    // Creamos lista
    lista->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    // Recorremos lista antes de la función
    t_list *tmp = lista;
    int i = 0;
    while (tmp != NULL)
    {
        printf("nodo[%d]: %s\n", i, (char *)tmp->content);
        tmp = tmp->next;
        i++;
    }

    // Llamamos a la función
    t_list *new_lst = ft_lstmap(lista, &multiply, ft_free);
    if (!new_lst)
    {
        printf("Error al mapear la lista.\n");
        return 1;
    }

    // Recorremos la nueva lista
    tmp = new_lst;
    i = 0;
    while (tmp != NULL)
    {
        printf("nuevo nodo[%d]: %d\n", i, *(int *)(tmp->content));
        tmp = tmp->next;
        i++;
    }

    // Liberamos memoria
    ft_free(&lista);
    ft_free(&new_lst);

    return 0;
}

