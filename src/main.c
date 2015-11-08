/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 21:03:28 by roblabla          #+#    #+#             */
/*   Updated: 2015/11/06 21:27:01 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_env.h"
#include <mlx.h>
#include "ft_printf.h"
#include "framework/fk_vectoriel.h"
#include "framework/fk_type.h"
#include "framework/fk_sphere.h"

int		rt_expose_hook(t_env *env)
{
	ft_render(*env);
	return (0);
}

/*
** TODO : Check segfault
*/
int		main(int argc, char **argv)
{
	t_env	env;

	(void)argc;
	(void)argv;
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, 500, 500, "RayTracer");
	env.img = mlx_new_image(env.mlx, 500, 500);
	env.resolution.height = 500;
	env.resolution.width = 500;
	env.fov = 60;
	env.pos_absolute_camera = (t_vertex3) { 0, 0, 0 };
	env.dir_camera = (t_vector3) { 0, 0, 1 };
	env.fctinter[SPHERE] = (t_fct_inter)intersect_sphere;
	mlx_expose_hook(env.win, rt_expose_hook, &env);
	mlx_loop(env.mlx);
	return (0);
}
