/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_intersect_cylinder.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 16:28:56 by mbarbari          #+#    #+#             */
/*   Updated: 2016/02/01 14:53:11 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_shape/fk_cylinder.h"
#include "framework_math/fk_math.h"

t_bool			intersect_cylinder(t_ray ray, t_cylinder *obj, float *t)
{
	float		a;
	float		b;
	float		c;
	float		d;
	t_vector3	etoc;

	etoc = vector_substract(ray.pos, obj->pos);
	a = vector_dotproduct(ray.dir, ray.dir) -
		SQUARE(vector_dotproduct(ray.dir, obj->dir));
	b = (vector_dotproduct(ray.dir, etoc) - vector_dotproduct(ray.dir, obj->dir)
		* vector_dotproduct(etoc, obj->dir)) * 2;
	c = vector_dotproduct(etoc, etoc) -
		SQUARE(vector_dotproduct(etoc, obj->dir)) - (obj->radius * obj->radius);
	d = b * b - 4 * a * c;
	if (d > 0.)
	{
		*t = FT_MIN(((-b - sqrt(d)) / (2 * a)), ((-b - sqrt(d)) / (2 * a)));
		if (*t >= 0.)
			return (TRUE);
	}
	return (FALSE);
}
