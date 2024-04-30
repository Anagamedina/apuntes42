/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:46:10 by anamedin          #+#    #+#             */
/*   Updated: 2024/04/30 10:21:02 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}		t_list;

void	insertarLista(t_list *nodo_anterior, void *dato)
{
    t_list	*nodo_nuevo = (t_list *) malloc(sizeof(t_list));

	nodo_nuevo->content = dato;
	nodo_nuevo->next = nodo_anterior->next;
	nodo_anterior->next = nodo_nuevo;
}

int	main()
{
	t_list	*lista = (t_list *) malloc(sizeof(t_list));

	t_list	*node1 = (t_list *) malloc(sizeof(t_list));
	t_list	*node2 = (t_list *) malloc(sizeof(t_list));
	t_list	*node3 = (t_list *) malloc(sizeof(t_list));

	node1->content = "10";
	node1->next = NULL;

	node2->content = "25";
	node2->next = NULL;

	node3->content = "40";
	node3->next = NULL;

	// CREAMOS LA LISTA
	lista->next = node1;
	node1->next = node2;
	node2->next = node3;

	insertarLista(node2, "75");	
	int	i = 0;
	while (lista != NULL)
	{
		printf("nodo[%d]: %s\n",i, lista->content);
		lista = lista->next;
		i++;
	}
	return (0);
}
