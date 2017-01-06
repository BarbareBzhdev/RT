/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/01 16:09:24 by mbarbari          #+#    #+#             */
/*   Updated: 2016/04/05 14:55:32 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENV_H
# define FT_ENV_H

# include <sys/stat.h>
# include "framework_math/fk_vector.h"
# include "framework_collision/fk_intersect.h"
# include "framework_light/fk_normal.h"

# define WIDTH 1920
# define HEIGHT 1080
# define L_WIDTH 560
# define L_HEIGHT 215
# define NB_OBJ 25

typedef struct s_env	t_env;
typedef struct		s_resolution
{
	int				height;
	int				width;
}					t_resolution;

typedef struct		s_img
{
	void			*img;
	void			*ptr;
	char			*data;
	int				bpp;
	int				sizeline;
	int				endianness;
}					t_img;

typedef struct		s_rout
{
	float			x;
	float			y;
	int				nthread;
	t_env			*env;
	t_color3		color;
}					t_rout;

struct				s_env
{
	void			*mlx;
	void			*win;
	t_img			img;
	t_img			loading;
	int				mid_w;
	int				mid_h;
	t_resolution	resolution;
	int				fov;
	int				nb_thread;
	int				process;
	int				depth;
	int				sampling;
	int				p_alias;
	int				max_alias;
	int				cartoon;
	int				sepia;
	t_color3		*matrice;
	char			*file;
	float			xy[2];
	float			invh;
	float			invw;
	float			ratio;
	float			anglex;
	float			angley;
	t_object		arr[NB_OBJ];
	pthread_t		th[16];
	int				load;
	float			angle;
	t_vertex3		pos_absolute_camera;
	t_fctinter		fctinter[DEFAULT];
	t_fctnormal		fctnormal[DEFAULT];
	time_t			oldtime;
};

void				ft_setup_inter(t_fctinter inter[DEFAULT]);
void				ft_setup_normal(t_fctnormal normal[DEFAULT]);

#endif
