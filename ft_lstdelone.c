/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 12:01:40 by anamedin          #+#    #+#             */
/*   Updated: 2024/05/01 22:36:17 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

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

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst)
	{
		del(lst->content);
		free(lst);
	}
}

void ft_free(t_list **lst)
{
	t_list *tmp;
	while (*lst != NULL)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		printf("%s\n", tmp->content);

		//printf("%s\n", (*lst)->content);
		//free(tmp);
		ft_lstdelone(tmp, del);
	}
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

	// REDIRECCIONAS EL NODO ANTERIOR :
	node1->next = node3;

	//imprimir contenido antes de eliminar
	printf("%s\n", node2->content);

	//eliminar  nodo
	ft_lstdelone(node2, del);

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
