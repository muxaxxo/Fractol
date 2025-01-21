/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalegria <aalegria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:21:13 by aalegria          #+#    #+#             */
/*   Updated: 2025/01/20 13:16:21 by aalegria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "minilibx-linux/mlx.h"

#define ERROR_MESSAGE "Pleaseenter \n\t\"./fractol mandelbrot\" or
		\n\t\"./fractol julia <value_1> <value_2>\"\n"

#define WIDTH	800
#define HEIGTH	800

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
}			t_fractal;



int	ft_strncmp(char *s1, char *s2, int n);
void	putstr_fd(char *s, int fd);

void	fractal_init(tfractal *fractal);

#endif
