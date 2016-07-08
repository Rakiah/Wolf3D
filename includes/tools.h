/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 06:43:12 by bkabbas           #+#    #+#             */
/*   Updated: 2016/03/30 08:47:43 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# include <wolf3d.h>

void	exit_clean(t_core *core);
void	exit_error(t_core *core, char *message);
void	set_pixel(t_core *core, int x, int y, int color);
int		get_pix(t_core *core, int texture_id, int x, int y);

#endif
