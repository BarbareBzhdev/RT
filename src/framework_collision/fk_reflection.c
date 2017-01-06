/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_reflection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 10:58:45 by root              #+#    #+#             */
/*   Updated: 2016/03/25 14:08:58 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_shape/fk_objects.h"
#include "framework_shape/fk_listobj.h"
#include "framework_math/fk_vector.h"

t_ray	create_reflection(t_ray ray, t_intersect inter)
{
	t_ray		newray;
	t_vector3	norm;

	norm = inter.v_normal;
	newray.dir = vector_substract(ray.dir,
			vector_mul(norm, 2.0f * vector_dotproduct(ray.dir, norm)));
	newray.dir = vector_unit(newray.dir);
	newray.pos = vector_substract(inter.pos, vector_mul(inter.v_normal, 1e-4f));
	return (newray);
}
