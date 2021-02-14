/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_type.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 17:10:50 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/14 02:42:11 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_TYPE_H
# define DATA_TYPE_H

# ifndef WIN_HEIGHT
#  define WIN_HEIGHT	600
# endif

# ifndef WIN_WIDTH
#  define WIN_WIDTH		800
# endif

typedef struct	s_img
{
	void	*image;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct	s_vect
{
	double	x;
	double	y;
}				t_vect;

typedef struct	s_ivect
{
	int		x;
	int		y;
}				t_ivect;

typedef struct	s_data
{
	double	xcam;
	t_vect	pos;
	t_vect	dir;
	t_vect	plane;
	t_vect	raydir;
	t_vect	sidedist;
	t_vect	deltadist;
	t_vect	step;
	t_ivect	map;
	int		side;
	double	perpwalldist;
	int		pixeltop;
	int		pixelbot;
}				t_data;

typedef struct	s_time
{
	double	time;
	double	old_time;
	double	frame_time;
	double	move_speed;
	double	rot_speed;
}				t_time;

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
	t_img	*img;
	t_data	*data;
	t_time	*time;
	int		kbflags;
}				t_vars;

# endif
