/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_linux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximelavail <maximelavail@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:18:55 by maximelavai       #+#    #+#             */
/*   Updated: 2023/09/14 15:33:54 by maximelavai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook2(int keycode, win_data *data)
{
	if (keycode == 50) // Touche 2
		data->color = 2050;
	else if (keycode == 51) // Touche 3
		data->color = 265;
	else if (keycode == 105) // Touche I
		data->show_text = !data->show_text;
          else if (keycode == 99) // Tocuhe C
          {
                    if (data->wow == 0) {
                              data->wow = 1;
                    } else if (data->wow == 1) {
                              data->wow = 2;
                    } else {
                              data->wow = 0;
                    }
          }
	return (0);
}

int	key_hook(int keycode, win_data *data)
{
	if (keycode == 27) // Touche echap
          {
		ft_window_close(data);
                    printf("ESC\n");
          }
          else if (keycode == 43) // Touche +
		data->it_max += 50;
	else if (keycode == 45) // Touche -
		data->it_max -= 50;
	else if (keycode == 68) // Touche fleche gauche
		data->x1 -= 30 / data->zoom;
	else if (keycode == 67) // Touche fleche droite
		data->x1 += 30 / data->zoom;
	else if (keycode == 66) // Touche fleche bas
		data->y1 += 30 / data->zoom;
	else if (keycode == 65) // Touche fleche haut
		data->y1 -= 30 / data->zoom;
	else if (keycode == 32) // Touche espace
		fractale_init(data);
	else if (keycode == 49) // Touche 1
		data->color = 2377215;
	key_hook2(keycode, data);
	fractale_calc(data);
	return (0);
}

void	ft_zoom(int x, int y, win_data *data)
{
	data->x1 = (x / data->zoom + data->x1) - (x / (data->zoom * 1.3));
	data->y1 = (y / data->zoom + data->y1) - (y / (data->zoom * 1.3));
	data->zoom *= 1.3;
	data->it_max++;
}

void	ft_dezoom(int x, int y, win_data *data)
{
	data->x1 = (x / data->zoom + data->x1)  - (x / (data->zoom / 1.3));
	data->y1 = (y / data->zoom + data->y1) - (y / (data->zoom / 1.3));
	data->zoom /= 1.3;
	data->it_max--;
}

int	mouse_hook(int mousecode, int x, int y, win_data *data)
{
	if (mousecode == 4 || mousecode == 1)
		ft_zoom(x, y, data);
	else if (mousecode == 5 || mousecode == 2)
		ft_dezoom(x, y, data);
	fractale_calc(data);
	return (0);
}
