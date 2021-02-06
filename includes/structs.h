/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:48:39 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/06 20:02:07 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct	s_img
{
	void	*image;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct	s_data
{
	double	xpos;
	double	ypos;
	double	xdir;
	double	ydir;
	double	xplane;
	double	yplane;
	double	xcam;
	double	xraydir;
	double	yraydir;
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
}				t_vars;

#endif
