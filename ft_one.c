/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_one.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 17:25:29 by anamedin          #+#    #+#             */
/*   Updated: 2024/05/01 17:27:54 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

//lst: el nodo a liberar.
//del: un puntero a la función utilizada para liberar el contenido del nodo
//t_list *lst: Un puntero a una estructura de datos del tipo t_list
//void (*del)(void *): Un puntero a una función que toma un puntero void *
//como argumento y no devuelve nada
typedef struct s_list
{
	void			*content;
	struct s_list	*next;

}					t_list;

void	del(void *content)
{
	free(content);
}


void ft_lstdelone(t_list **lst, t_list *node_to_delete)
{
    t_list *tmp = *lst;
    t_list *prev = NULL;

    // Buscar el nodo a eliminar y su nodo anterior
    while (tmp != NULL && tmp != node_to_delete)
    {
        prev = tmp;
        tmp = tmp->next;
    }

    // Si se encontró el nodo a eliminar
    if (tmp == node_to_delete)
    {
        // Si el nodo a eliminar es el primero de la lista
        if (prev == NULL)
            *lst = tmp->next;
        else
            prev->next = tmp->next;

        // Liberar la memoria del contenido y del nodo
        del(tmp->content);
        free(tmp);
    }
}
//
int main(void)
{
    t_list *lista = NULL;
    t_list *node1 = (t_list *)malloc(sizeof(t_list));
    t_list *node2 = (t_list *)malloc(sizeof(t_list));
    t_list *node3 = (t_list *)malloc(sizeof(t_list));
    t_list *node4 = (t_list *)malloc(sizeof(t_list));

    // RELLENAR CONTENIDO DE LOS NODOS
    node1->content = "10";
    node1->next = node2;

    node2->content = "25";
    node2->next = node3;

    node3->content = "40";
    node3->next = node4;

    node4->content = "75";
    node4->next = NULL;

    lista = node1;

    // Eliminar el nodo2 de la lista
    ft_lstdelone(&lista, node2);

    // Imprimir la lista actualizada
    t_list *tmp = lista;
    int i = 0;
    while (tmp != NULL)
    {
        printf("nodo[%d]: %s\n", i, (char *)tmp->content);
        tmp = tmp->next;
        i++;
    }

    // Liberar la memoria de la lista completa
    //ft_free(&lista);

    return (0);
}

