/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalegria <aalegria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:37:32 by aalegria          #+#    #+#             */
/*   Updated: 2025/01/21 16:23:01 by aalegria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;

	z.x = 0.0;
	z.y = 0.0;
	c.x = map(x, -2, +2, 0, WIDTH);
	c.y = map(y, +2, -2, 0, HEIGTH);

	while (??????????)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			my_pixel_put();
			return ;
		}
	}
}

void	fractal_render(t__fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (HEIGTH > y++)
	{
		x = -1;
		while (WIDTH > x++)
		{
			handle_pixel (x, y, fractal);
		}
	}

}
