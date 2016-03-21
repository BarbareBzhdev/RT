/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_collision.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 12:45:47 by mbarbari          #+#    #+#             */
/*   Updated: 2016/02/09 11:26:58 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FK_COLLISION_H
# define FK_COLLISION_H

# include "framework_math/fk_vector.h"
# include "framework_shape/fk_ray.h"

#include "ft_env.h"
/*
** ****************************************************************************
** fk_collision.c
** ****************************************************************************
*/
t_color3		ft_trace_ray(t_object *arr, t_ray ray, int depth, float *dist_out, t_env env);
void		ft_render(t_env env);

/*
** ****************************************************************************
** fk_ray.c
** ****************************************************************************
*/
t_ray				ray_new(t_vertex3 v, t_vector3 dir);
t_ray				ray_modif_pos(t_ray ray, t_vertex3 v);
t_ray				ray_modif_dir(t_ray ray, t_vector3 v);

#endif
