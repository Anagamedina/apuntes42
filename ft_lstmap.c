/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:04:23 by anamedin          #+#    #+#             */
/*   Updated: 2024/05/02 20:07:53 by anamedin         ###   ########.fr       */
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


t_list  ft_lstmap(t_list *lst, void*(*f)(void *), void (*del)(void *))
{
	t_list *new_lst = NULL;
	t_list *current = lst;
	t_list *new_node;
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

int main (void)
{
	t_list *lista = ft_lstnew(strdup(""));
	t_list *node1 = ft_lstnew(strdup("10"));
	t_list *node2 = ft_lstnew(strdup("25"));
	t_list *node3 = ft_lstnew(strdup("40"));
	t_list *node4 = ft_lstnew(strdup("75"));

   	 //creamos lista
	lista->next = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;


	//aplicar funcion x:
	ft_lstiter(lista,(void *)printf);

	printf("despues de aplicar funcion: %s", (char *)lista->content);

	//RECORRER LISTA DESPUES:

	t_list	*tmp = lista;
	int i;
	i = 0;
    while (tmp != NULL)
	{
		printf("nodo[%d]: %s\n", i, tmp->content);
		tmp = tmp->next;
		i++;
    }
	ft_free(&lista);
    return (0);
}
