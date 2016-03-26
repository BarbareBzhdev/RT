/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_collision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/01 20:34:17 by mbarbari          #+#    #+#             */
/*   Updated: 2016/03/26 19:04:25 by root             ###   ########.fr       */
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

	ray.pos = env.pos_absolute_camera;
	ray.dir.x = (2. *((env.xy[0] + offsetx) * env.invw) - 1.) * env.angle * env.ratio;
	ray.dir.y = (1. - 2. * ((env.xy[1] + offsety) * env.invh)) * env.angle;
	ray.dir.z = 1;
	ray.dir = vector_unit(ray.dir);
	return (ray);
}

static void	*ft_routine(void *arg)
{
	int			i;
	t_ray		ray;
	t_env		*env;

	env = (t_env *)arg;
	i = 0;
	env->xy[0] = -1;
	dprintf(2, "Lancement de la routine: y = %d\n", env->xy[1]);
	while (++env->xy[0] < env->resolution.width)
	{
		ray = ray_calc(*env, env->invw, env->invh);
		ft_put_pixel_to_image(env->img, env->xy[0], env->xy[1],
				antialiasing(env->arr, *env, ft_trace_ray(env->arr, ray, 0, *env), 4));
	}
	pthread_exit(0);
}

void		ft_render(t_env env)
{
	int				i_thread;
	pthread_t		th[16];
	void			*ret;

	ft_bzero(env.arr, sizeof(t_object) * 16);
	create_scene(parser(env.file), env.arr);
	env.xy[1] = -1;
	i_thread = 0;
	while (env.xy[1] < env.resolution.height || i_thread > 0)
	{
		while (env.xy[1] < env.resolution.height && i_thread < env.nb_thread)
		{
			++env.xy[1];
			if (pthread_create(&th[i_thread], NULL, ft_routine, &env) == 0)
			{
				dprintf(2, "creatiion d'un thread %d\n", i_thread);
				if (i_thread == (env.nb_thread - 1) || env.xy[1] >= env.resolution.height)
					break ;
				++i_thread;
			}
			else
				exit(0);
		}
		sleep(1);
		while (i_thread > -1) {
			dprintf(2, "destruction d'un thread %d\n", i_thread);
			pthread_join(th[i_thread], &ret);
			--i_thread;
		}
		i_thread = 0;
	}
	mlx_put_image_to_window(env.mlx, env.win, env.img.ptr, 0, 0);
}
