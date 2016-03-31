/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_collision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/01 20:34:17 by mbarbari          #+#    #+#             */
/*   Updated: 2016/03/31 00:14:29 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>
#include <pthread.h>
#include "parser.h"
#include "framework_collision/fk_collision.h"
#include "framework_shape/fk_objects.h"
#include "framework_shape/fk_listobj.h"
#include "framework_light/fk_light.h"
#include "framework_math/fk_math.h"
#include "framework_math/fk_vector.h"

t_color3	ft_trace_ray(t_object arr[NB_OBJ], t_ray ray, int depth, t_env env)
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

t_ray		ray_calc(t_env env, float offsetx, float offsety)
{
	t_ray		ray;
	float		alpha1;
	float		alpha2;

	alpha1 = env.angley;
	alpha2 = env.anglex;
	ray.pos = env.pos_absolute_camera;
	ray.dir.x = (2. * ((env.xy[0] + offsetx) * env.invw) - 1.) *
		env.angle * env.ratio;
	ray.dir.y = (1. - 2. * ((env.xy[1] + offsety) * env.invh)) * env.angle;
	ray.dir.x = -cos(alpha1) * sin(alpha2)
		+ ray.dir.x * cos(alpha2) + ray.dir.y * sin(alpha1) * sin(alpha2);
	ray.dir.y = sin(alpha1) + ray.dir.y * cos(alpha1);
	ray.dir.z = cos(alpha1) * cos(alpha2)
		+ ray.dir.x * sin(alpha2) - ray.dir.y * sin(alpha1) * cos(alpha2);
	ray.dir = vector_unit(ray.dir);
	return (ray);
}

void		ft_apply_scene(t_env *env)
{
	int				thread;
	pthread_t		th[16];

	thread = -1;
	while (++thread < env->nb_thread)
	{
		env[thread].p_alias = thread * (WIDTH * (HEIGHT / (float)env->nb_thread));
		env[thread].max_alias = (thread + 1) * (WIDTH * (HEIGHT / (float)env->nb_thread));
		pthread_create(&th[thread], NULL, &routine_aliasing, &env[thread]);
	}
	while (--thread > -1)
		pthread_join(th[thread], NULL);
	mlx_put_image_to_window(env->mlx, env->win, env->img.ptr, 0, 0);
}

void		ft_render(t_env env)
{
	int				thread;
	t_env			tmp[16];
	pthread_t		th[16];

	env.xy[1] = -1;
	thread = 0;
	ft_bzero(env.arr, sizeof(t_object) * NB_OBJ);
	create_scene(parser(env.file), &env);
	while (thread < env.nb_thread)
		ft_memcpy(&tmp[thread++], &env, sizeof(t_env));
	thread = -1;
	while (++thread < env.nb_thread)
	{
		tmp[thread].p_alias = thread * (WIDTH * (HEIGHT / (float)env.nb_thread));
		tmp[thread].max_alias = (thread + 1) * (WIDTH * (HEIGHT / (float)env.nb_thread));
		pthread_create(&th[thread], NULL, &routine_render, &tmp[thread]);
	}
	while (--thread > -1)
		pthread_join(th[thread], NULL);
	ft_apply_scene(tmp);
	ft_putendl("End loading\n");
}
