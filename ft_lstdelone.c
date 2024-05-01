/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 12:01:40 by anamedin          #+#    #+#             */
/*   Updated: 2024/05/01 13:26:43 by anamedin         ###   ########.fr       */
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

void del(void *content)
{
    free(content);
}

void ft_lstdelone(t_list *lst, void (*del)(void*))
{
	(* del)(lst->content);
	free(lst);
}


void ft_free(t_list *lst)
{
	t_list *tmp;
	while (lst != NULL)
	{
		tmp = lst;
		lst = lst->next;
		//del(tmp->content);
		free(tmp);
	}
}

int main (void)
{
	t_list *lista = (t_list *) malloc(sizeof(t_list));		
	t_list *node1 = (t_list *) malloc(sizeof(t_list));
    t_list *node2 = (t_list *) malloc(sizeof(t_list));
    t_list *node3 = (t_list *) malloc(sizeof(t_list));
    t_list *node4 = (t_list *) malloc(sizeof(t_list));

     node1->content = "10";
	 node1->next = NULL;

	 node2->content = "25";
	 node2->next = NULL;

	 node3->content = "40";
	 node3->next = NULL;

	 node4->content = "75";
	 node4->next = NULL;

	 //creamos lista
	 lista->next = node1;
	 node1->next = node2;
	 node2->next = node3;
	 node3->next = node4;

	 //aplicamos funcion
	 ft_lstdelone(node2, &del);
	 ft_free(lista);
}
