/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_new_triangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 00:26:55 by yderosie          #+#    #+#             */
/*   Updated: 2016/03/31 12:38:03 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "framework_shape/fk_triangle.h"
#include "framework_math/fk_vector.h"
#include "framework_shape/fk_newelement.h"

void		new_triangle(t_value val, t_object *data)
{
	ft_memcpy(data, &(t_triangle){
		TRIANGLE,
		new_material(val),
		json_get(val.data.obj, "reflection_index").data.number,
		json_get(val.data.obj, "refraction_index").data.number,
		json_get(val.data.obj, "ambient").data.number,
		json_get(val.data.obj, "diffuse").data.number,
		json_get(val.data.obj, "specular").data.number,
		json_get(val.data.obj, "light").data.boolean,
		new_position(val),
		new_direction(val),
		(t_vertex3){
			.x = json_get(val.data.obj, "pos2.x").data.number,
			.y = json_get(val.data.obj, "pos2.y").data.number,
			.z = json_get(val.data.obj, "pos2.z").data.number
		},
		(t_vertex3){
			.x = json_get(val.data.obj, "pos3.x").data.number,
			.y = json_get(val.data.obj, "pos3.y").data.number,
			.z = json_get(val.data.obj, "pos3.z").data.number
		}
	}, sizeof(t_triangle));
}
