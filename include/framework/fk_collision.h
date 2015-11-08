/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_collision.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 12:45:47 by mbarbari          #+#    #+#             */
/*   Updated: 2015/11/03 19:56:45 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FK_COLLISION_H
# define FK_COLLISION_H

#include "libft.h"
#include "framework/fk_rgb.h"
#include "framework/fk_vectoriel.h"
#include "framework/fk_vertexiel.h"
#include "framework/fk_ray.h"

typedef struct		s_intersect t_intersect;

struct				s_intersect
{
	t_vertex3		pos;
	long			radius;
};

#include "ft_env.h"
/*
** ****************************************************************************
** fk_collision.c
** ****************************************************************************
*/
t_intersect	nearest_vertex(t_ray ray, t_intersect new, t_intersect old);
t_rgb		ft_trace_ray(t_env env, t_ray ray);
void		ft_render(t_env env);

/*
** ****************************************************************************
** fk_ray.c
** ****************************************************************************
*/
t_ray		ray_new(t_vertex3 v, t_vector3 dir);
t_ray		ray_modif_pos(t_ray ray, t_vertex3 v);
t_ray		ray_modif_dir(t_ray ray, t_vector3 v);

#endif
