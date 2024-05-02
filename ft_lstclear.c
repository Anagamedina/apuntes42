/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 22:40:12 by anamedin          #+#    #+#             */
/*   Updated: 2024/05/02 02:14:47 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// lst: la dirección de un puntero a un nodo.
// del: un puntero a función utilizado para eliminar
//      el contenido de un nodo.
//      
//      Elimina y libera el nodo ’lst’ dado y todos los
//		consecutivos de ese nodo, utilizando la función
//		’del’ y free(3).
//		Al final, el puntero a la lista debe ser NULL.

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;

}					t_list;


void	del(void *content)
{
	free(content);
}


void	ft_lstclear(t_list **lst, void(*del)(void *))
{
	t_list *actual;
	t_list *next;
	// revisar que no sea Nulo el doble puntero , ni la funcion 
	
	actual = *lst;
	while (actual != NULL)
	{
		next = actual->next;
		printf("->freed  %p\n", actual);
		del(actual->content);
		free(actual);
		actual = next;
	}
	//*lst = NULL;
}

//void ft_free(t_list **lst)
//{
//	t_list *tmp;
//	while (*lst != NULL)
//	{
//		tmp = *lst;
//		*lst = (*lst)->next;
//		printf("%s\n", tmp->content);
//	}
//}

t_list *ft_lstnew (void *content)
{
	t_list	*new_nodo = (t_list*)malloc (sizeof(t_list));
	if (!new_nodo)
		return(NULL);

	new_nodo-> content = content;
	new_nodo->next = NULL;
	return (new_nodo);
}
int main (void)
{
	t_list *lista = ft_lstnew(strdup("i"));
	t_list *node1 = ft_lstnew(strdup("10"));
	t_list *node2 = ft_lstnew(strdup("25"));
	t_list *node3 = ft_lstnew(strdup("40"));
	t_list *node4 = ft_lstnew(strdup("75"));

   	 //creamos lista
	lista->next = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	t_list *tmp2 = lista->next;
	int i = 0;
	while (tmp2 !=  NULL)
	{
		printf("lista antes de clear[%d]: %s\n",i, tmp2->content);
		tmp2 = tmp2->next;
		i++;

	}
	//printf("head antes de clear: %s\n", lista->content);
	//eliminar  nodo....
	ft_lstclear(&node3, del);


	t_list	*tmp = lista;
	i = 0;
    while (tmp)
	{
		printf("0 %p\n", tmp);
		printf("init %d\n", i);
		printf("- nodo[%d]: %s\n", i, (*tmp).content);
		printf("1 %d\n", i);
		tmp = tmp->next;
		printf("tmp %p")
		printf("2 %d\n", i);
		i++;
    }
	//ft_free(&lista);
    return (0);
}
