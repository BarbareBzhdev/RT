/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_normal_cone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 14:22:25 by yderosie          #+#    #+#             */
/*   Updated: 2016/03/31 12:21:54 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_light/fk_normal_cone.h"
#include "framework_math/fk_math.h"

void		normal_cone(t_intersect *inter, t_cone *obj)
{
	float		radius;
	t_vector3	ctop;
	t_vector3	qtop;

	ctop = vector_substract(inter->pos, obj->pos);
	radius = vector_dotproduct(ctop, obj->dir);
	qtop = vector_substract(ctop, vector_mul(obj->dir, radius));
	inter->v_normal = vector_unit(vector_div(qtop, -obj->radius));
}
