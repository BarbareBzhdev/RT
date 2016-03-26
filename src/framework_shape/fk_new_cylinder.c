/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_new_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare </var/spool/mail/barbare>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 09:49:28 by barbare           #+#    #+#             */
/*   Updated: 2016/03/25 15:41:30 by root             ###   ########.fr       */
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
		new_material(val, data),
		json_get(val.data.obj, "reflection_index").data.number,
		json_get(val.data.obj, "refraction_index").data.number,
		json_get(val.data.obj, "ambient").data.number,
		json_get(val.data.obj, "diffuse").data.number,
		json_get(val.data.obj, "specular").data.number,
		json_get(val.data.obj, "light").data.boolean,
		new_position(val, data),
		new_direction(val, data),
		json_get(val.data.obj, "radius").data.number
	}, sizeof(t_cylinder));
}
