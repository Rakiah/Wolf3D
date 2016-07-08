/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 06:41:58 by bkabbas           #+#    #+#             */
/*   Updated: 2016/03/30 08:53:17 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTER_H
# define RAYCASTER_H

# include <wolf3d.h>

t_vector2i	calculate_ray(t_core *core, t_ray *ray);
void		calculate_steps(t_ray *ray);
void		throw_ray(t_core *core, t_ray *ray);
void		draw_slice(t_core *core, int slice, t_vector2i stripe, t_ray *ray);
void		calculate_ray_floor_ceil(t_core *c, t_ray *r, t_vector2i s, int x);
void		rasterize_screen(t_core *core);

#endif
