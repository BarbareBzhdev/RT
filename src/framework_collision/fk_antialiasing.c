/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_antialiasing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 16:14:38 by root              #+#    #+#             */
/*   Updated: 2016/03/26 15:27:53 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_collision/fk_collision.h"
#include "framework_shape/fk_objects.h"
#include "framework_shape/fk_listobj.h"
#include "framework_light/fk_light.h"
#include "framework_math/fk_math.h"
#include "framework_math/fk_vector.h"


t_color3		antialiasing(t_object arr[16], t_env env, t_color3 color, int n)
{
	int				nalias[3];
	t_ray			ray;
	float			offset[2];

	nalias[0] = -(n / 2);
	nalias[2] = 1;
	ft_bzero(offset, sizeof(float) * 2);
	if (n == 1)
		return (color);
	while (nalias[0] < ((n / 2) + 1))
	{
		nalias[1] = -(n / 2);
		while (nalias[1] < ((n / 2) + 1))
		{
			ray = ray_calc(env, nalias[0], nalias[1]);
			color = vector_sum(color, ft_trace_ray(arr, ray, 0, env));
			++nalias[2];
			++nalias[1];
		}
		++nalias[0];
	}
	return (vector_div(color, nalias[2]));
}
