/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 05:06:04 by bkabbas           #+#    #+#             */
/*   Updated: 2016/03/30 07:01:49 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	move(t_core *core, double speed, double x, double y)
{
	t_vector2 *pos;

	pos = &core->player_pos;
	if (core->map[(int)(pos->x + x * 0.3)][(int)pos->y] == 0 ||
		core->map[(int)(pos->x + x * 0.3)][(int)pos->y] == 3)
		pos->x += x * speed;
	if (core->map[(int)pos->x][(int)(pos->y + y * 0.3)] == 0 ||
		core->map[(int)pos->x][(int)(pos->y + y * 0.3)] == 3)
		pos->y += y * speed;
}

void	do_weapon(t_core *core)
{
	static t_bool	weapon_forward = FALSE;
	static int		frames_forward = 0;
	static int		frames_cooldown = 0;

	core->is_attacking = FALSE;
	if (get_mouse_button_down(1) && frames_cooldown <= 0)
	{
		weapon_forward = TRUE;
		core->is_attacking = TRUE;
		frames_forward = 0;
		frames_cooldown = 25;
	}
	if (frames_forward > 15)
		weapon_forward = FALSE;
	frames_cooldown--;
	if (weapon_forward)
	{
		core->weapon_pos = (SDL_Rect) { (double)SCREEN_WIDTH / 2 - 150,
										(double)SCREEN_HEIGHT / 1.7, 0, 0 };
		frames_forward++;
	}
	else
		core->weapon_pos = (SDL_Rect) { (double)SCREEN_WIDTH / 2 - 50,
										(double)SCREEN_HEIGHT / 1.6, 0, 0 };
}

void	do_mouse_look(t_core *core)
{
	t_vector2	mouse_pos;
	t_vector2	screen_half;
	double		rotation;
	double		old_dir_x;
	double		old_plane_x;

	mouse_pos = get_mouse_pos();
	screen_half.x = SCREEN_WIDTH / 2;
	screen_half.y = SCREEN_WIDTH / 2;
	rotation = -((mouse_pos.x - screen_half.x) * 0.01);
	old_dir_x = core->player_dir.x;
	core->player_dir.x = core->player_dir.x * cos(rotation) -
	core->player_dir.y * sin(rotation);
	core->player_dir.y = old_dir_x * sin(rotation) +
	core->player_dir.y * cos(rotation);
	old_plane_x = core->plane.x;
	core->plane.x = core->plane.x * cos(rotation) -
	core->plane.y * sin(rotation);
	core->plane.y = old_plane_x * sin(rotation) +
	core->plane.y * cos(rotation);
}

void	process_events(t_core *core)
{
	double speed;

	speed = 0.05;
	if (get_key_down(O))
		core->warp_pointer = !core->warp_pointer;
	if (get_key_down(R))
		speed = 0.1;
	if (get_key_down(W))
		move(core, speed, core->player_dir.x, core->player_dir.y);
	if (get_key_down(S))
		move(core, speed, -core->player_dir.x, -core->player_dir.y);
	if (get_key_down(A))
		move(core, speed, -core->plane.x, -core->plane.y);
	if (get_key_down(D))
		move(core, speed, core->plane.x, core->plane.y);
	do_weapon(core);
	if (core->warp_pointer)
		do_mouse_look(core);
}
