/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_createscene.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 13:12:45 by root              #+#    #+#             */
/*   Updated: 2016/03/29 08:09:45 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_collision/fk_collision.h"
#include "framework_shape/fk_objects.h"
#include "framework_shape/fk_listobj.h"
#include "framework_light/fk_light.h"
#include "framework_math/fk_vector.h"

void		fill_arr(t_value val, int idx, void *obj)
{
	t_object *data;

	data = (t_object *)obj;
	if (ft_strequ(json_get(val.data.obj, "type").data.s, "SPHERE"))
		new_sphere(val, &data[idx]);
	else if (ft_strequ(json_get(val.data.obj, "type").data.s, "PLANE"))
		new_plane(val, &data[idx]);
	else if (ft_strequ(json_get(val.data.obj, "type").data.s, "CYLINDER"))
		new_cylinder(val, &data[idx]);
	else if (ft_strequ(json_get(val.data.obj, "type").data.s, "CONE"))
		new_cone(val, &data[idx]);
	else if (ft_strequ(json_get(val.data.obj, "type").data.s, "TRIANGLE"))
		new_triangle(val, &data[idx]);
	else if (ft_strequ(json_get(val.data.obj, "type").data.s, "PARABOLOID"))
		new_paraboloid(val, &data[idx]);
}

void		create_scene(t_value val, t_env *env)
{
	static unsigned int def = DEFAULT;

	ft_bzero(env->arr, sizeof(t_object) * NB_OBJ);
	json_foreach_arr(
			json_get(val.data.obj, "scene").data.arr, &fill_arr, env->arr);
	env->arr[json_arr_length(
			json_get(val.data.obj, "scene").data.arr)].type = def;
	env->depth = (int)json_get(val.data.obj, "depth").data.number;
	env->sampling = (int)json_get(val.data.obj, "sampling").data.number;
}
