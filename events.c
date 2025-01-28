/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalegria <aalegria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:02:47 by aalegria          #+#    #+#             */
/*   Updated: 2025/01/28 16:51:04 by aalegria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_handler(fractal);
	else if (keysym == XK_Right)
		fractal->shift_x += 0.5;
	else if (keysym == XK_Left)
		fractal->shift_x += 0.5;
	else if (keysym == XK_Up)
	
	else if (keysym == XK_Down)
	
	else if (keysym == XK_plus)
		fractal->iterations_definition +=10;
	else if (keysym == XK_minus)
		fractal->iterations_definition -=10;
	fractal_render(fractal)
	return (0);
}
