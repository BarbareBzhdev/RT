/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_plan.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 20:35:03 by mbarbari          #+#    #+#             */
/*   Updated: 2016/02/17 10:08:33 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_shape/fk_plane.h"
#include "framework_math/fk_math.h"

#define EPSILON 0.00001

t_bool			intersect_plane(t_ray ray, t_plane *plane, float *t)
{
	float	m;
	float	d;
	t_vector3	pos;

	*t = -(vector_dotproduct(plane->normal, vector_substract(ray.pos, plane->pos)) /
			vector_dotproduct(plane->normal, ray.dir));
	return (TRUE);
}

