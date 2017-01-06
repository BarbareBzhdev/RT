/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_newelement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 15:19:03 by root              #+#    #+#             */
/*   Updated: 2016/03/31 12:37:18 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/parser.h"
#include "framework_shape/fk_type.h"
#include "framework_shape/fk_ray.h"
#include "framework_collision/fk_intersect.h"
#include "framework_math/fk_vector.h"
#include "framework_shape/fk_objects.h"
#include "framework_shape/fk_sphere.h"

t_material		new_material(t_value val)
{
	t_material	mat;

	mat = (t_material){
			color_new(json_get(val.data.obj, "color1.red").data.number,
					json_get(val.data.obj, "color1.green").data.number,
					json_get(val.data.obj, "color1.blue").data.number),
			color_new(json_get(val.data.obj, "color2.red").data.number,
					json_get(val.data.obj, "color2.green").data.number,
					json_get(val.data.obj, "color2.blue").data.number),
			color_new(json_get(val.data.obj, "color3.red").data.number,
					json_get(val.data.obj, "color3.green").data.number,
					json_get(val.data.obj, "color3.blue").data.number),
			json_get(val.data.obj, "texture").data.s,
			json_get(val.data.obj, "datatexture.v0").data.number,
			json_get(val.data.obj, "datatexture.v1").data.number,
			json_get(val.data.obj, "datatexture.v2").data.number,
			};
	return (mat);
}

t_vertex3		new_position(t_value val)
{
	t_vertex3	pos;

	pos = (t_vertex3){
			.x = json_get(val.data.obj, "pos.x").data.number,
			.y = json_get(val.data.obj, "pos.y").data.number,
			.z = json_get(val.data.obj, "pos.z").data.number
		};
	return (pos);
}

t_vector3		new_direction(t_value val)
{
	t_vector3		res;

	res = (t_vector3) {
			.x = json_get(val.data.obj, "dir.x").data.number,
			.y = json_get(val.data.obj, "dir.y").data.number,
			.z = json_get(val.data.obj, "dir.z").data.number
	};
	return (res);
}
