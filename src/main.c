/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 21:03:28 by roblabla          #+#    #+#             */
/*   Updated: 2016/03/26 17:52:15 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_env.h"
#include <mlx.h>
#include "ft_printf.h"
#include "framework_math/fk_math.h"
#include "framework_math/fk_vector.h"
#include "framework_collision/fk_collision.h"

#define WIDTH 1224
#define HEIGHT 780

int		rt_expose_hook(t_env *env)
{

	env->angle = tanf(M_PI * 0.5f * env->fov / 180.);
	env->ratio = env->resolution.width / (float)env->resolution.height;
	env->invw = 1 / (float)env->resolution.width;
	env->invh = 1 / (float)env->resolution.height;
	env->nb_thread = 4;
	ft_render(*env);
	return (0);
}

static int key_press(int key, t_env *env)
{
	(void)env;
	if (key == 53 || key == 65307)
		exit(0);
	return (0);
}

int		main(int argc, char **argv)
{
	t_env	env;

	(void)argc;
	(void)argv;
	if (argc == 2)
	{
		env.mlx = mlx_init();
		env.file = argv[1];
		env.resolution.width = WIDTH;
		env.resolution.height = HEIGHT;
		env.win = mlx_new_window(env.mlx, WIDTH, HEIGHT, "RayTracer");
		env.img.ptr = mlx_new_image(env.mlx, WIDTH, HEIGHT);
		env.img.data = mlx_get_data_addr(env.img.ptr, &env.img.bpp,
				&env.img.sizeline, &env.img.endianness);
		env.fov = 45;
		env.pos_absolute_camera = (t_vertex3) { .x = 0, .y = 0, .z = 0 };
		ft_setup_inter(env.fctinter);
		ft_setup_normal(env.fctnormal);
		mlx_hook(env.win, 2, (1L << 0), &key_press, &env);
		mlx_expose_hook(env.win, rt_expose_hook, &env);
		mlx_loop(env.mlx);
	}
	else
		ft_printf("Usage: %s scene.json\n", argv[0]);
	return (0);
}
