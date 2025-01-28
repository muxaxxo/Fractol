/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalegria <aalegria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:21:13 by aalegria          #+#    #+#             */
/*   Updated: 2025/01/28 16:52:40 by aalegria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "minilibx-linux/mlx.h"

#define ERROR_MESSAGE "Pleaseenter \n\t\"./fractol mandelbrot\" or
		\n\t\"./fractol julia <value_1> <value_2>\"\n"

#define WIDTH	800
#define HEIGHT	800

# define BLACK       0x000000
# define WHITE       0xFFFFFF
# define RED         0xFF0000
# define GREEN       0x00FF00
# define BLUE        0x0000FF
# define YELLOW      0xFFFF00
# define CYAN        0x00FFFF
# define MAGENTA     0xFF00FF

# define BRIGHT_RED      0xFF6666
# define BRIGHT_GREEN    0x66FF66
# define BRIGHT_BLUE     0x6666FF
# define BRIGHT_YELLOW   0xFFFF66
# define BRIGHT_CYAN     0x66FFFF
# define BRIGHT_MAGENTA  0xFF66FF

# define RAINBOW         0xFF77FF
# define TRIPPY_CYAN     0x77FFFF
# define ACID_GREEN      0x88FF00
# define PURPLE_HAZE     0x8800FF
# define NEON_RAVE       0xFF1188
# define LIME_SHOCK      0x99FF33


typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}			t_img;



typedef struct s_fractal
{
	char	*name
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	double	escape_value;
	int 	iterations_definition;
	double	shift_x;
	double	shift_y;
}			t_fractal;

typedef struct	s_complex
{
	double	x;
	double	y;
}				t_complex

int	ft_strncmp(char *s1, char *s2, int n);
void	putstr_fd(char *s, int fd);

void	fractal_init(tfractal *fractal);

void	fractal_render(t__fractal *fractal);

double map (double unscaled_num, double new_min, double new_max, double old_min. double old_max);
t_complex sum_complex(t_complex z1, t_complex z2);
t_complex square_complex(t_complex z);

int	key_handler(int keysym, t_fractal *fractal);

#endif
