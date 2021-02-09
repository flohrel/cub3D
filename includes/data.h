/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:48:39 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/09 02:25:35 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# define Y	0
# define X	1

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
	double	xcam;
	double	pos[2];
	double	dir[2];
	double	plane[2];
	double	raydir[2];
	int		step[2];
	int		map[2];
	double	sidedist[2];
	double	deltadist[2];
	double	perpdist;
}				t_vect;

typedef struct	s_time
{
	double	time;
	double	old_time;
	double	frame_time;
}				t_time;

typedef struct	s_param
{
	double	move_speed;
	double	rot_speed;
}				t_param;

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
	t_img	*img;
	t_vect	*data;
	t_time	*time;
	t_param	*param;
}				t_vars;

#endif
