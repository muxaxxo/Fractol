/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalegria <aalegria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:38:19 by aalegria          #+#    #+#             */
/*   Updated: 2025/04/03 14:05:26 by aalegria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	set_res(char *value, t_res low_res, t_res high_res, t_args *args)
{
	if (!value)
		return (1);
	if (!ft_strncmp(value, "high", -1))
	{
		args->max_i = high_res.y;
		args->min_i = high_res.x;
	}
	else if (!ft_strncmp(value, "low", -1))
	{
		args->max_i = low_res.y;
		args->min_i = low_res.x;
	}
	else
		return ((free(value), 1));
	free(value);
	return (0);
}

static int	parse_mandelbrot(t_render_data *args)
{
	char	*res;
	int		status;

	args->args.max_i = 150;
	args->args.min_i = 5;
	status = ft_set_key(args->argv, "-res", &res, pntr);
	if (status == 1)
		if (set_res(res, (t_res){5, 50}, (t_res){5, 300}, &args->args))
			return (1);
	if (args->argc > 2 + (status == 1))
		return (1);
	args->args.zoom_mov_x = .0625;
	args->args.zoom_mov_y = .0625;
	return (0);
}

static int	parse_julia(t_render_data *args)
{
	t_julia	*julia;
	char	*res;
	int		status;
	size_t	i;

	args->args.max_i = 150;
	julia = &args->julia;
	res = 0;
	i = 0;
	status = ft_set_key(args->argv, "-res", &res, pntr);
	if (status == 1)
	{
		if (set_res(res, (t_res){0, 50}, (t_res){0, 300}, &args->args))
			return (1);
		i++;
	}
	construct(julia);
	if (ft_set_key(args->argv, "-cx", &julia->cx, f64) == 1)
		i++;
	if (ft_set_key(args->argv, "-cy", &julia->cy, f64) == 1)
		i++;
	args->args.zoom_mov_x = 0.1;
	args->args.zoom_mov_y = 0.1;
	return ((size_t)args->argc - 2 != i);
}

int	parse_args(t_render_data *args)
{
	int	tmp;

	if (args->argc < 2)
		return (1);
	tmp = !ft_strncmp(args->argv[1], "mandelbrot", 40);
	tmp += !ft_strncmp(args->argv[1], "julia", 40) * 2;
	if (!tmp)
		return (1);
	if (tmp == 1)
		return (parse_mandelbrot(args));
	if (tmp == 2)
		return (parse_julia(args));
	return (1);
}
