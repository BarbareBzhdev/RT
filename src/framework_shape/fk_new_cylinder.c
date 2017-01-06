/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_new_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare <mbarbari@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 09:49:28 by barbare           #+#    #+#             */
/*   Updated: 2016/03/31 12:26:18 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "framework_shape/fk_cylinder.h"
#include "framework_math/fk_vector.h"
#include "framework_shape/fk_newelement.h"

void		new_cylinder(t_value val, t_object *data)
{
	ft_memcpy(data, &(t_cylinder){
		CYLINDER,
		new_material(val),
		json_get(val.data.obj, "reflection_index").data.number,
		json_get(val.data.obj, "refraction_index").data.number,
		json_get(val.data.obj, "ambient").data.number,
		json_get(val.data.obj, "diffuse").data.number,
		json_get(val.data.obj, "specular").data.number,
		json_get(val.data.obj, "light").data.boolean,
		new_position(val),
		new_direction(val),
		json_get(val.data.obj, "radius").data.number
	}, sizeof(t_cylinder));
}
