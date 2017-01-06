/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_new_cone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare <mbarbari@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 09:51:05 by barbare           #+#    #+#             */
/*   Updated: 2016/03/31 12:26:17 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "framework_shape/fk_cone.h"
#include "framework_shape/fk_newelement.h"

void		new_cone(t_value val, t_object *data)
{
	ft_memcpy(data, &(t_cone){
		CONE,
		new_material(val),
		json_get(val.data.obj, "reflection_index").data.number,
		json_get(val.data.obj, "refraction_index").data.number,
		json_get(val.data.obj, "ambient").data.number,
		json_get(val.data.obj, "diffuse").data.number,
		json_get(val.data.obj, "specular").data.number,
		json_get(val.data.obj, "light").data.boolean,
		new_position(val),
		new_direction(val),
		json_get(val.data.obj, "radius").data.number,
		0
	}, sizeof(t_cone));
}
