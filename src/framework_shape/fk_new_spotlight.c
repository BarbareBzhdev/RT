/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_new_spotlight.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare </var/spool/mail/barbare>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 09:54:02 by barbare           #+#    #+#             */
/*   Updated: 2016/02/17 10:18:04 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "framework_light/fk_light.h"

void		new_spotlight(t_value val, t_object *data)
{
	ft_memcpy(data, &(t_spotlight){
		SPOTLIGHT,
		color_new(json_get(val.data.obj, "color.red").data.number, json_get(val.data.obj, "color.green").data.number, json_get(val.data.obj, "color.blue").data.number),
		json_get(val.data.obj, "reflection_index").data.number,
		json_get(val.data.obj, "diffuse").data.number,
		json_get(val.data.obj, "refraction").data.number,
		json_get(val.data.obj, "refraction_index").data.number,
		vector_new(json_get(val.data.obj, "pos.x").data.number, json_get(val.data.obj, "pos.y").data.number, json_get(val.data.obj, "pos.z").data.number),
		vector_new(json_get(val.data.obj, "dir.x").data.number, json_get(val.data.obj, "dir.y").data.number, json_get(val.data.obj, "dir.z").data.number),
		json_get(val.data.obj, "intensity").data.number
	}, sizeof(t_spotlight));
}
