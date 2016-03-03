/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_new_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare </var/spool/mail/barbare>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 09:49:28 by barbare           #+#    #+#             */
/*   Updated: 2016/02/17 10:16:52 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "framework_shape/fk_cylinder.h"

void		new_cylinder(t_value val, t_object *data)
{
	ft_memcpy(data, &(t_cylinder){
		CYLINDER,
		color_new(json_get(val.data.obj, "color.red").data.number, json_get(val.data.obj, "color.green").data.number, json_get(val.data.obj, "color.blue").data.number),
		json_get(val.data.obj, "reflection_index").data.number,
		json_get(val.data.obj, "diffuse").data.number,
		json_get(val.data.obj, "refraction").data.number,
		json_get(val.data.obj, "refraction_index").data.number,
		vector_new(json_get(val.data.obj, "pos.x").data.number, json_get(val.data.obj, "pos.y").data.number, json_get(val.data.obj, "pos.z").data.number),
		vector_unit(vector_new(json_get(val.data.obj, "normal.x").data.number, json_get(val.data.obj, "normal.y").data.number, json_get(val.data.obj, "normal.z").data.number)),
		json_get(val.data.obj, "radius").data.number
	}, sizeof(t_cylinder));
}
