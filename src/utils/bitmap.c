/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 18:11:32 by flohrel           #+#    #+#             */
/*   Updated: 2021/03/02 20:09:32 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"

void	write_header(int outfile, uint32_t *header)
{
	int	i;

	i = -1;
	while (++i < 6)
	{
		ft_putchar_fd(header[i] & 0x000000FF, outfile);
		ft_putchar_fd((header[i] & 0x0000FF00) >> 8, outfile);
		ft_putchar_fd((header[i] & 0x00FF0000) >> 16, outfile);
		ft_putchar_fd((header[i] & (unsigned int)0xFF000000) >> 24, outfile);
	}
	ft_putchar_fd(1, outfile);
	ft_putchar_fd(0, outfile);
	ft_putchar_fd(32, outfile);
	ft_putchar_fd(0, outfile);
	while (++i < 13)
	{
		ft_putchar_fd(header[i] & 0x000000FF, outfile);
		ft_putchar_fd((header[i] & 0x0000FF00) >> 8, outfile);
		ft_putchar_fd((header[i] & 0x00FF0000) >> 16, outfile);
		ft_putchar_fd((header[i] & (unsigned int)0xFF000000) >> 24, outfile);
	}
}

void	set_header(int outfile, int filesize, int width, int height)
{
	uint32_t	header[13];

	header[0] = filesize + 54;
	header[1] = 0;
	header[2] = 54;
	header[3] = 40;
	header[4] = width;
	header[5] = height;
	header[7] = 0;
	header[8] = filesize;
	header[9] = 0;
	header[10] = 0;
	header[11] = 0;
	header[12] = 0;
	ft_putstr_fd("BM", outfile);
	write_header(outfile, header);
}

int		data_to_bmp(t_param *param, t_img *screen)
{
	int				i;
	int				fd;
	int				filesize;
	int				width;

	fd = open("rsrc/screenshot.bmp", O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
		return (error_handler(NULL));
	width = screen->line_length;
	filesize = width * param->win_height;
	set_header(fd, filesize, width / 4, param->win_height);
	i = -1;
	while (++i < param->win_height)
		if (write(fd, screen->addr
			+ (width * (param->win_height - i - 1)), width) == -1)
			return (error_handler(NULL));
	return (SUCCESS);
}
