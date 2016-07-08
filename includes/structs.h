/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 06:46:03 by bkabbas           #+#    #+#             */
/*   Updated: 2016/03/30 06:52:07 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

struct				s_vector2i
{
	int				x;
	int				y;
};

struct				s_vector2
{
	double			x;
	double			y;
};

struct				s_core
{
	SDL_Window		*window;
	SDL_Surface		*screen;
	SDL_Surface		*weapon;
	t_list			*textures;
	t_vector2i		map_size;
	t_vector2		player_pos;
	t_vector2		player_dir;
	t_vector2		plane;
	SDL_Rect		weapon_pos;
	t_bool			is_attacking;
	t_bool			warp_pointer;
	int				**map;
};

struct				s_ray
{
	t_vector2i		steps;
	t_vector2i		map;
	t_vector2		pos;
	t_vector2		dir;
	t_vector2		dist;
	t_vector2		dist_increment;
	double			hit_pixel_wall;
	double			hit_length;
	int				hit_side;
	int				hit_material;
};

struct				s_floor_ceil_ray
{
	t_vector2		base_wall;
	double			wall_dist;
	double			player_dist;
};

struct				s_texture
{
	unsigned char	*pixels;
	int				w;
	int				h;
};

#endif
