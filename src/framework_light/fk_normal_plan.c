/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_normal_plan.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 17:08:36 by mbarbari          #+#    #+#             */
/*   Updated: 2016/03/21 10:57:07 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_light/fk_normal_plan.h"
#include "framework_math/fk_math.h"

t_vector3		normal_plan(t_ray ray, t_vector3 inter, t_plan *obj)
{
	(void)ray, (void)inter, (void)obj;
	return (obj->dir);
}
