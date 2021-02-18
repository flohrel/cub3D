/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:04:46 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/18 19:39:24 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "utils/image.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		xpm_to_img(t_vars *vars, t_img **texture, char *filename)
{
	int		width;
	int		height;

	width = TEX_WIDTH;
	height = TEX_HEIGHT;
	*texture = ft_calloc(1, sizeof(t_img));
	if (!*texture)
		return (ERROR);
	(*texture)->image = mlx_xpm_file_to_image(vars->mlx, filename,
			&width, &height);
	if (!(*texture)->image)
		return (ERROR);
	(*texture)->addr = mlx_get_data_addr((*texture)->image,
			&(*texture)->bits_per_pixel,
			&(*texture)->line_length, &(*texture)->endian);
	if (!(*texture)->addr)
		return (ERROR);
	return (0);
}

int		load_texture(t_vars *vars, t_param *param)
{
	int	i;

	i = -1;
	while (++i < 5)
	{
		if (xpm_to_img(vars, &vars->textures[i], param->texture_path[i]) == -1)
			return (ERROR);
	}
	return (SUCCESS);
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
