/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalegria <aalegria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:37:32 by aalegria          #+#    #+#             */
/*   Updated: 2025/04/03 15:25:32 by aalegria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	draw_julia(t_render_data *args)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	while (x < args->img.res.x)
	{
		y = 0;
		while (y < args->img.res.y)
		{
			i = y * args->img.res.x + x;
			((int *)args->img.addr)[i] = get_julia(x, y, args, args->julia);
			y++;
		}
		x++;
	}
	return (0);
}

static int	draw_mandelbrot(t_render_data *args)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	while (x < args->img.res.x)
	{
		y = 0;
		while (y < args->img.res.y)
		{
			i = y * args->img.res.x + x;
			((int *)args->img.addr)[i] = get_mandelbrot(x, y,
					args->img.res, args->args);
			y++;
		}
		x++;
	}
	return (0);
}

static int	route_drawing(t_render_data *args)
{
	if (!ft_strncmp(args->argv[1], "mandelbrot", 40))
		return (draw_mandelbrot(args));
	if (!ft_strncmp(args->argv[1], "julia", 40))
		return (draw_julia(args));
	return (1);
}

int	draw(t_render_data *args)
{
	if (route_drawing(args))
	{
		mlx_loop_end(args->mlx);
		return (1);
	}
	return (0);
}
