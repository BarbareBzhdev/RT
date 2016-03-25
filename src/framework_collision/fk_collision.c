/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_collision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/01 20:34:17 by mbarbari          #+#    #+#             */
/*   Updated: 2016/03/25 13:55:41 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "parser.h"
#include "framework_collision/fk_collision.h"
#include "framework_shape/fk_objects.h"
#include "framework_shape/fk_listobj.h"
#include "framework_light/fk_light.h"
#include "framework_math/fk_math.h"
#include "framework_math/fk_vector.h"

t_color3		ft_trace_ray(t_object arr[16], t_ray ray, int depth, t_env env)
{
	t_intersect		inter;
	int				i;
	float			dist;
	float			dist_out;

	dist_out = INFINITY;
	i = -1;
	inter.obj = NULL;
	while (arr[(++i)].type != DEFAULT)
		if (env.fctinter[arr[i].type](ray, arr + i, &dist))
			if ((!inter.obj || dist < dist_out) && dist > 1e-4f)
			{
				inter.obj = &arr[i];
				dist_out = dist;
			}
	if (!inter.obj)
		return (color_new(17, 25, 37));
	inter.ray = ray;
	inter.pos = create_intersect(ray, dist_out);
	inter.v_normal = env.fctnormal[inter.obj->type](ray, inter.pos, inter.obj);
	return (process_color(arr, inter, env, depth));
}

void		ft_render(t_env env, float invW, float invH)
{
	t_ray		ray;
	float		xy[2];
	float		ratio;
	float		angle;
	t_object	arr[16];

	angle = tanf(M_PI * 0.5f * env.fov / 180.);
	ratio = env.resolution.width / (float)env.resolution.height;
	ft_bzero(arr, sizeof(t_object) * 16);
	create_scene(parser(env.file), arr);
	xy[1] = -1;
	while (++xy[1] < env.resolution.height && (xy[0] = -1))
		while (++xy[0] < env.resolution.width)
		{
			ray.pos = env.pos_absolute_camera;
			ray.dir.x = (2. *(xy[0] * invW) - 1.) * angle * ratio;
			ray.dir.y = (1. - 2. * (xy[1] * invH)) * angle;
			ray.dir.z = 1;
			ray.dir = vector_unit(ray.dir);
			ft_put_pixel_to_image(env.img, xy[0], xy[1],
					ft_trace_ray(arr, ray, 0, env));
		}
	mlx_put_image_to_window(env.mlx, env.win, env.img.ptr, 0, 0);
}
