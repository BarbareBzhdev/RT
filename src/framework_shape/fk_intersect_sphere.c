/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 21:18:55 by mbarbari          #+#    #+#             */
/*   Updated: 2016/04/04 08:39:01 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_shape/fk_sphere.h"
#include "framework_math/fk_math.h"

t_bool			intersect_sphere(t_ray ray, t_sphere *obj, float *t)
{
	t_vector3		etoc;
	float			radius;
	float			t0;
	float			t1;
	float			vector_radius;

	if (obj->radius == 0.0f)
		return (FALSE);
	etoc = vector_substract(obj->pos, ray.pos);
	if ((vector_radius = vector_dotproduct(etoc, ray.dir)) < 0.)
		return (FALSE);
	*t = vector_dotproduct(etoc, etoc) - SQUARE(vector_radius);
	if (*t > (radius = SQUARE(obj->radius)))
		return (FALSE);
	*t = sqrt(radius - *t);
	t0 = (vector_radius - *t);
	t1 = (vector_radius + *t);
	*t = FT_MIN(t0, t1);
	return (TRUE);
}
