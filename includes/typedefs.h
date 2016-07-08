/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 06:43:39 by bkabbas           #+#    #+#             */
/*   Updated: 2016/03/30 06:44:13 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEFS_H
# define TYPEDEFS_H

typedef struct s_core		t_core;
typedef struct s_ray		t_ray;
typedef struct s_vector2	t_vector2;
typedef struct s_vector2i	t_vector2i;
typedef struct s_texture	t_texture;
typedef enum e_keycode		t_keycode;
typedef enum e_input_cmd	t_input_cmd;
typedef char				t_bool;

enum	e_input_cmd
{
	CMD_GET,
	CMD_SET,
	CMD_SET_ALL,
	CMD_GET_LAST
};
enum	e_keycode
{
	NONE,
	BACK_SPACE,
	TAB,
	DELETE,
	CLEAR,
	RETURN,
	PAUSE,
	ESCAPE,
	SPACE,
	KEYPAD0,
	KEYPAD1,
	KEYPAD2,
	KEYPAD3,
	KEYPAD4,
	KEYPAD5,
	KEYPAD6,
	KEYPAD7,
	KEYPAD8,
	KEYPAD9,
	KEYPAD_PERIOD,
	KEYPAD_DIVIDE,
	KEYPAD_MULTIPLY,
	KEYPAD_MINUS,
	KEYPAD_PLUS,
	KEYPAD_ENTER,
	KEYPAD_EQUALS,
	UP_ARROW,
	DOWN_ARROW,
	RIGHT_ARROW,
	LEFT_ARROW,
	INSERT,
	HOME,
	END,
	PAGE_UP,
	PAGE_DOWN,
	F1,
	F2,
	F3,
	F4,
	F5,
	F6,
	F7,
	F8,
	F9,
	F10,
	F11,
	F12,
	ALPHA0,
	ALPHA1,
	ALPHA2,
	ALPHA3,
	ALPHA4,
	ALPHA5,
	ALPHA6,
	ALPHA7,
	ALPHA8,
	ALPHA9,
	EXCLAIM,
	DOUBLE_QUOTE,
	HASH,
	DOLLAR,
	AMPERSAND,
	QUOTE,
	LEFT_PAREN,
	RIGHT_PAREN,
	ASTERISK,
	PLUS,
	COMMA,
	MINUS,
	PERIOD,
	SLASH,
	COLON,
	SEMICOLON,
	LESS,
	EQUALS,
	GREATER,
	QUESTION,
	AT,
	LEFT_BRACKET,
	BACK_SLASH,
	RIGHT_BRACKET,
	CARET,
	UNDER_SCORE,
	BACK_QUOTE,
	A,
	B,
	C,
	D,
	E,
	F,
	G,
	H,
	I,
	J,
	K,
	L,
	M,
	N,
	O,
	P,
	Q,
	R,
	S,
	T,
	U,
	V,
	W,
	X,
	Y,
	Z,
	NUM_LOCK,
	CAPS_LOCK,
	SCROLL_LOCK,
	RIGHT_SHIFT,
	LEFT_SHIFT,
	LEFT_CONTROL,
	RIGHT_ALT,
	LEFT_ALT,
	LEFT_COMMAND,
	LEFT_APPLE,
	LEFT_WINDOWS,
	RIGHT_COMMAND,
	RIGHT_APPLE,
	RIGHT_WINDOWS,
	ALTGR,
	HELP,
	PRINT,
	SYSREQ,
	BREAK,
	MENU,
	ANY
};

#endif
