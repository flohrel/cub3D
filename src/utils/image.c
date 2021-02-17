/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:04:46 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/17 16:07:08 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "utils/image.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

/*int		xpm_to_img(t_vars *vars, t_list **textures, char *filename)
{
	t_img	*img;
	t_list	*lst;
	int		width;
	int		height;

	width = TEX_WIDTH;
	height = TEX_HEIGHT;
	img = ft_calloc(1, sizeof(t_img));
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

int		load_textures(t_vars *vars)
{
	if (xpm_to_img(vars, &vars->textures, MLX_TEX0) == -1 ||
		xpm_to_img(vars, &vars->textures, MLX_TEX1) == -1 ||
		xpm_to_img(vars, &vars->textures, MLX_TEX2) == -1 ||
		xpm_to_img(vars, &vars->textures, MLX_TEX3) == -1 ||
		xpm_to_img(vars, &vars->textures, MLX_TEX4) == -1 ||
		xpm_to_img(vars, &vars->textures, MLX_TEX5) == -1)
		return (ERROR);
	return (SUCCESS);
}
*/
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
