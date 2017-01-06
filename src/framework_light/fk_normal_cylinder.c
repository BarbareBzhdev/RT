/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_normal_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 20:19:03 by mbarbari          #+#    #+#             */
/*   Updated: 2016/03/31 12:21:36 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_light/fk_normal_cylinder.h"
#include "framework_math/fk_math.h"

void		normal_cylinder(t_intersect *inter, t_cylinder *obj)
{
	float		radius;
	t_vector3	ctop;
	t_vector3	qtop;

	ctop = vector_substract(inter->pos, obj->pos);
	radius = vector_dotproduct(ctop, obj->dir);
	qtop = vector_substract(ctop, vector_mul(obj->dir, radius));
	inter->v_normal = vector_unit(vector_div(qtop, -obj->radius));
}
