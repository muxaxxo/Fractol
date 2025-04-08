/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalegria <aalegria@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:02:40 by aalegria          #+#    #+#             */
/*   Updated: 2025/04/03 14:02:43 by aalegria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	free_all(t_render_data *d)
{
	free_img(d);
	free_win(d);
	free_mlx(d);
}

int	free_img(t_render_data *d)
{
	if (!d->img.img || !d->mlx)
		return (1);
	mlx_destroy_image(d->mlx, d->img.img);
	d->img.img = 0;
	return (1);
}

int	free_mlx(t_render_data *d)
{
	if (!d->mlx)
		return (1);
	mlx_destroy_display(d->mlx);
	free(d->mlx);
	d->mlx = 0;
	return (1);
}

int	free_win(t_render_data *d)
{
	if (!d->win || !d->mlx)
		return (1);
	mlx_destroy_window(d->mlx, d->win);
	d->win = 0;
	return (1);
}
