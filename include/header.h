/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:29:18 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/18 12:16:58 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <math.h>
# include <mlx.h>
# include <libft.h>
# include "./struct.h"

int		check_error(int argc, char **argv);
int		key_hook(int keycode, t_data_util *d);
void	my_mlx_pixel_put(t_data_mlximg *data, int x, int y, int color);
void	line_put(t_data_util *d, t_rotate_all_vars *v, t_line_put_vars *vl);
float	rotate_pixel_x(t_data_util *d, t_rotate_all_vars *v);
float	rotate_pixel_y(t_data_util *d, t_rotate_all_vars *v);
void	rotate_all(t_data_util *d);
void	rotate_all_rev(t_data_util *d);
int		width_tab(char *str);
void	setup_struct(t_data_util *d);
int		setup_tab(t_data_util *d, const char *pathname);
int		setup_hw_tab(t_data_util *d, const char *pathname);
t_li	*nb_nb_point(t_data_util *d);
void	put_background(t_data_util *d);
int		calloc_all(t_data_util *d);
void	free_all(t_data_util *d);
void	square_size(t_data_util *d);
void	octant_one(t_data_util *d, t_line_put_vars *vl);
void	octant_two(t_data_util *d, t_line_put_vars *vl);
void	octant_three(t_data_util *d, t_line_put_vars *vl);
void	octant_four(t_data_util *d, t_line_put_vars *vl);
void	octant_five(t_data_util *d, t_line_put_vars *vl);
void	octant_six(t_data_util *d, t_line_put_vars *vl);
void	octant_seven(t_data_util *d, t_line_put_vars *vl);
void	octant_eight(t_data_util *d, t_line_put_vars *vl);
void	dy_zero_dx_sup(t_data_util *d, t_line_put_vars *vl);
void	dy_zero_dx_inf(t_data_util *d, t_line_put_vars *vl);
void	dy_sup_dx_zero(t_data_util *d, t_line_put_vars *vl);
void	dy_inf_dx_zero(t_data_util *d, t_line_put_vars *vl);
void	ssv(t_data_util *d, t_rotate_all_vars *v, t_line_put_vars *vl);
void	ssvptt(t_line_put_vars *vl);
void	first_setup_line_put_vars_xy(t_line_put_vars *v, int x_two, int y_two);
void	first_setup_line_put_vars_ij(t_line_put_vars *v, int i_two, int j_two);
void	rotate_all_rev(t_data_util *d);
void	nb_nb_six(int list_size, t_li *cpy_four);

#endif
