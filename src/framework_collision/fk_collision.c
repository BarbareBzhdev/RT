/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_collision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/01 20:34:17 by mbarbari          #+#    #+#             */
/*   Updated: 2016/03/21 10:01:10 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "parser.h"
#include "framework_shape/fk_type.h"
#include "framework_collision/fk_collision.h"
#include "framework_light/fk_normal_sphere.h"
#include "framework_shape/fk_objects.h"
#include "framework_shape/fk_listobj.h"
#include "framework_light/fk_light.h"
#include "framework_math/fk_math.h"
#include "framework_math/fk_vector.h"

#define VECTOR_UP ((t_vector3) { .x = 0, .y = 1, .z = 0 })
#define COLOR_ZERO ((t_color3) { .r = 0, .g = 0, .b = 0 })

int	g_depth;


static void		fill_arr(t_value val, int idx, t_object *data)
{
	if (ft_strequ(json_get(val.data.obj, "type").data.s, "SPHERE"))
		new_sphere(val, &data[idx]);
	else if (ft_strequ(json_get(val.data.obj, "type").data.s, "PLANE"))
		new_plane(val, &data[idx]);
	else if (ft_strequ(json_get(val.data.obj, "type").data.s, "CYLINDER"))
		new_cylinder(val, &data[idx]);
	else if (ft_strequ(json_get(val.data.obj, "type").data.s, "CONE"))
		new_cone(val, &data[idx]);
}

static	void	create_scene(t_value val, t_object *arr/*, t_object *light*/)
{
	json_foreach_arr(json_get(val.data.obj, "scene").data.arr, &fill_arr, arr);
	arr[json_arr_length(json_get(val.data.obj, "scene").data.arr)].type = DEFAULT;
	arr[json_arr_length(json_get(val.data.obj, "scene").data.arr) + 1].type = DEFAULT;
	g_depth = (int)json_get(val.data.obj, "depth").data.number;
}

static	t_color3	getfinalcolor(t_object *arr, t_intersect inter, t_env env)
{
	t_color3			color;
	t_color3			color_tmp;
	float				dist[2];
	t_ray 				newray;
	float				shade;
	t_vector3			l;

	int					i;
	int 				k;
	int 				a;

	color_tmp = color_new(0, 0, 0);
	a = 0;
	if (inter.obj)
	{
		i = -1;
		while(arr[i].type != DEFAULT)
		{
			shade = 1.0;
			if (arr[i].light == TRUE)
			{
				l = vector_substract(arr[i].pos, inter.pos);
				dist[0] = vector_magnitude(l);
				newray.pos = vector_substract(inter.pos, vector_mul(inter.v_normal, 1e-4f));
				newray.dir = vector_unit(l);
				k = -1;
				while (++k < 16 && arr[k].type != DEFAULT)
					if (env.fctinter[arr[k].type](newray, arr + k, &dist[1]))
					{
						if (arr[k].light != TRUE && dist[1] <= dist[0])
							shade -= 0.3;
					}
				color_tmp = vector_sum(color_tmp, iter_light(inter, &arr[i], shade));
				++a;
			}
			++i;
		}
		return (vector_div(color_tmp, a));
	}
	return (color_new(17, 25, 37));
}

t_ray	create_reflection(t_ray ray, t_intersect inter)
{
	t_ray		newray;
	t_vector3	 norm;

	norm = inter.v_normal;
	newray.dir = vector_substract(ray.dir,
			vector_mul(norm, 2.0f * vector_dotproduct(ray.dir, norm)));
	newray.pos = inter.pos;
	return (newray);
}

t_color3	ft_trace_ray(t_object arr[16],/* t_object light[16],*/ t_ray ray, int depth, float *dist_out, t_env env)
{
	t_intersect		inter;
	t_color3		outcolor;
	t_color3		refl_color;
	int				i;
	float			dist;
	float			_dist_out;

	if (dist_out == NULL)
		dist_out = &_dist_out;
	*dist_out = INFINITY;
	outcolor = color_new(17, 25, 37);
	i = -1;
	inter.obj = NULL;
	while (++i < 16 && arr[i].type != DEFAULT)
		if (env.fctinter[arr[i].type](ray, arr + i, &dist))
			if ((!inter.obj || dist < *dist_out) && dist > 0.00001)
			{
				inter.obj = &arr[i];
				*dist_out = dist;
			}
	if (inter.obj)
	{
		inter.pos = create_intersect(ray, *dist_out);
		inter.v_normal = env.fctnormal[inter.obj->type](ray, inter.pos, inter.obj);
		inter.ray = ray;
		outcolor = getfinalcolor(arr, inter, env);
		if (inter.obj->reflection_index != 0.0 && depth < g_depth)
		{
			refl_color = ft_trace_ray(arr, create_reflection(ray, inter), depth + 1, NULL, env);
			outcolor = vector_sum(outcolor, vector_mul(refl_color, inter.obj->reflection_index));
		}
	}
	return outcolor;
}

void			ft_put_pixel_to_image(t_img img, int x, int y, t_color3 color)
{
	int				addr;

	addr = y * img.sizeline + x * (img.bpp / 8);
	img.data[addr + 0] = FT_MAX(FT_MIN(color.b * 255, 255), 0);
	img.data[addr + 1] = FT_MAX(FT_MIN(color.g * 255, 255), 0);
	img.data[addr + 2] = FT_MAX(FT_MIN(color.r * 255, 255), 0);
}

void		ft_render2(t_env env)
{
	t_color3	rgba;
	t_ray	ray;
	float	y;
	float	x;
	t_object arr[16];
	t_object light[16];
	float invW = 1 / (float)env.resolution.width;
	float invH = 1 / (float)env.resolution.height;
	float ratio = env.resolution.width / (float)env.resolution.height;
	float angle = tanf(M_PI * 0.5f * env.fov / 180.);

	ft_bzero(arr, sizeof(t_object) * 16);
	ft_bzero(light, sizeof(t_object) * 16);
	create_scene(parser(env.file), arr/*, light*/);
	y = 0;
	while (y < env.resolution.height)
	{
		x = 0;
		while (x < env.resolution.width)
		{
			ray.pos = env.pos_absolute_camera;
			ray.dir.x = (2. *(x * invW) - 1.) * angle * ratio;
			ray.dir.y = (1. - 2. * (y * invH)) * angle;
			ray.dir.z = 1;
			ray.dir = vector_unit(ray.dir);
			rgba = ft_trace_ray(arr, /*light,*/ ray, 0, NULL, env);
			ft_put_pixel_to_image(env.img, x, y, rgba);
			x++;
		}
		y++;
	}
	dprintf(2, "The end\n");
	mlx_put_image_to_window(env.mlx, env.win, env.img.ptr, 0, 0);
}

void		ft_render(t_env env)
{
	ft_render2(env);
}
