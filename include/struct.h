/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:11:18 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/15 18:09:41 by tda-silv         ###   ########.fr       */
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

typedef struct	s_setup_tab_vars
{
	int		fd;
	int		comma;
	int		x_tab;
	int		y_tab;
	int		x_str;
	char	*str;
}	t_setup_tab_vars;

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
}	t_data_util;

#endif
