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

void		normal_plan(t_intersect *inter, t_plan *obj)
{
	(void)obj;
	inter->v_normal = vector_unit(vector_mul(obj->dir, -1));
}
