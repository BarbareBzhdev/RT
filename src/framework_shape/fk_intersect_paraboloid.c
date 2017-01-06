/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_intersect_paraboloid.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 00:09:39 by yderosie          #+#    #+#             */
/*   Updated: 2016/03/31 00:09:40 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_shape/fk_paraboloid.h"
#include "framework_math/fk_math.h"

t_bool			intersect_paraboloid(t_ray ray, t_paraboloid *obj, float *t)
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
		* (vector_dotproduct(etoc, obj->dir) + 2 * obj->height)) * 2;
	c = vector_dotproduct(etoc, etoc) - vector_dotproduct(etoc, obj->dir)
		* (vector_dotproduct(etoc, obj->dir) + 4 * obj->height);
	d = b * b - 4 * a * c;
	if (d > 0.)
	{
		*t = FT_MIN(((-b - sqrt(d)) / (2 * a)), ((-b - sqrt(d)) / (2 * a)));
		if (*t >= 0.)
			return (TRUE);
	}
	return (FALSE);
}
