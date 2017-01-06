/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_refraction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 07:25:26 by mbarbari          #+#    #+#             */
/*   Updated: 2016/04/04 08:50:21 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_shape/fk_objects.h"
#include "framework_shape/fk_listobj.h"
#include "framework_math/fk_vector.h"
#include "framework_math/fk_math.h"

extern int g_indice;

t_ray	create_refraction(t_ray ray, t_intersect inter)
{
	float		cosi;
	float		cosi2;
	t_ray		newray;

	cosi = vector_dotproduct(inter.v_normal, vector_mul(ray.dir, -1));
	cosi2 = sqrt(1 - SQUARE(inter.obj->refraction_index / g_indice) *
		(1 - SQUARE(cosi)));
	newray.dir = vector_mul(ray.dir, (inter.obj->refraction_index / g_indice));
	newray.dir = (cosi > 0) ? vector_sum(newray.dir, vector_mul(inter.v_normal,
				(inter.obj->refraction_index / g_indice) * cosi - cosi2)) :
		vector_sum(newray.dir, vector_mul(inter.v_normal,
				(inter.obj->refraction_index / g_indice) * cosi + cosi2));
	newray.pos = vector_sum(inter.pos, vector_mul(ray.dir, 1e-4f));
	newray.dir = vector_unit(newray.dir);
	g_indice = (g_indice != inter.obj->refraction_index)
		? 1.0 : inter.obj->refraction_index;
	return (newray);
}
