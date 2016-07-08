/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 17:01:48 by bkabbas           #+#    #+#             */
/*   Updated: 2016/03/30 06:46:45 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include "wolf3d.h"

void			fill_inputs(t_core *core);
t_bool			get_focus_event(void);
t_bool			get_mouse_button_up(int code);
t_bool			get_mouse_button_down(int code);
t_bool			get_key_up(t_keycode code);
t_bool			get_key_down(t_keycode code);
t_vector2		get_mouse_pos(void);
t_vector2		get_mouse_motion(void);

t_keycode		get_last_key_down(void);
t_keycode		get_last_key_up(void);
int				get_last_mouse_up(void);
int				get_last_mouse_down(void);

t_keycode		key_up(t_keycode code, t_input_cmd cmd, t_bool value);
t_keycode		key_down(t_keycode code, t_input_cmd cmd, t_bool value);
int				mouse_up(int code, t_input_cmd cmd, t_bool value);
int				mouse_down(int mousebutton, t_input_cmd cmd, t_bool value);
t_vector2		mouse_pos(int x, int y, t_input_cmd cmd);
t_vector2		mouse_motion(int x, int y, t_input_cmd cmd);
t_bool			focus_event(t_input_cmd cmd, t_bool value);

t_keycode		mlx_to_r3d_key(int keycode);
int				mlx_to_r3d_mbutton(int keycode);

t_keycode		f_touch(int keycode);
t_keycode		controls(int keycode);
t_keycode		alpha_num(int keycode);
t_keycode		alphabet_0(int keycode);
t_keycode		alphabet_1(int keycode);
t_keycode		alphabet_2(int keycode);
t_keycode		special_0(int keycode);
t_keycode		special_1(int keycode);
t_keycode		special_2(int keycode);
t_keycode		special_3(int keycode);
t_keycode		special_4(int keycode);
t_keycode		keypad_numbers(int keycode);
t_keycode		keypad_operators(int keycode);

int				internal_key_down_hook(int keycode);
int				internal_key_up_hook(int keycode);
int				internal_mouse_down_hook(int keycode, int x, int y);
int				internal_mouse_up_hook(int keycode, int x, int y);
int				internal_mouse_pos_hook(int x, int y);
int				internal_mouse_motion_hook(int x, int y);

#endif
