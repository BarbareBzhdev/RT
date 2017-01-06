/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_new_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare <mbarbari@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 09:42:04 by barbare           #+#    #+#             */
/*   Updated: 2016/04/05 13:59:41 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "framework_shape/fk_sphere.h"
#include "framework_shape/fk_type.h"
#include "framework_shape/fk_newelement.h"

void		new_sphere(t_value val, t_object *data)
{
	ft_memcpy(data, &(t_sphere){ SPHERE,
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
	}, sizeof(t_sphere));
}
