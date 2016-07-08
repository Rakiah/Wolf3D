/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 04:54:57 by bkabbas           #+#    #+#             */
/*   Updated: 2016/03/30 01:54:11 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

int		internal_mouse_up_hook(int keycode, int x, int y)
{
	keycode = mlx_to_r3d_mbutton(keycode);
	if (keycode < 0 || keycode > MOUSEBUTTON_COUNT)
		return (0);
	mouse_up(keycode, CMD_SET, TRUE);
	mouse_down(keycode, CMD_SET, FALSE);
	mouse_pos(x, y, CMD_SET);
	return (0);
}

int		get_last_mouse_up(void)
{
	return (mouse_up(-1, CMD_GET_LAST, FALSE));
}

t_bool	get_mouse_button_up(int code)
{
	if (code < 0 || code > MOUSEBUTTON_COUNT)
		return (FALSE);
	return ((t_bool)mouse_up(code, CMD_GET, FALSE));
}

int		mouse_up(int mousebutton, t_input_cmd cmd, t_bool value)
{
	static t_bool	*button = NULL;
	static int		last_button = -1;

	if (button == NULL)
		button = (t_bool *)ft_memalloc(MOUSEBUTTON_COUNT * sizeof(t_bool));
	if (cmd == CMD_SET_ALL)
	{
		mousebutton = 0;
		while (mousebutton < MOUSEBUTTON_COUNT)
			button[mousebutton++] = value;
		last_button = -1;
	}
	else if (cmd == CMD_SET)
	{
		last_button = mousebutton;
		mouse_down(mousebutton, CMD_SET, FALSE);
		button[mousebutton] = value;
	}
	else if (cmd == CMD_GET)
	{
		if (mousebutton == MOUSEBUTTON_COUNT && last_button != -1)
			return (TRUE);
		return (button[mousebutton]);
	}
	return (last_button);
}
