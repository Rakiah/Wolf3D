/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 07:12:38 by bkabbas           #+#    #+#             */
/*   Updated: 2016/03/30 08:49:12 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raycaster.h>

t_vector2i	calculate_ray(t_core *core, t_ray *ray)
{
	int			line_height;
	t_vector2i	stripe;

	ray->map = (t_vector2i) { (int)ray->pos.x, (int)ray->pos.y };
	calculate_steps(ray);
	throw_ray(core, ray);
	if (ray->hit_side == 0)
	{
		ray->hit_length = (ray->map.x - ray->pos.x +
							(1 - ray->steps.x) / 2) / ray->dir.x;
		ray->hit_pixel_wall = ray->pos.y + ray->hit_length * ray->dir.y;
	}
	else
	{
		ray->hit_length = (ray->map.y - ray->pos.y +
							(1 - ray->steps.y) / 2) / ray->dir.y;
		ray->hit_pixel_wall = ray->pos.x + ray->hit_length * ray->dir.x;
	}
	ray->hit_pixel_wall -= floor(ray->hit_pixel_wall);
	line_height = (int)(SCREEN_HEIGHT / ray->hit_length);
	stripe.x = ft_clamp(-line_height / 2 + SCREEN_HEIGHT / 2, 0, ~(1 << 31));
	stripe.y = ft_clamp(line_height / 2 + SCREEN_HEIGHT / 2,
						(1 << 31), SCREEN_HEIGHT - 1);
	return (stripe);
}

void		calculate_steps(t_ray *ray)
{
	ray->dist_increment.x = sqrt(1 + (ray->dir.y * ray->dir.y) /
									(ray->dir.x * ray->dir.x));
	ray->dist_increment.y = sqrt(1 + (ray->dir.x * ray->dir.x) /
									(ray->dir.y * ray->dir.y));
	if (ray->dir.x < 0)
	{
		ray->steps.x = -1;
		ray->dist.x = (ray->pos.x - ray->map.x) * ray->dist_increment.x;
	}
	else
	{
		ray->steps.x = 1;
		ray->dist.x = (ray->map.x + 1.0 - ray->pos.x) * ray->dist_increment.x;
	}
	if (ray->dir.y < 0)
	{
		ray->steps.y = -1;
		ray->dist.y = (ray->pos.y - ray->map.y) * ray->dist_increment.y;
	}
	else
	{
		ray->steps.y = 1;
		ray->dist.y = (ray->map.y + 1.0 - ray->pos.y) * ray->dist_increment.y;
	}
}

void		throw_ray(t_core *core, t_ray *ray)
{
	ray->hit_material = 0;
	while (ray->hit_material == 0)
	{
		if (ray->dist.x < ray->dist.y)
		{
			ray->dist.x += ray->dist_increment.x;
			ray->map.x += ray->steps.x;
			ray->hit_side = 0;
		}
		else
		{
			ray->dist.y += ray->dist_increment.y;
			ray->map.y += ray->steps.y;
			ray->hit_side = 1;
		}
		ray->hit_material = core->map[ray->map.x][ray->map.y];
	}
}

void		draw_slice(t_core *core, int slice, t_vector2i stripe, t_ray *ray)
{
	t_vector2i		tx;
	int				round;
	int				line_height;
	unsigned int	p;

	line_height = (int)(SCREEN_HEIGHT / ray->hit_length);
	tx.x = (int)(ray->hit_pixel_wall * (double)T_W);
	if (ray->hit_side == 0 && ray->dir.x > 0)
		tx.x = T_W - tx.x - 1;
	if (ray->hit_side == 1 && ray->dir.y < 0)
		tx.x = T_W - tx.x - 1;
	while (stripe.x < stripe.y)
	{
		round = stripe.x * 256 - SCREEN_HEIGHT * 128 + line_height * 128;
		tx.y = ((round * T_H) / line_height) / 256;
		p = get_pix(core, ray->hit_material - 1, tx.x, tx.y);
		if (ray->hit_side == 1)
			p = (p >> 1) & 8355711;
		set_pixel(core, slice, stripe.x, p);
		stripe.x++;
	}
}
