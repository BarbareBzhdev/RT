/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_new_paraboloid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 00:27:04 by yderosie          #+#    #+#             */
/*   Updated: 2016/03/31 12:26:18 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "framework_shape/fk_paraboloid.h"
#include "framework_math/fk_vector.h"
#include "framework_shape/fk_newelement.h"

void		new_paraboloid(t_value val, t_object *data)
{
	ft_memcpy(data, &(t_paraboloid){
		PARABOLOID,
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
		json_get(val.data.obj, "height").data.number
	}, sizeof(t_paraboloid));
}
