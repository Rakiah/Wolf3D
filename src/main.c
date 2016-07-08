/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 06:50:56 by bkabbas           #+#    #+#             */
/*   Updated: 2016/03/30 08:51:07 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void		init_game(t_core *core)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		exit_error(core, ft_strjoin("Couldnt init SDL_VIDEO",
					SDL_GetError()));
	if ((core->window = SDL_CreateWindow(TITLE,
					SDL_WINDOWPOS_CENTERED,
					SDL_WINDOWPOS_CENTERED,
					SCREEN_WIDTH, SCREEN_HEIGHT,
					SDL_WINDOW_SHOWN)) == NULL)
		exit_error(core, ft_strjoin("Couldnt create window ",
					SDL_GetError()));
	if ((core->screen = SDL_CreateRGBSurface(0, SCREEN_WIDTH, SCREEN_HEIGHT,
					32, 0, 0, 0, 0)) == NULL)
		exit_error(core, ft_strjoin("Couldnt create screen surface ",
					SDL_GetError()));
	load_map(core, "level_1.w3d");
	load_textures(core);
	core->player_pos = (t_vector2) { PLAYER_POS_X + 0.5, PLAYER_POS_Y + 0.5 };
	core->player_dir = (t_vector2) { -1, 0 };
	core->weapon_pos = (SDL_Rect) { (double)SCREEN_WIDTH / 2 - 50,
									(double)SCREEN_HEIGHT / 1.7, 0, 0 };
	core->plane = (t_vector2) { 0, 0.60 };
	core->warp_pointer = TRUE;
	core->is_attacking = FALSE;
}

void		rasterize_screen(t_core *core)
{
	int			x;
	t_ray		r;
	t_vector2i	stripe;
	double		camera;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		camera = 2 * x / ((double)SCREEN_WIDTH) - 1;
		r.pos = (t_vector2) { core->player_pos.x, core->player_pos.y };
		r.dir.x = core->player_dir.x + core->plane.x * camera;
		r.dir.y = core->player_dir.y + core->plane.y * camera;
		if (core->is_attacking && x == SCREEN_WIDTH / 2 &&
		(r.hit_material == 2 || r.hit_material == 4) && r.hit_length < 0.8)
		{
			if (r.hit_material == 4)
				exit_clean(core);
			core->map[r.map.x][r.map.y] = 0;
			core->is_attacking = FALSE;
		}
		stripe = calculate_ray(core, &r);
		draw_slice(core, x, stripe, &r);
		calculate_ray_floor_ceil(core, &r, stripe, x);
		x++;
	}
}

void		render(t_core *core)
{
	rasterize_screen(core);
	SDL_BlitSurface(core->screen, NULL,
			SDL_GetWindowSurface(core->window), NULL);
	SDL_BlitSurface(core->weapon, NULL,
			SDL_GetWindowSurface(core->window), &core->weapon_pos);
	SDL_UpdateWindowSurface(core->window);
	SDL_FillRect(core->screen, NULL, 0x000000);
}

int			main(void)
{
	t_core core;

	init_game(&core);
	while (42)
	{
		render(&core);
		fill_inputs(&core);
		process_events(&core);
	}
	return (0);
}
