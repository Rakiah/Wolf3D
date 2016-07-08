/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_iterators.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <bkabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 22:50:00 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/27 22:50:00 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rlists.h>

void	*list_next(t_list *list)
{
	void	*data;

	if (list->current >= (int)list->count)
		return (NULL);
	list->current++;
	data = list->iterator->data;
	list->iterator = list->iterator->next;
	return (data);
}

void	*list_prev(t_list *list)
{
	void	*data;

	if (list->current < 0)
		return (NULL);
	list->current--;
	data = list->iterator->data;
	list->iterator = list->iterator->prev;
	return (data);
}

void	list_set_end(t_list *list)
{
	list->iterator = list->end;
	list->current = list->count - 1;
}

void	list_set_start(t_list *list)
{
	list->iterator = list->start;
	list->current = 0;
}

void	list_set_index(t_list *list, int index)
{
	list->iterator = list_get_node_at(list, index);
	list->current = index;
}
