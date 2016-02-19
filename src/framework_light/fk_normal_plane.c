/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_normal_plan.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 17:08:36 by mbarbari          #+#    #+#             */
/*   Updated: 2016/02/17 10:06:32 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_light/fk_normal_plane.h"
#include "framework_math/fk_math.h"

t_vector3		normal_plane(t_ray ray, t_vector3 inter, t_plane *obj)
{
	(void)ray, (void)inter, (void)obj;
	return (vector_unit(obj->normal));
}
