/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_antialiasing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 16:14:38 by root              #+#    #+#             */
/*   Updated: 2016/03/30 17:39:02 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <pthread.h>
#include "framework_collision/fk_collision.h"
#include "framework_shape/fk_objects.h"
#include "framework_shape/fk_listobj.h"
#include "framework_light/fk_light.h"
#include "framework_math/fk_math.h"
#include "framework_math/fk_vector.h"

t_color3		rgb_to_xyz(t_color3 color)
{
	t_color3		out;

	color.r = (color.r > 0.04045f) ? pow(((color.r + 0.055f) / 1.055f), 2.4f)
		: color.r / 12.92f;
	color.g = (color.g > 0.04045f) ? pow(((color.g + 0.055f) / 1.055f), 2.4f)
		: color.g / 12.92f;
	color.b = (color.b > 0.04045f) ? pow(((color.b + 0.055f) / 1.055f), 2.4f)
		: color.b / 12.92f;
	vector_mul(color, 100);
	out.r = color.r * 0.4124f + color.g * 0.3576f + color.b * 0.1805f;
	out.g = color.r * 0.2126f + color.g * 0.7152f + color.b * 0.0722f;
	out.b = color.r * 0.0193f + color.g * 0.1192f + color.b * 0.9505f;
	return (out);
}

t_color3		xyz_to_lab(t_color3 color)
{
	t_color3		lab;
	t_color3		out;

	lab.r = color.r / 95.047;
	lab.g = color.g / 100.;
	lab.b = color.b / 108.883;

	lab.r = (lab.r > 0.008856) ? pow(lab.r, (1/3.)) : (903 * lab.r + 16) / 116;
	lab.g = (lab.g > 0.008856) ? pow(lab.g, (1/3.)) : (903 * lab.g + 16) / 116;
	lab.b = (lab.b > 0.008856) ? pow(lab.b, (1/3.)) : (903 * lab.b + 16) / 116;
	out.r = FT_MAX((116 * lab.g) - 16, 0);
	out.g = 500 * (lab.r - lab.g);
	out.b = 200 * (lab.g - lab.b);
	return (out);
}

float				delta_e(t_color3 lab1, t_color3 lab2)
{
	float		delta_e;

	delta_e = sqrtf(SQUARE(lab1.r - lab2.r) +
			SQUARE(lab1.g - lab2.g) + SQUARE(lab1.b - lab2.b));
	return (delta_e);
}

t_color3		supersampling(t_env env)
{
	float			y;
	float			x;
	int				a;
	t_color3		col;
	t_ray			ray;

	col = color_new(0, 0, 0);
	y = -(1 / 2.);
	a = 0;
	while (y < 0.6)
	{
		x = -(1 / 2);
		while (x < 0.6)
		{
			ray = ray_calc(env, x, y);
			col = vector_sum(col, ft_trace_ray(env.arr, ray, 0, env));
			x += (1 / (float)env.sampling);
			++a;
		}
		y += (1 / (float)env.sampling);
	}
	return (vector_div(col, a));
}

t_color3		sampling(t_env env, int i)
{
	t_color3		tmp[5];
	float			delta;

	if ((i - WIDTH) <= 0  || (i + WIDTH) >= (WIDTH * HEIGHT) || i < 1 ||
			(i % WIDTH) < 1 || floor(i / WIDTH) < 1)
		return (env.matrice[i]);
	if ((i % WIDTH) > (WIDTH - 1) && floor(i / WIDTH) > (HEIGHT - 1))
		return (env.matrice[i]);
	tmp[0] = xyz_to_lab(rgb_to_xyz(env.matrice[i]));
	tmp[1] = xyz_to_lab(rgb_to_xyz(env.matrice[(i - 1)]));
	tmp[2] = xyz_to_lab(rgb_to_xyz(env.matrice[(i - WIDTH)]));
	tmp[3] = xyz_to_lab(rgb_to_xyz(env.matrice[(i + 1)]));
	tmp[4] = xyz_to_lab(rgb_to_xyz(env.matrice[(i + WIDTH)]));
	delta = delta_e(tmp[0], tmp[1]);
	delta += delta_e(tmp[0], tmp[2]);
	delta += delta_e(tmp[0], tmp[3]);
	delta += delta_e(tmp[0], tmp[4]);
	if (delta < 1)
		return (env.matrice[i]);
	env.xy[0] = (i % WIDTH);
	env.xy[1] = floor(i / WIDTH);
	return (supersampling(env));
}
