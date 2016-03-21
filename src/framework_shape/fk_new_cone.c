/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_new_cone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare </var/spool/mail/barbare>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 09:51:05 by barbare           #+#    #+#             */
/*   Updated: 2016/02/17 10:17:34 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "framework_shape/fk_cone.h"

void		new_cone(t_value val, t_object *data)
{
	ft_memcpy(data, &(t_cone){
		CONE,
		color_new(json_get(val.data.obj, "color.red").data.number,
					json_get(val.data.obj, "color.green").data.number,
					json_get(val.data.obj, "color.blue").data.number),
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
		json_get(val.data.obj, "radius").data.number,
		0
	}, sizeof(t_cone));
}
