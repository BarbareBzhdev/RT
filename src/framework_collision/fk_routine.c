/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 00:10:15 by root              #+#    #+#             */
/*   Updated: 2016/03/31 12:52:09 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <mlx.h>
#include <unistd.h>
#include "framework_collision/fk_collision.h"
#include "framework_shape/fk_objects.h"
#include "framework_shape/fk_listobj.h"
#include "framework_light/fk_light.h"
#include "framework_math/fk_math.h"
#include "framework_math/fk_vector.h"

void	*routine_render(void *arg)
{
	t_ray		ray;
	t_env		*env;

	env = (t_env *)arg;
	while (++env->p_alias < env->max_alias)
	{
		env->xy[0] = env->p_alias % WIDTH;
		env->xy[1] = floor(env->p_alias / WIDTH);
		ray = ray_calc(*env, 0, 0);
		env->matrice[env->p_alias] = ft_trace_ray(env->arr, ray, 0, *env);
	}
	pthread_exit(0);
	return (NULL);
}

void	*routine_aliasing(void *arg)
{
	t_env	*env;

	env = (t_env *)arg;
	while (++env->p_alias < env->max_alias)
		ft_put_pixel_to_image(env->img, (env->p_alias % WIDTH),
			floor(env->p_alias / WIDTH), sampling(*env, env->p_alias));
	pthread_exit(0);
	return (NULL);
}
