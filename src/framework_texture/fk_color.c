/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 12:49:55 by root              #+#    #+#             */
/*   Updated: 2016/04/04 08:10:43 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_collision/fk_collision.h"
#include "framework_shape/fk_objects.h"
#include "framework_shape/fk_listobj.h"
#include "framework_light/fk_light.h"
#include "framework_math/fk_vector.h"
#include "framework_texture/fk_texture.h"
#include "framework_math/fk_math.h"

unsigned int	color_dword(t_color3 color)
{
	int		col[3];

	col[0] = ABS(color.r * 255);
	col[1] = ABS(color.g * 255);
	col[2] = ABS(color.b * 255);
	return ((col[0] & 0xFF) << 16) | ((col[1] & 0xFF) << 8) | (col[2] & 0xFF);
}

void			ft_put_pixel_to_image(t_img img, int x, int y, t_color3 color)
{
	int				addr;

	addr = y * img.sizeline + x * (img.bpp / 8);
	img.data[addr + 0] = FT_MAX(FT_MIN(color.b * 255, 255), 0);
	img.data[addr + 1] = FT_MAX(FT_MIN(color.g * 255, 255), 0);
	img.data[addr + 2] = FT_MAX(FT_MIN(color.r * 255, 255), 0);
}

t_color3		fk_finalcolor(t_object *arr, t_intersect in, t_env env)
{
	t_color3			color;
	t_ray				ray;
	float				shade;
	float				d[2];
	int					i[3];

	color = color_new(0, 0, 0);
	i[0] = -1;
	i[2] = 0;
	while (arr[(++i[0])].type != DEFAULT && (i[1] = -1))
		if (arr[i[0]].light == TRUE && (shade = 1.0) && (++i[2]))
		{
			d[0] = vector_magnitude(vector_substract(arr[i[0]].pos, in.pos));
			ray.pos = vector_substract(in.pos, vector_mul(in.v_normal, 1e-4f));
			ray.dir = vector_unit(vector_substract(arr[i[0]].pos, in.pos));
			while (arr[(++i[1])].type != DEFAULT)
				if (env.fctinter[arr[i[1]].type](ray, arr + i[1], &d[1]))
					if (arr[i[1]].light != TRUE && d[1] <= d[0])
					{
						shade = 0;
						break ;
					}
			color = vector_sum(color, iter_light(in, &arr[i[0]], shade));
		}
	return (vector_div(color, i[2]));
}

static t_color3	sepia(t_color3 outcolor)
{
	outcolor.r = (outcolor.r * .393) + (outcolor.g * .769) +
		(outcolor.b * .189);
	outcolor.g = (outcolor.r * .349) + (outcolor.g * .686) +
		(outcolor.b * .168);
	outcolor.b = (outcolor.r * .272) + (outcolor.g * .534) +
		(outcolor.b * .131);
	return (outcolor);
}

t_color3		process_color(t_object *arr, t_intersect it, t_env env,
		int depth)
{
	t_color3		outcolor;

	if (ft_strcmp(it.obj->mat.texture, "checkerboard") == 0)
		it.color = fk_checkerboard(it);
	else if (ft_strcmp(it.obj->mat.texture, "perlin") == 0)
		it.color = fk_perlin(it);
	else
		it.color = it.obj->mat.color1;
	it.water = (ft_strcmp(it.obj->mat.texture, "water") == 0) ? 1 : 0;
	outcolor = fk_finalcolor(arr, it, env);
	if (it.obj->reflection_index != 0.0 && depth < env.depth)
		outcolor = vector_sum(outcolor, vector_mul(ft_trace_ray(arr,
			create_reflection(it.ray, it), depth + 1, env),
				it.obj->reflection_index));
	if (it.obj->refraction_index != 0.0 && depth < env.depth)
		outcolor = vector_sum(outcolor, vector_mul(
			ft_trace_ray(arr, create_refraction(it.ray, it),
				depth + 1, env), it.obj->refraction_index));
	if (env.sepia == 1)
		outcolor = sepia(outcolor);
	return (outcolor);
}
