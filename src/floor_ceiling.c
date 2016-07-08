/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 08:48:38 by bkabbas           #+#    #+#             */
/*   Updated: 2016/03/30 08:49:20 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void		draw_floor_ceil(t_core *core, t_vector2i pos,
							t_vector2 base, t_vector2 dists)
{
	t_vector2	base_curr;
	t_vector2i	base_tex;
	double		weight;
	double		dist_curr;

	while (++pos.y < SCREEN_HEIGHT)
	{
		dist_curr = SCREEN_HEIGHT / (2.0 * pos.y - SCREEN_HEIGHT);
		weight = (dist_curr - dists.y) / (dists.x - dists.y);
		base_curr.x = weight * base.x + (1.0 - weight) * core->player_pos.x;
		base_curr.y = weight * base.y + (1.0 - weight) * core->player_pos.y;
		base_tex = (t_vector2i) { (int)(base_curr.x * T_W) % T_W,
									(int)(base_curr.y * T_H) % T_H };
		set_pixel(core, pos.x, SCREEN_HEIGHT - pos.y,
		get_pix(core, core->textures->count - 2, base_tex.x, base_tex.y));
		set_pixel(core, pos.x, pos.y,
		(get_pix(core, core->textures->count - 1, base_tex.x, base_tex.y) >> 1)
		& 8355711);
	}
}

void		calculate_ray_floor_ceil(t_core *core, t_ray *ray,
									t_vector2i stripe, int x)
{
	t_vector2	base_wall;
	t_vector2	dists;
	t_vector2i	x_y;

	dists = (t_vector2) { ray->hit_length, 0.0 };
	if (ray->hit_side == 0 && ray->dir.x > 0)
		base_wall = (t_vector2) { ray->map.x, ray->map.y +
								ray->hit_pixel_wall };
	else if (ray->hit_side == 0 && ray->dir.x < 0)
		base_wall = (t_vector2) { ray->map.x + 1.0, ray->map.y +
								ray->hit_pixel_wall };
	else if (ray->hit_side == 1 && ray->dir.y > 0)
		base_wall = (t_vector2) { ray->map.x +
								ray->hit_pixel_wall, ray->map.y };
	else
		base_wall = (t_vector2) { ray->map.x +
								ray->hit_pixel_wall, ray->map.y + 1.0 };
	if (stripe.y < 0)
		stripe.y = SCREEN_HEIGHT;
	x_y = (t_vector2i) { x, stripe.y };
	draw_floor_ceil(core, x_y, base_wall, dists);
}
