/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_converters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <bkabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 22:50:00 by bkabbas           #+#    #+#             */
/*   Updated: 2016/03/30 06:34:14 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rlists.h>

void	**list_to_array(t_list *list)
{
	int		i;
	void	**ret_array;
	t_node	*node;

	ret_array = malloc(sizeof(void *) * list->count);
	node = list->start;
	i = 0;
	while (node != NULL)
	{
		ret_array[i] = node->data;
		node = node->next;
		i++;
	}
	return (ret_array);
}

void	**list_to_array_range(t_list *list, int start, int end)
{
	void	**ret_array;
	t_node	*node;

	ret_array = malloc(sizeof(void *) * (end - start));
	node = list_get_node_at(list, start);
	while (start < end)
	{
		ret_array[start] = node->data;
		node = node->next;
		start++;
	}
	return (ret_array);
}
