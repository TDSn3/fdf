/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:29:18 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/03 10:08:00 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

#include <math.h>
#include <mlx.h>
#include <libft.h>
#include "./struct.h"

void	my_mlx_pixel_put(t_data_mlximg *data, int x, int y, int color);
void	line_put(int x1, int y1, int x2, int y2, void *mlx, void *mlx_win, t_data_mlximg *img, t_data_util *d, int i, int j, int i2, int j2);
float	rotate_pixel_x(int Ox, int Oy, int Mx, int My, t_data_util *d, int i, int j);
float	rotate_pixel_y(int Ox, int Oy, int Mx, int My, t_data_util *d, int i, int j);
void	rotate_all(t_data_util *d, void *mlx, void *mlx_win, t_data_mlximg *img);
int		width_tab(char *str);
void	setup_struct(t_data_util *d);
int		setup_tab(t_data_util *d, const char *pathname);
int		setup_hw_tab(t_data_util *d, const char *pathname);

#endif
