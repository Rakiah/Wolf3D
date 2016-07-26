/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loaders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 07:02:57 by bkabbas           #+#    #+#             */
/*   Updated: 2016/07/26 21:18:21 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

t_vector2i	parse_map_header(t_core *core, char *line)
{
	char		**split;
	t_vector2i	size;

	split = ft_strsplit(line, ' ', NULL);
	size = (t_vector2i) { ft_atoi(split[0]), ft_atoi(split[1]) };
	core->map_size = size;
	core->map = (int **)ft_create_tab(size.x, size.y, sizeof(int));
	ft_delete_tab((void **)split, 2);
	free(line);
	return (size);
}

void		load_textures(t_core *core)
{
	core->textures = list_new(sizeof(t_texture));
	list_push_back(core->textures, SDL_LoadBMP("textures/wall.bmp"));
	list_push_back(core->textures, SDL_LoadBMP("textures/cracked_wall.bmp"));
	list_push_back(core->textures, SDL_LoadBMP("textures/stone.bmp"));
	list_push_back(core->textures, SDL_LoadBMP("textures/diamond.bmp"));
	list_push_back(core->textures, SDL_LoadBMP("textures/test.bmp"));
	list_push_back(core->textures, SDL_LoadBMP("textures/ceil.bmp"));
	core->weapon = SDL_LoadBMP("textures/sword.bmp");
	SDL_SetColorKey(core->weapon, SDL_TRUE, 0);
}

void		load_map(t_core *core, char *path)
{
	int			fd;
	t_vector2i	size;
	t_vector2i	pos;
	char		*line;
	char		**split;

	line = NULL;
	if ((fd = open(path, O_RDONLY)) < 0)
		exit_error(core, ft_strjoin("couldnt find file at ", path));
	get_next_line(fd, &line);
	size = parse_map_header(core, line);
	pos.y = 0;
	while (get_next_line(fd, &line) > 0)
	{
		split = ft_strsplit(line, ' ', NULL);
		pos.x = -1;
		while (++pos.x < size.x)
			core->map[pos.x][pos.y] = ft_atoi(split[pos.x]);
		ft_delete_tab((void **)split, size.x);
		free(line);
		pos.y++;
	}
	close(fd);
}
