/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:04:46 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/15 19:42:35 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "img_utils.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		xpm_to_img(t_vars *vars, t_list **textures, char *filename)
{
	t_img	*img;
	t_list	*lst;
	int		width;
	int		height;

	width = TEX_WIDTH;
	height = TEX_HEIGHT;
	img = malloc(sizeof(img));
	img->image = mlx_xpm_file_to_image(vars->mlx, filename, &width, &height);
	if (!img->image)
		return (-1);
	img->addr = mlx_get_data_addr(img->image, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	if (!img->addr)
		return (-1);
	img->mlx = vars->mlx;
	lst = ft_lstnew(img);
	if (!lst)
		return (-1);
	ft_lstadd_back(textures, lst);
	return (0);
}

void	get_fps(t_vars *vars, t_time *time)
{
	char	*fps;

	time->old_time = time->time;
	time->time = clock();
	time->frame_time = (time->time - time->old_time) / CLOCKS_PER_SEC;
	fps = ft_itoa(1 / time->frame_time);
	mlx_string_put(vars->mlx, vars->win, 15, 15, 0xFFFFFFFF, fps);
	time->move_speed = time->frame_time * 10.0;
	time->rot_speed = time->frame_time * 5.0;
	free(fps);
}

void	destroy_textures(void *texture)
{
	t_img	*img;

	img = (t_img *)texture;
	mlx_destroy_image(img->mlx, img->image);
}

int		new_screen(t_vars *vars, t_img *img, int width, int height)
{
	img->image = mlx_new_image(vars->mlx, width, height);
	if (!img->image)
		return (-1);
	img->addr = mlx_get_data_addr(img->image, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	if (!img->addr)
		return (-1);
	img->mlx = vars->mlx;
	return (0);
}
