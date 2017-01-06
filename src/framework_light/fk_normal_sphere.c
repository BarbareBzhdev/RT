/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_normal_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 18:18:56 by mbarbari          #+#    #+#             */
/*   Updated: 2016/01/23 16:32:26 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_light/fk_normal_sphere.h"
#include "framework_texture/fk_texture.h"
#include "framework_math/fk_math.h"

void		normal_sphere(t_intersect *inter, t_sphere *obj)
{
	inter->v_normal = vector_unit(vector_substract(obj->pos, inter->pos));
}
