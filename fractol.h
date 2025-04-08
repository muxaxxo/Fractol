/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalegria <aalegria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:21:13 by aalegria          #+#    #+#             */
/*   Updated: 2025/04/03 15:38:40 by aalegria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"

typedef struct s_args
{
	size_t	time;
	double	zoom;
	double	zoom_mov_x;
	double	zoom_mov_y;
	double	movement_x;
	double	movement_y;
	size_t	min_i;
	size_t	max_i;
}		t_args;

typedef struct s_res
{
	int	x;
	int	y;
}			t_res;

typedef struct s_win_d
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_res	res;
}				t_win_d;

typedef struct s_mandelbrot
{
	double	x0;
	double	x;
	double	x2;
	double	y0;
	double	y;
	double	y2;
}			t_mandelbrot;

typedef struct s_julia
{
	double	r;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	double	n;
	double	x_tmp;
}			t_julia;

typedef struct s_render_data
{
	t_args	args;
	t_win_d	img;
	void	*mlx;
	void	*win;
	int		argc;
	char	**argv;
	t_julia	julia;
}		t_render_data;

// MAIN FUNCTIONS

int		main(int argc, char *argv[]);
void	create_hooks(t_render_data *r_d);
int		draw(t_render_data *args);
int		parse_args(t_render_data *args);
int		notify_usage(void);

// FRACTALS

int		get_mandelbrot(int x, int y, t_res res, t_args args);

int		get_julia(int x, int y, t_render_data *data, t_julia vs);
void	construct(t_julia *this);

// MEMORY MANAGEMENT

void	check_err(t_win_d img, size_t bytes_written, void *mlx, void *win);

void	free_all(t_render_data *d);
//	Returns 1
int		free_img(t_render_data *d);
int		free_mlx(t_render_data *d);
int		free_win(t_render_data *d);

#endif