/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_new_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare </var/spool/mail/barbare>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 09:47:48 by barbare           #+#    #+#             */
/*   Updated: 2016/03/21 10:55:13 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "framework_shape/fk_plan.h"

void		new_plane(t_value val, t_object *data)
{
	ft_memcpy(data, &(t_plan){
		PLANE,
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
					json_get(val.data.obj, "dir.z").data.number))
	}, sizeof(t_plan));
}
