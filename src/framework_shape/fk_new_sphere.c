/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_new_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare </var/spool/mail/barbare>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 09:42:04 by barbare           #+#    #+#             */
/*   Updated: 2016/02/17 10:16:23 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "framework_shape/fk_sphere.h"
#include "framework_shape/fk_type.h"

void		new_sphere(t_value val, t_object *data)
{
		ft_memcpy(data, &(t_sphere){
			SPHERE,
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
			json_get(val.data.obj, "radius").data.number
		}, sizeof(t_sphere));
	}
