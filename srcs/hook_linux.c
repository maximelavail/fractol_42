/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_linux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximelavail <maximelavail@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:18:55 by maximelavai       #+#    #+#             */
/*   Updated: 2023/09/17 22:06:28 by maximelavai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook2(int keycode, win_data *data)
{
	if (keycode == XK_2) // Touche 2
		data->color = 2050;
	else if (keycode == XK_3) // Touche 3
		data->color = 265;
	else if (keycode == XK_i) // Touche I
		data->show_text = !data->show_text;
          else if (keycode == XK_c) // Tocuhe C
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
          Display *display = data->display;

          if (keycode == XK_Escape) // Touche echap
          ft_window_close(data);
          else if (keycode == XK_plus) // Touche +
          data->it_max += 50;
          else if (keycode == XK_minus) // Touche -
          data->it_max -= 50;
          else if (keycode == XK_Left) // Touche fleche gauche
          data->x1 -= 30 / data->zoom;
          else if (keycode == XK_Right) // Touche fleche droite
          data->x1 += 30 / data->zoom;
          else if (keycode == XK_Down) // Touche fleche bas
          data->y1 += 30 / data->zoom;
          else if (keycode == XK_Up) // Touche fleche haut
          data->y1 -= 30 / data->zoom;
          else if (keycode == XK_space) // Touche espace
          fractale_init(data);
          else if (keycode == XK_1) // Touche 1
          data->color = 2377215;

          // Appelez key_hook2 après les autres vérifications
          key_hook2(keycode, data);

          KeySym key = XkbKeycodeToKeysym(display, keycode, 0, 0);
          (void)key;
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
