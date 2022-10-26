/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:17:07 by tda-silv          #+#    #+#             */
/*   Updated: 2022/10/26 13:38:23 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	rotate_all(float L, float H, float SQUARE_X, void *mlx, void *mlx_win, t_data_mlximg *img)
{
	int i = 0;
	int j = 0;
	float tabX = 6;
	float tabY = 6;

	while (i < tabX)
	{
		while (j < tabY)
		{
			if (i + 1 < tabX)
				line_put(rotate_pixel_x(L / 2,	H / 2, 	(L /2 - ((tabX / 2) * SQUARE_X) + (i * SQUARE_X)), 		(H /2 - ((tabY / 2) * SQUARE_X) + (j * SQUARE_X))) + (SQUARE_X / 2),
						 rotate_pixel_y(L / 2,	H / 2, 	(L /2 - ((tabX / 2) * SQUARE_X) + (i * SQUARE_X)), 		(H /2 - ((tabY / 2) * SQUARE_X) + (j * SQUARE_X))),
						 rotate_pixel_x(L / 2,	H / 2, 	L /2 - ((tabX / 2) * SQUARE_X) + ((i + 1) * SQUARE_X), 	H /2 - ((tabY / 2) * SQUARE_X) + (j * SQUARE_X)) + (SQUARE_X / 2),
						 rotate_pixel_y(L / 2,	H / 2, 	L /2 - ((tabX / 2) * SQUARE_X) + ((i + 1) * SQUARE_X), 	H /2 - ((tabY / 2) * SQUARE_X) + (j * SQUARE_X)),
						 mlx, mlx_win, img);
			if (j + 1 < tabY)
				line_put(rotate_pixel_x(L / 2, H / 2, 	(L /2 - ((tabX / 2) * SQUARE_X) + (i * SQUARE_X)), 		(H /2 - ((tabY / 2) * SQUARE_X) + (j * SQUARE_X))) + (SQUARE_X / 2),
						 rotate_pixel_y(L / 2, H / 2, 	(L /2 - ((tabX / 2) * SQUARE_X) + (i * SQUARE_X)), 		(H /2 - ((tabY / 2) * SQUARE_X) + (j * SQUARE_X))),
						 rotate_pixel_x(L / 2, H / 2, 	(L /2 - ((tabX / 2) * SQUARE_X) + (i * SQUARE_X)), 		H /2 - ((tabY / 2) * SQUARE_X) + ((j + 1) * SQUARE_X)) + (SQUARE_X / 2),
						 rotate_pixel_y(L / 2, H / 2, 	(L /2 - ((tabX / 2) * SQUARE_X) + (i * SQUARE_X)), 		H /2 - ((tabY / 2) * SQUARE_X) + ((j + 1) * SQUARE_X)),
						 mlx, mlx_win, img);
			j++;
		}
		j = 0;
		i++;
	}
}
