/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximelavail <maximelavail@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:56:00 by maximelavai       #+#    #+#             */
/*   Updated: 2023/09/13 16:42:38 by maximelavai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL
# define FRACT_OL

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "libft.h"
# include "mlx.h"
# include "math.h"
# include <pthread.h>

# define WIDTH 800
# define HEIGHT 600
# define THREAD_WIDTH 7
# define THREAD_NUMBER 120

// Structure donnees fenetre
typedef struct      win_data {
	void		*mlx;
	void		*win;
	void		*img;
	void		*img_ptr;
	int			endian;
	int			sl;
	int			bpp;
	int			fract;
	int			color;
	int			x;
	int			y;
	int			y_max;
	int			it;
	int			it_max;
	int			show_text; // Afficher les iterations
          int                           wow; // Choix de la fractale, effet WOW (non) garantie
	double		zoom;
	double		x1; 
	double		y1;
	double		c_r; // Partie reelle de C
	double		c_i; // Partie imaginaire de C
	double		z_r; // Partie reelle de Z
	double		z_i; // Partie imaginaire de Z
	double		tmp;
} win_data;

int       main(int argc, char **argv);
int       ft_window_close(win_data *data);
int       ft_key_press(int keycode, win_data *data);
int       ft_arguments_filter(int argc, char **argv, win_data *data);
int	mouse_hook(int mousecode, int x, int y, win_data *data);
int	key_hook(int keycode, win_data *data);
int	key_hook2(int keycode, win_data *data);
void	ft_zoom(int x, int y, win_data *data);
void	ft_dezoom(int x, int y, win_data *data);
void	fractale_calc(win_data *data);
void	put_pxl_to_img(win_data *data, int x, int y, int color);
void	fractale_pthread(win_data *data);
void	fractale_init(win_data *data);
void	put_text(win_data *data);
void      fract_init(win_data *data);

#endif
