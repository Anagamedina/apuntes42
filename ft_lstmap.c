/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:04:23 by anamedin          #+#    #+#             */
/*   Updated: 2024/05/04 03:41:24 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

//lst: un puntero a un nodo
// f:  la dirección de un puntero a una función usada
//     en la iteración de cada elemento de la lista.
//del: un puntero a función utilizado para eliminar
//     el contenido de un nodo, si es necesario.

typedef struct s_list
{
	void			*content;
	struct s_list	*next;

}					t_list;

	// CONTENIDO PASARLO A INTEGER
	// INTERGER * NUM
	// GUARDARLO EN NEW_NODE
	// return new_node

/*void    *multiply(void *content)
{
    int     result;
	char	*str;

	str = NULL;
	result = 2 * atoi((char *)content);
	str = itoa(result);
    return ((void *)str);
}*/

void	*f(void *content)
{
    int *original = (int *)content;
    int *duplicated = (int *)malloc(sizeof(int));
    if (!duplicated)
        return NULL;
    *duplicated = *original * 2;
    return (duplicated);
}



t_list  *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list *new_lst = NULL;
    t_list *tmp = lst;

    while (tmp)
    {
        t_list *new_node = ft_lstnew(f(tmp->content));
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




t_list *ft_lstnew (void *content)
{

	t_list	*new_nodo = (t_list*)malloc (sizeof(t_list));
	if (!new_nodo)
		return(NULL);

	new_nodo-> content = content;
	new_nodo->next = NULL;
	return (new_nodo);

}

void ft_lstadd_back(t_list **lst, t_list *new)
{
	if (new == NULL || lst == NULL)
		return;
	if (*lst == NULL)
	{
		*lst = new;
		return;
	}
	t_list *tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

void ft_free(t_list **lst)
{
	t_list *tmp;

	while (*lst != NULL)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp->content);
		free(tmp);
	}
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
