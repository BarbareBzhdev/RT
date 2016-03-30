/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_collision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/01 20:34:17 by mbarbari          #+#    #+#             */
/*   Updated: 2016/03/30 18:23:51 by root             ###   ########.fr       */
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

static void	*routine_render(void *arg)
{
	int			i;
	t_ray		ray;
	t_env		*env;

	env = (t_env *)arg;
	env->xy[0] = -1;
	while (++env->xy[0] < env->resolution.width)
	{
		i = env->xy[1] * WIDTH + env->xy[0];
		ray = ray_calc(*env, 0, 0);
		env->matrice[i] = ft_trace_ray(env->arr, ray, 0, *env);
	}
	pthread_exit(0);
}

//static void	*routine_aliasing(void *arg)
//{
//	ft_put_pixel_to_image(env->img, (i % WIDTH), floor(i / WIDTH),
//			sampling(*env, i));
//}

void		ft_apply_scene(t_env *env)
{
	int		i;
	int		thread;
	t_env	tmp[16];

	i = -1;
	//thread = 0;
	//while (thread < env.nb_thread)
	//	ft_memcpy(&tmp[thread++], &env, sizeof(t_env));
	//thread = -1;
	//i = 0;
	//while (++thread < 4)
	//{
	//	env.p_alias = thread * (HEIGHT / env.nb_thread);
	//	pthread_create(&env.th[thread], NULL, routine_render, &tmp[thread]);
	//}
	while (++i < WIDTH * HEIGHT)
		ft_put_pixel_to_image(env->img, (i % WIDTH), floor(i / WIDTH),
			sampling(*env, i));
	mlx_put_image_to_window(env->mlx, env->win, env->img.ptr, 0, 0);
}

void		ft_render(t_env env)
{
	int				thread;
	t_env			tmp[16];

	env.xy[1] = -1;
	thread = 0;
	ft_bzero(env.arr, sizeof(t_object) * 16);
	create_scene(parser(env.file), &env);
	while (thread < env.nb_thread)
		ft_memcpy(&tmp[thread++], &env, sizeof(t_env));
	while (env.xy[1] < env.resolution.height)
	{
		thread = 0;
		while ((tmp[thread].xy[1] = ++env.xy[1]) < env.resolution.height)
		{
			pthread_create(&env.th[thread], NULL, routine_render, &tmp[thread]);
			if (thread == (env.nb_thread - 1))
				while (thread > -1)
				{
					pthread_join(env.th[thread], NULL);
					--thread;
				}
			thread++;
		}
	}
	ft_apply_scene(&env);
}
