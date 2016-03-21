/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 21:03:28 by roblabla          #+#    #+#             */
/*   Updated: 2016/03/21 10:59:12 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_env.h"
#include <mlx.h>
#include "ft_printf.h"
#include "framework_math/fk_vector.h"
#include "framework_collision/fk_collision.h"
#include <stdlib.h>

#define WIDTH 1224
#define HEIGHT 780
int		rt_expose_hook(t_env *env)
{
	ft_render(*env);
	return (0);
}

/*
** TODO : Check segfault
*/
static int key_press(int key, t_env *env)
{
	if (key == 53 || key == 65307)
		exit(0);
	return (0);
}

int		main(int argc, char **argv)
{
	t_env	env;

	(void)argc;
	(void)argv;
	if (argc < 2)
	{
		ft_printf("Usage: %s scene.json\n", argv[0]);
		return (0);
	}
	env.mlx = mlx_init();
	env.file = argv[1];
	env.resolution.width = 1224;
	env.resolution.height = 780;
	env.win = mlx_new_window(env.mlx, env.resolution.width, env.resolution.height, "RayTracer");
	env.img.ptr = mlx_new_image(env.mlx, env.resolution.width, env.resolution.height);
	env.img.data = mlx_get_data_addr(env.img.ptr, &env.img.bpp, &env.img.sizeline, &env.img.endianness);
	env.fov = 45;
	env.pos_absolute_camera = (t_vertex3) { .x = 0, .y = 0, .z = 0 };
	env.dir_camera = (t_vector3) { .x = 0, .y = 0, .z = 1 };
	ft_setup_inter(env.fctinter);
	ft_setup_normal(env.fctnormal);
	mlx_hook(env.win, 2, (1L << 0), &key_press, &env);
	mlx_expose_hook(env.win, rt_expose_hook, &env);
	mlx_loop(env.mlx);
	return (0);
}
