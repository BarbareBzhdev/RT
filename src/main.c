/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 21:03:28 by roblabla          #+#    #+#             */
/*   Updated: 2016/04/05 15:58:33 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "ft_printf.h"
#include "parser/parser.h"
#include "framework_math/fk_math.h"
#include "framework_math/fk_vector.h"
#include "framework_event/fk_event.h"
#include "ft_env.h"

void		init_env(t_env *env)
{
	env->mlx = mlx_init();
	env->resolution.width = WIDTH;
	env->resolution.height = HEIGHT;
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "RayTracer");
	env->img.ptr = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	env->img.data = mlx_get_data_addr(env->img.ptr, &env->img.bpp,
			&env->img.sizeline, &env->img.endianness);
	init_img(env, "loading.xpm");
	mlx_put_image_to_window(env->mlx, env->win, env->loading.img,
		env->mid_w, env->mid_h);
	mlx_put_image_to_window(env->mlx, env->win, env->loading.img, 0, 0);
	env->fov = 45;
	env->pos_absolute_camera = (t_vertex3){
		.x = json_get(parser(env->file).data.obj, "pos_camera.x").data.number,
		.y = json_get(parser(env->file).data.obj, "pos_camera.y").data.number,
		.z = json_get(parser(env->file).data.obj, "pos_camera.z").data.number};
	env->matrice = malloc(sizeof(t_color3) * (WIDTH * HEIGHT) + 1);
	env->angle = tanf(M_PI * 0.5f * env->fov / 180.);
	env->ratio = env->resolution.width / (float)env->resolution.height;
	env->invw = 1 / (float)env->resolution.width;
	env->invh = 1 / (float)env->resolution.height;
	env->nb_thread = 16;
	env->sampling = 2;
	env->anglex = 0;
	env->angley = 0;
}

int			main(int argc, char **argv)
{
	t_env		env;
	struct stat	file_stat;

	if (argc == 2)
	{
		env.file = argv[1];
		if (stat(env.file, &file_stat) < 0)
		{
			ft_printf("file not exists\n");
			exit(0);
		}
		file_is_modified(env.file, &env.oldtime, 1);
		init_env(&env);
		ft_setup_inter(env.fctinter);
		ft_setup_normal(env.fctnormal);
		mlx_do_key_autorepeatoff(env.mlx);
		mlx_hook(env.win, 2, (1L << 0), &key_press, &env);
		mlx_loop_hook(env.mlx, &loop_hook, &env);
		mlx_expose_hook(env.win, &rt_expose_hook, &env);
		mlx_loop(env.mlx);
		free(env.matrice);
	}
	else
		ft_printf("Usage: %s scene.json\n", argv[0]);
	return (0);
}
