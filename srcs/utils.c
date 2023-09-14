/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximelavail <maximelavail@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:50:03 by maximelavai       #+#    #+#             */
/*   Updated: 2023/09/14 15:28:02 by maximelavai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int       ft_window_close(win_data *data)
{
          mlx_destroy_window(data->mlx, data->win);
          exit(0);
          return (0);
}

void	put_pxl_to_img(win_data *data, int x, int y, int color)
{
	if (data->x < WIDTH && data->y < HEIGHT)
	{
		color = mlx_get_color_value(data->mlx, color);
		ft_memcpy(data->img_ptr + 4 * WIDTH * y + x * 4,
				&color, sizeof(int));
	}
}

void	fractale_calc(win_data *data)
{
	if (data->it_max < 0)
		data->it_max = 0;
          else if (data->fract == 2)
		fractale_pthread(data);
	if (data->show_text)
		put_text(data);
}

void	put_text(win_data *data)
{
	char	*text_iteration;
          char      *text_fractale;
	char	*nb;

	nb = ft_itoa(data->it_max);
	text_iteration = ft_strjoin("iterations : ", nb);
	mlx_string_put(data->mlx, data->win, 10, 10, 0xFFFFFF, text_iteration);
	ft_strdel(&text_iteration);
	ft_strdel(&nb);

          text_fractale = ft_strjoin("Pour afficher une fractale appuyez sur ESPACE", "");
          if (data->wow == 2)
                    text_fractale = ft_strjoin("Fractale : Julia", "");
          else if (data->wow == 1)
                    text_fractale = ft_strjoin("Fractale : Mandelbrot", "");
          else if (data->wow == 0)
                    text_fractale = ft_strjoin("Fractale : Burningship", "");

	mlx_string_put(data->mlx, data->win, 10, 30, 0xFFFFFF, text_fractale);
	ft_strdel(&text_fractale);
          
}