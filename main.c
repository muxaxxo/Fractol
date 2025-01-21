/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalegria <aalegria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:13:19 by aalegria          #+#    #+#             */
/*   Updated: 2025/01/21 13:36:04 by aalegria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, int **argv)
{
	if (argc == 2 && !ft_strncmp(argv [1], "mandelbrot, 10")
		|| argc == 4 && !ft_strncmp(argv [1], "julia, 5"))
	{
		fractal.name = arv[1];
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		putrstr_fd(ERROR_MESSAG, STDERR_FILEN0); //NO SE SI ESTA LINEA ESTA BIEN, HAY QUE REVISAR
		exit(EXIT_FAILURE)
	}
}
