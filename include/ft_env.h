/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/01 16:09:24 by mbarbari          #+#    #+#             */
/*   Updated: 2016/03/26 16:48:17 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENV_H
# define FT_ENV_H

# include "framework_math/fk_vector.h"
# include "framework_collision/fk_intersect.h"
# include "framework_light/fk_normal.h"

typedef struct		s_env t_env;
typedef struct		s_resolution
{
	int				height;
	int				width;
}					t_resolution;

typedef struct		s_img
{
	void			*ptr;
	char			*data;
	int				bpp;
	int				sizeline;
	int				endianness;
}					t_img;

struct				s_env
{
	void			*mlx;
	void			*win;
	t_img			img;
	t_resolution	resolution;
	int				fov;
	int				nb_thread;
	char			*file;
	int				xy[2];
	float			invh;
	float			invw;
	float			ratio;
	float			angle;
	t_object		arr[16];
	t_vertex3		pos_absolute_camera;
	t_fctinter		fctinter[DEFAULT];
	t_fctnormal		fctnormal[DEFAULT];
};

void		ft_setup_inter(t_fctinter inter[DEFAULT]);
void		ft_setup_normal(t_fctnormal normal[DEFAULT]);
#endif
