/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 06:42:36 by bkabbas           #+#    #+#             */
/*   Updated: 2016/03/30 06:42:56 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <SDL.h>
# include <libft.h>
# include <get_next_line.h>
# include <rlists.h>
# include <math.h>
# include <fcntl.h>
# include <defines.h>
# include <typedefs.h>
# include <structs.h>
# include <input.h>
# include <tools.h>
# include <raycaster.h>
# include <loader.h>

void	process_events(t_core *core);
void	move(t_core *core, double speed, double x, double y);

#endif
