/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 17:10:50 by flohrel           #+#    #+#             */
/*   Updated: 2021/03/01 02:10:27 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_TYPE_H
# define DATA_TYPE_H

# include <stdint.h>
# include <stdbool.h>
# include "libft/list.h"

typedef struct	s_img
{
	void		*image;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct	s_vect
{
	double		x;
	double		y;
}				t_vect;

typedef struct	s_ivect
{
	int			x;
	int			y;
}				t_ivect;

typedef struct	s_data
{
	double		xcam;
	t_vect		pos;
	t_vect		dir;
	t_vect		plane;
	t_vect		raydir;
	t_vect		sidedist;
	t_vect		deltadist;
	t_vect		step;
	t_ivect		map;
	int			side;
	double		perpwalldist;
	int			pixeltop;
	int			pixelbot;
	int			stripe_len;
	double		xwall;
	int			tex_id;
	t_ivect		tex;
	double		*zbuffer;
}				t_data;

typedef struct	s_time
{
	double		time;
	double		old_time;
	double		frame_time;
	double		move_speed;
	double		rot_speed;
}				t_time;

typedef struct	s_sprite
{
	t_vect		pos;
	t_vect		pos2;
	double		invdet;
	t_vect		transform;
	int			screenx;
	int			height;
	int			width;
	t_vect		draw_start;
	t_vect		draw_end;
	float		distance;
	t_ivect		tex;
}				t_sprite;

typedef struct	s_param
{
	int			win_height;
	int			win_width;
	int			map_height;
	int			map_width;
	int			**map;
	uint32_t	floor_color;
	uint32_t	ceil_color;
	char		*texture_path[5];
	char		flags;
	t_ivect		pos;
	bool		save;
}				t_param;

typedef struct	s_vars
{
	t_param		*param;
	void		*mlx;
	void		*win;
	t_img		*screen;
	t_data		*data;
	t_time		*time;
	t_img		textures[5];
	t_list		*sprites;
	char		**map;
	int			kbflags;
}				t_vars;

# endif
