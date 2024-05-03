/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:04:23 by anamedin          #+#    #+#             */
/*   Updated: 2024/05/03 22:01:51 by anamedin         ###   ########.fr       */
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
	//

void	*multiply(void *content)
{
	t_list	*new_node = NULL;
	int		result;
	int		num;
	char	*str_num;


	//str_num = (char *)content
	result = 2;
	str_num = (char *)new_node->content;
	num = atoi(str_num);
	result = result * num;
	*(int *)new_node->content = result;
	return ((void *)new_node);
}


/*t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
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
}*/



t_list	ft_lstmap(t_list *lst, void*(*f)(void *), void (*del)(void *))
{
	t_list *lst = (t_list *) malloc(sizeof(t_list));
	t_list *tmp = lst;
	t_list *new_node = (t_list *) malloc(sizeof(t_list));

	while (tmp)
	{
		new_node = ft_lstnew(f(tmp->content));
		if (!new_node)
		{
			while (new_lst)
			{
				t_list *next = new_lst->next;
				del(new_lst->content);
				free(new_lst);
				new_lst = next;
			}
		}
		ft_lstadd_back(&new_lst, new_node);
		tmp = tmp->next;
	}
	return (*new_lst);
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

/*void ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *tmp;
	while (*lst)
	{
		tmp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
}*/

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


	t_list *new_nodo = (t_list *) malloc(sizeof(t_list));
	//LLAMAR FUNCION:
	ft_lstmap(new_list, &multiply ,del);
	t_list *tmp2 = new_lst;
	i = 0;
	while (tmp2 != NULL)
	{
		printf("nuevo nodo[%d]: %s\n", i , tmp2->content);
		tmp2 = tmp2->next;
		i++;
	}

	//RECORRER DESPUES DE FUNCION:
	
	ft_free(&lista);
    return (0);
}
