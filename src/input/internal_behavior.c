/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_behavior.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 06:14:15 by bkabbas           #+#    #+#             */
/*   Updated: 2016/03/30 07:02:53 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

static void	internal_inputs(void)
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			exit(0);
		else if (event.type == SDL_KEYDOWN)
			internal_key_down_hook(event.key.keysym.sym);
		else if (event.type == SDL_KEYUP)
			internal_key_up_hook(event.key.keysym.sym);
		else if (event.type == SDL_MOUSEMOTION)
			internal_mouse_pos_hook(event.motion.x, event.motion.y);
		else if (event.type == SDL_MOUSEBUTTONDOWN)
			internal_mouse_down_hook(event.button.button,
						event.button.x,
						event.button.y);
		else if (event.type == SDL_MOUSEBUTTONUP)
			internal_mouse_up_hook(event.button.button,
						event.button.x,
						event.button.y);
		else if (event.type == SDL_WINDOWEVENT)
			if (event.window.event == SDL_WINDOWEVENT_CLOSE)
				exit(0);
	}
}

static void	reset_inputs(void)
{
	key_up(-1, CMD_SET_ALL, FALSE);
	mouse_up(-1, CMD_SET_ALL, FALSE);
}

void		fill_inputs(t_core *core)
{
	internal_inputs();
	if (core->warp_pointer)
		SDL_WarpMouseInWindow(core->window, SCREEN_WIDTH / 2,
											SCREEN_HEIGHT / 2);
	reset_inputs();
}
