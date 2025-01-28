/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalegria <aalegria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:38:19 by aalegria          #+#    #+#             */
/*   Updated: 2025/01/28 16:43:37 by aalegria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx-linux/mlx.h"

static void	malloc_error(void)
{
	perror("Problems with malloc");
	exit(EXIT_FAILURE);
}

void	data_init(t_fractal *fractal)
{
	fractal->escape_value = 4;
	fractal->iterations_definition = 42;
}

void	tevents_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window, KeyPress, KeyPressMask, key_handle, fractal);
	/*	mlx_hook(fractal->mlx_window, ButtonPress, ButtonPressMask, mouse_handle,
		fractal);
	mlx_hook(fractal->mlx_window, DestroyNotify, StructureNotifyMask,
		close_handle, fractal);
		*/
}

void	fractal_init(tfractal *fractal)
{
	fractal->mlx_conection = mlx_init();
	if (fractal->mlx_conection == NULL)
		malloc_error();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection, WIDTH, HEIGHT,
			fractal->name);
	if (fractal->mlx_window == NULL)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_conection);
		malloc_error();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection,
			WIDTH, HEIGHT);
	if (fractal->img.img_ptr == NULL)
	{
		mlx_destroy_display(fractal->mlx_connection, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_conection);
	}
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
	data_init(fractal);
}
