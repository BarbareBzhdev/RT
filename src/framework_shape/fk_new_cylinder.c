/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_new_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare </var/spool/mail/barbare>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 09:49:28 by barbare           #+#    #+#             */
/*   Updated: 2016/03/23 14:12:00 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "framework_shape/fk_cylinder.h"
#include "framework_math/fk_vector.h"

void		new_cylinder(t_value val, t_object *data)
{
	ft_memcpy(data, &(t_cylinder){
		CYLINDER,
		material_new(color_new(json_get(val.data.obj, "color1.red").data.number,
					json_get(val.data.obj, "color1.green").data.number,
					json_get(val.data.obj, "color1.blue").data.number),
		color_new(json_get(val.data.obj, "color2.red").data.number,
					json_get(val.data.obj, "color2.green").data.number,
					json_get(val.data.obj, "color2.blue").data.number),
		color_new(json_get(val.data.obj, "color3.red").data.number,
					json_get(val.data.obj, "color3.green").data.number,
					json_get(val.data.obj, "color3.blue").data.number),
		json_get(val.data.obj, "texture").data.s),
		json_get(val.data.obj, "reflection_index").data.number,
		json_get(val.data.obj, "refraction_index").data.number,
		json_get(val.data.obj, "ambient").data.number,
		json_get(val.data.obj, "diffuse").data.number,
		json_get(val.data.obj, "specular").data.number,
		json_get(val.data.obj, "light").data.boolean,
		vector_new(json_get(val.data.obj, "pos.x").data.number,
					json_get(val.data.obj, "pos.y").data.number,
					json_get(val.data.obj, "pos.z").data.number),
		vector_unit(vector_new(json_get(val.data.obj, "dir.x").data.number,
					json_get(val.data.obj, "dir.y").data.number,
					json_get(val.data.obj, "dir.z").data.number)),
		json_get(val.data.obj, "radius").data.number
	}, sizeof(t_cylinder));
}
