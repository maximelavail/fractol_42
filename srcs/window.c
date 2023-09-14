/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximelavail <maximelavail@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:55:43 by maximelavai       #+#    #+#             */
/*   Updated: 2023/09/14 15:28:15 by maximelavai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int       ft_arguments_filter(int argc, char **argv, win_data *data)
{        
          (void)    argv;
          if (argc != 1) {
                    printf("Usage: ./fractol\n");
                    return (0);
          }
          data->fract = 2;
          return(3);
}

void	fract_init(win_data *data)
{
	if (data->fract == 0)
		data->wow = 2;
	else if (data->fract == 1)
		data->wow = 1;
	else if (data->fract == 2)
		data->wow = 0;
          fractale_calc(data);
}

void	mlx_win_init(win_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Fract'ol");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img_ptr = mlx_get_data_addr(data->img,
			&data->bpp, &data->sl, &data->endian);
}

int       main(int argc, char **argv)
{
          win_data  data;
          
          if (ft_arguments_filter(argc, argv, &data) != 0) {
                    mlx_win_init(&data);
                    if (!data.mlx)
                              return 1;
                    fractale_init(&data);
                    fract_init(&data);
                    data.show_text = !data.show_text;
		mlx_mouse_hook(data.win, mouse_hook, &data);
		mlx_key_hook(data.win, key_hook, &data);
                    mlx_loop(data.mlx);
          }
          return 0;
}


