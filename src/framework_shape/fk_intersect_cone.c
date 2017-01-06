/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_intersect_cone.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 14:21:51 by yderosie          #+#    #+#             */
/*   Updated: 2016/01/27 14:21:54 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_shape/fk_cone.h"
#include "framework_math/fk_math.h"

float			compute_len(float a, float b, float c)
{
	float		t1;
	float		t2;
	float		det;

	det = pow(b, 2) - (4 * a * c);
	t1 = (-b + sqrt(det)) / (2 * a);
	t2 = (-b - sqrt(det)) / (2 * a);
	if (det < 0)
		return (-1);
	else if (det == 0)
		return (t1);
	else if (t1 > t2)
		return (t2);
	else if (t1 < t2)
		return (t1);
	return (-1);
}

t_bool			intersect_cone(t_ray ray, t_cone *obj, float *t)
{
	float		a;
	float		b;
	float		c;
	float		tmp;
	t_vector3	ec;

	ec = vector_substract(ray.pos, obj->pos);
	tmp = (1 + obj->radius * obj->radius);
	a = vector_dotproduct(ray.dir, ray.dir);
	a = a - (tmp * SQUARE(vector_dotproduct(ray.dir, obj->dir)));
	b = vector_dotproduct(ray.dir, obj->dir) * vector_dotproduct(ec, obj->dir);
	b = 2 * (vector_dotproduct(ray.dir, ec) - b * tmp);
	c = vector_dotproduct(ec, ec);
	c -= tmp * SQUARE(vector_dotproduct(ec, obj->dir));
	if ((*t = compute_len(a, b, c)) > 0.)
	{
		ec = vector_substract(create_intersect(ray, *t), obj->pos);
		if (obj->height == 0 || obj->dir.x > 0)
			return (TRUE);
		else if (obj->height > 0. && vector_dotproduct(obj->dir, ec) > 0.)
			if ((obj->height / cos(atan(obj->radius)) > vector_magnitude(ec)))
				return (TRUE);
	}
	return (FALSE);
}
