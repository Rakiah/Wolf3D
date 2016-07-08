/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 06:43:01 by bkabbas           #+#    #+#             */
/*   Updated: 2016/03/30 06:43:07 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOADER_H
# define LOADER_H

t_vector2i	parse_map_header(t_core *core, char *line);
void		load_map(t_core *core, char *path);
void		load_textures(t_core *core);

#endif
