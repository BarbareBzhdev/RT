/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/01 16:09:24 by mbarbari          #+#    #+#             */
/*   Updated: 2015/11/03 21:03:48 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENV_H
# define FT_ENV_H

typedef struct		s_env t_env;
typedef struct		s_resolution
{
	int				height;
	int				width;
}					t_resolution;

# include "framework/fk_vectoriel.h"
# include "framework/fk_vertexiel.h"
# include "framework/fk_objects.h"
# include "framework/fk_collision.h"

typedef t_bool (*t_fct_inter)(t_ray ray, t_object *obj, t_intersect *inter);

struct				s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	t_resolution	resolution;
	int				fov;
	t_vertex3		pos_absolute_camera;
	t_vector3		dir_camera;
	t_fct_inter		fctinter[DEFAULT];
};
#endif
