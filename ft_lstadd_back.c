/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:51:32 by anamedin          #+#    #+#             */
/*   Updated: 2024/04/30 20:10:47 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

//lst: el puntero al primer nodo de una lista.
//new: el puntero a un nodo que anadir a la lista 

typedef struct s_list
{
	void			*content;
	struct s_list	*next;

}					t_list;

void ft_lstadd_back(t_list **lst, t_list *new)
{
	if (new == NULL || lst == NULL)
		return;

	if (*lst == NULL)
	{
		*lst = new; // Si la lista está vacía, el nuevo nodo se convierte en el primer nodo
		return;
	}

	t_list *tmp = *lst;
	while (tmp->next != NULL)
	{
		tmp = tmp->next; // Avanzar hasta el último nodo de la lista
	}
	tmp->next = new; // Conectar el nuevo nodo al final de la lista
}

int main (void)
{
	t_list *lista = (t_list *) malloc(sizeof(t_list));
	t_list *node1 = (t_list *) malloc(sizeof(t_list));
	t_list *node2 = (t_list *) malloc(sizeof(t_list));
	t_list *node3 = (t_list *) malloc(sizeof(t_list));
	
	node1->content = "10";
	node1->next = NULL;

	node2->content = "25";
	node2->next = NULL;

	node3->content = "40";
	node3->next = NULL;

	//creamos lista
	lista->next = node1;
	node1->next = node2;
	node2->next = node3;

	t_list *new_nodo = (t_list *) malloc(sizeof(t_list));

	new_nodo->content = "75";
	new_nodo->next = NULL;

	ft_lstadd_back(&lista, new_nodo);
	t_list *temp = lista;
	int i = 0;
	while (temp != NULL)
	{
		printf("nodo[%d]: %s\n", i, temp->content);
		temp = temp->next;
		i++;
	}
	return(0);
}
