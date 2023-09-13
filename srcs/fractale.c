/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractale.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximelavail <maximelavail@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:12:20 by maximelavai       #+#    #+#             */
/*   Updated: 2023/09/13 16:48:02 by maximelavai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractale_init(win_data *data)
{
	data->it_max = 50;
	data->zoom = 220;
	data->x1 = -2.2;
	data->y1 = -1.8;
	data->color = 265;
}

void	fractale2_calc(win_data *data)
{
          if(data->wow == 0)
          {
                    // Burningship
                    data->c_r = data->x / data->zoom + data->x1;
                    data->c_i = data->y / data->zoom + data->y1;
                    data->z_r = 0;
                    data->z_i = 0;
                    data->it = 0;
                    while (data->z_r * data->z_r + data->z_i * data->z_i < 8
                                        && data->it < data->it_max)
                    {
                              data->tmp = data->z_r * data->z_r - data->z_i * data->z_i + data->c_r;
                              data->z_i = fabs(2 * data->z_r * data->z_i) + data->c_i;
                              data->z_r = data->tmp;
                              data->it++;
                              
                    }
          } 
          else if (data->wow == 1) 
          {
                    // Mandelbrot
                    data->c_r = data->x / data->zoom + data->x1;
                    data->c_i = data->y / data->zoom + data->y1;
                    data->z_r = 0;
                    data->z_i = 0;
                    data->it = 0;
                    while (data->z_r * data->z_r + data->z_i *
                                        data->z_i < 8 && data->it < data->it_max)
                    {
                              data->tmp = data->z_r;
                              data->z_r = data->z_r * data->z_r -
                                        data->z_i * data->z_i + data->c_r;
                              data->z_i = 2 * data->z_i * data->tmp + data->c_i;
                              data->it++;
                               
                    }
          } 
          else if (data->wow == 2) 
          {
                    // Julia
                    data->z_r = data->x / data->zoom + data->x1;
                    data->z_i = data->y / data->zoom + data->y1;
                    data->it = 0;
                    while (data->z_r * data->z_r + data->z_i
                                        * data->z_i < 8 && data->it < data->it_max)
                    {
                              data->tmp = data->z_r;
                              data->z_r = data->z_r * data->z_r -
                                        data->z_i * data->z_i - 0.8 + (data->c_r / WIDTH);
                              data->z_i = 2 * data->z_i * data->tmp + data->c_i / WIDTH;
                              data->it++;
                              
                    }
          }


	if (data->it == data->it_max)
		put_pxl_to_img(data, data->x, data->y, 0x000000);
	else
		put_pxl_to_img(data, data->x, data->y, (data->color * data->it));
}

void	*fractale(void *tab)
{
	int		tmp;
	win_data	*data;

	data = (win_data *)tab;
	data->x = 0;
	tmp = data->y;
	while (data->x < WIDTH)
	{
		data->y = tmp;
		while (data->y < data->y_max)
		{
			fractale2_calc(data);
			data->y++;
		}
		data->x++;
	}
	return (tab);
}

void fractale_pthread(win_data *data)
{
          win_data tab[THREAD_NUMBER];
          pthread_t t[THREAD_NUMBER];
          int i;

          i = 0;
          while (i < THREAD_NUMBER)
          {
                    ft_memcpy((void *)&tab[i], (void *)data, sizeof(win_data));
                    tab[i].y = THREAD_WIDTH * i;
                    tab[i].y_max = THREAD_WIDTH * (i + 1);
                    pthread_create(&t[i], NULL, fractale, &tab[i]);
                    i++;
          }
          while (i--)
                    pthread_join(t[i], NULL);
          mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
