/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_normal_paraboloid.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 00:15:14 by yderosie          #+#    #+#             */
/*   Updated: 2016/03/31 00:15:15 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_light/fk_normal_paraboloid.h"
#include "framework_math/fk_math.h"

void		normal_paraboloid(t_intersect *inter, t_paraboloid *obj)
{
	inter->v_normal = vector_unit(vector_substract(obj->pos, inter->pos));
}
