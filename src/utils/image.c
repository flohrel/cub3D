/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:04:46 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/18 17:19:24 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "utils/image.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		xpm_to_img(t_vars *vars, t_img *textures, char *filename)
{
	t_img	*img;
	int		width;
	int		height;

	width = TEX_WIDTH;
	height = TEX_HEIGHT;
	img = ft_calloc(1, sizeof(t_img));
	if (!img)
		return (ERROR);
	img->image = mlx_xpm_file_to_image(vars->mlx, filename, &width, &height);
	if (!img->image)
		return (ERROR);
	img->addr = mlx_get_data_addr(img->image, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	if (!img->addr)
		return (ERROR);
	textures = img;
	return (0);
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
	return (0);
}
