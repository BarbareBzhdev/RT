/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 12:49:55 by root              #+#    #+#             */
/*   Updated: 2016/03/25 14:04:04 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_collision/fk_collision.h"
#include "framework_shape/fk_objects.h"
#include "framework_shape/fk_listobj.h"
#include "framework_light/fk_light.h"
#include "framework_math/fk_vector.h"
#include "framework_texture/fk_texture.h"

void			ft_put_pixel_to_image(t_img img, int x, int y, t_color3 color)
{
	int				addr;

	addr = y * img.sizeline + x * (img.bpp / 8);
	img.data[addr + 0] = FT_MAX(FT_MIN(color.b * 255, 255), 0);
	img.data[addr + 1] = FT_MAX(FT_MIN(color.g * 255, 255), 0);
	img.data[addr + 2] = FT_MAX(FT_MIN(color.r * 255, 255), 0);
}

t_color3	fk_finalcolor(t_object *arr, t_intersect inter, t_env env)
{
	t_color3			color;
	t_ray 				ray;
	float				shade;
	float				d[2];
	int					i[3];

	color = color_new(0, 0, 0);
	i[0] = -1;
	i[2] = 0;
	while(arr[(++i[0])].type != DEFAULT)
		if (arr[i[0]].light == TRUE && (i[1] = -1) && (shade = 1.0) && (++i[2]))
		{
			d[0] = vector_magnitude(vector_substract(arr[i[0]].pos, inter.pos));
			ray.pos = vector_sum(inter.pos, vector_mul(inter.v_normal, -1e-4f));
			ray.dir = vector_unit(vector_substract(arr[i[0]].pos, inter.pos));
			while (arr[(++i[1])].type != DEFAULT)
				if (env.fctinter[arr[i[1]].type](ray, arr + i[1], &d[1]))
					if (arr[i[1]].light != TRUE && d[1] <= d[0])
					{
						shade = 0;
						break ;
					}
			color = vector_sum(color, iter_light(inter, &arr[i[0]], shade));
		}
	return (vector_div(color, i[2]));
}

t_color3	process_color(t_object *arr, t_intersect it, t_env env, int depth)
{
	t_color3		outcolor;
	t_color3		refl_color;

	if (ft_strcmp(it.obj->mat.texture, "checkerboard") == 0)
		it.color = fk_checkerboard(it);
	else if (ft_strcmp(it.obj->mat.texture, "perlin") == 0)
		it.color = fk_perlin(it);
	else
		it.color = it.obj->mat.color1;
	outcolor = fk_finalcolor(arr, it, env);
	if (it.obj->reflection_index != 0.0 && depth < g_depth)
	{
		refl_color = ft_trace_ray(arr,
				create_reflection(it.ray, it), depth + 1, env);
		outcolor = vector_sum(outcolor,
				vector_mul(refl_color, it.obj->reflection_index));
	}
	return (outcolor);
}
