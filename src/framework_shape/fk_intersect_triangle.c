/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_intersect_triangle.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 00:09:50 by yderosie          #+#    #+#             */
/*   Updated: 2016/03/31 00:09:51 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_shape/fk_triangle.h"
#include "framework_math/fk_math.h"

t_bool			intersect_triangle(t_ray ray, t_triangle *obj, float *out)
{
	t_tri	tri;

	tri.e1 = vector_substract(obj->pos2, obj->pos);
	tri.e2 = vector_substract(obj->pos3, obj->pos);
	tri.p = vector_product(ray.dir, tri.e2);
	tri.det = vector_dotproduct(tri.e1, tri.p);
	if (tri.det > -1e-4f && tri.det < 1e-4f)
		return (FALSE);
	tri.det = 1.f / tri.det;
	tri.t = vector_substract(ray.pos, obj->pos);
	tri.u = vector_dotproduct(tri.t, tri.p) * tri.det;
	if (tri.u < 0. || tri.u > 1.)
		return (FALSE);
	tri.q = vector_product(tri.t, tri.e1);
	tri.v = vector_dotproduct(ray.dir, tri.q) * tri.det;
	if (tri.v < 0. || (tri.u + tri.v) > 1.)
		return (FALSE);
	*out = vector_dotproduct(tri.e2, tri.q) * tri.det;
	if (*out > 1e-4f)
		return (TRUE);
	return (FALSE);
}
