/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 07:04:22 by bkabbas           #+#    #+#             */
/*   Updated: 2016/03/30 08:49:34 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	tex_free(t_node *surf)
{
	SDL_FreeSurface((SDL_Surface *)surf->data);
}

void	exit_clean(t_core *core)
{
	SDL_FreeSurface(core->screen);
	SDL_FreeSurface(core->weapon);
	list_clear_inner(core->textures, tex_free);
	free(core->textures);
	SDL_DestroyWindow(core->window);
	SDL_Quit();
	ft_delete_tab((void **)core->map, core->map_size.y);
	exit(0);
}

void	exit_error(t_core *core, char *message)
{
	ft_putendl(message);
	free(message);
	exit_clean(core);
}

void	set_pixel(t_core *core, int x, int y, int color)
{
	*((unsigned int *)(core->screen->pixels + ((y * core->screen->pitch) +
	(x * core->screen->format->BytesPerPixel)))) = color;
}

int		get_pix(t_core *core, int texture_id, int x, int y)
{
	int			pix;
	SDL_Surface *tex;

	tex = list_get_data_at(core->textures, texture_id);
	pix = ((unsigned char *)tex->pixels)
			[T_W * y * 3 + x * 3 + 0];
	pix = pix + (((unsigned char *)tex->pixels)
			[T_W * y * 3 + x * 3 + 1] << 8);
	pix = pix + (((unsigned char *)tex->pixels)
			[T_W * y * 3 + x * 3 + 2] << 16);
	return (pix);
}
