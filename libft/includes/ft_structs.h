/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 06:30:50 by bkabbas           #+#    #+#             */
/*   Updated: 2016/03/30 06:31:34 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCTS_H
# define FT_STRUCTS_H

# include "libft.h"

struct		s_array
{
	void	*array;
	size_t	element_size;
	size_t	bytes_size;
	size_t	count;
};

struct		s_filebuffer
{
	int		fd;
	size_t	stock;
	char	*buffer;
};

#endif
