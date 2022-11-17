/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:11:18 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/17 09:06:31 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct	s_data_mlximg
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data_mlximg;

typedef struct	s_rotate_all_vars
{
	int i;
	int j;
	float w;
	float h;
	int	win_h_div;
	int	win_w_div;
	int	x_o;
	int	y_o;
	int	x_next;
	int	y_next;
}	t_rotate_all_vars;

typedef struct	s_setup_tab_vars
{
	int		fd;
	int		comma;
	int		x_tab;
	int		y_tab;
	int		x_str;
	char	*str;
}	t_setup_tab_vars;

typedef struct	s_line_put_vars
{
	int		i_one;
	int		j_one;
	int		i_two;
	int		j_two;
	int		x_one;
	int		y_one;
	int		x_two;
	int		y_two;
	int		dx;
	int		dy;
	int		e;
	int		c_one_r;
	int		c_one_v;
	int		c_one_b;
	int		c_two_r;
	int		c_two_v;
	int		c_two_b;
	int		color;
	float	dif_x_r;
	float	dif_x_v;
	float	dif_x_b;
	float	dif_y_r;
	float	dif_y_v;
	float	dif_y_b;
	float	dif_xi_r;
	float	dif_xi_v;
	float	dif_xi_b;
	float	dif_yi_r;
	float	dif_yi_v;
	float	dif_yi_b;
}	t_line_put_vars;

typedef struct	s_data_util
{
	void			*mlx;
	void			*win;
	t_data_mlximg	*img;
	int				win_widht;
	int				win_height;
	int 			square_size;
	int				tab_widht;
	int				tab_height;
	int				**tab_hw;
	int				**tab_color;
	int				**pos_x;
	int				**pos_y;
	t_li			*li_color;
	int				h_point;
	int				x_shift;
	int				y_shift;
	int				rotation;
	float			projection;
}	t_data_util;

#endif
