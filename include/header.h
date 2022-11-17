/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:29:18 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/17 10:34:18 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

#include <math.h>
#include <mlx.h>
#include <libft.h>
#include "./struct.h"

void	my_mlx_pixel_put(t_data_mlximg *data, int x, int y, int color);
void	line_put(t_data_util *d, t_rotate_all_vars *v, t_line_put_vars *vl);
float	rotate_pixel_x(t_data_util *d, t_rotate_all_vars *v);
float	rotate_pixel_y(t_data_util *d, t_rotate_all_vars *v);
void	rotate_all(t_data_util *d);
int		width_tab(char *str);
void	setup_struct(t_data_util *d);
int		setup_tab(t_data_util *d, const char *pathname);
int		setup_hw_tab(t_data_util *d, const char *pathname);
t_li    *nb_nb_point(t_data_util *d);
void	put_background(t_data_util *d);
int     calloc_all(t_data_util *d);
void	free_all(t_data_util *d);
void	square_size(t_data_util *d);
void	octant_one(t_data_util *d, t_line_put_vars *v);
void	first_setup_line_put_vars_xy(t_line_put_vars *v, int x_two, int y_two);
void	first_setup_line_put_vars_ij(t_line_put_vars *v, int i_two, int j_two);

#endif
