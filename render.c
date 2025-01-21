/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalegria <aalegria@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:37:32 by aalegria          #+#    #+#             */
/*   Updated: 2025/01/21 13:37:36 by aalegria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
