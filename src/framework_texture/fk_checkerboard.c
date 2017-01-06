/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_checkerboard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 12:51:52 by root              #+#    #+#             */
/*   Updated: 2016/03/23 13:51:21 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_collision/fk_collision.h"
#include "framework_shape/fk_objects.h"
#include "framework_shape/fk_listobj.h"
#include "framework_light/fk_light.h"
#include "framework_math/fk_vector.h"
#include "framework_texture/fk_texture.h"
#include "framework_math/fk_math.h"

static int		check_pair(float point)
{
	int		x;
	float	len;

	len = 1;
	x = (int)(ABS((point + 0.001) / len)) % 2;
	if (point < 0)
		return (x == 0 ? 1 : 0);
	return (x % 2);
}

t_color3		fk_checkerboard(t_intersect inter)
{
	int			result[3];

	result[0] = check_pair((inter.pos.x));
	result[1] = check_pair((inter.pos.y));
	result[2] = check_pair((inter.pos.z));
	if (result[2] == 0)
	{
		if ((!result[0] && !result[1]) || (result[0] && result[1]))
			return (inter.obj->mat.color1);
		else
			return (inter.obj->mat.color2);
	}
	if ((!result[0] && !result[1]) || (result[0] && result[1]))
		return (inter.obj->mat.color2);
	return (inter.obj->mat.color1);
}
