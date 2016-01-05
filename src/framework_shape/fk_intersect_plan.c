/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_plan.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 20:35:03 by mbarbari          #+#    #+#             */
/*   Updated: 2015/12/22 13:50:44 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_shape/fk_plan.h"
#include "framework_math/fk_math.h"

#define EPSILON 0.00001

//t_bool			intersect_plan(t_ray ray, t_plan *plan, float *t)
//{
//	float	m;
//	t_vector3	pos;
//
//	m = vector_dotproduct(ray.dir, plan->normal);
//	dprintf(2, "on rentre au debut de l'intersection plan : %f\n", m);
//	if (m < EPSILON)
//		return (FALSE);
//	pos = vector_substract(ray.pos, plan->pos);
//	*t = vector_dotproduct(plan->normal, pos);
//	if ((*t = (float)(-*t / m)) > 0.)
//		return (TRUE);
//	dprintf(2, "test suite au calcul de intersect_plan : %f", *t);
//	return (FALSE);
//}

t_bool			intersect_plan(t_ray ray, t_plan *plan, float *t)
{
	float	m;
	float	d;
	t_vector3	pos;

	pos = vector_substract(plan->pos, ray.pos);
	m = vector_dotproduct(plan->normal, pos);
	if ((d = vector_dotproduct(plan->normal, ray.dir)) == 0.00000)
		return (FALSE);
	*t = m / d;
	if (*t < 0.)
		return (FALSE);
	return (TRUE);
}

