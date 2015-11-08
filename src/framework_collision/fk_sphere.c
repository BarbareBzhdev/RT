/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 21:18:55 by mbarbari          #+#    #+#             */
/*   Updated: 2015/11/06 21:24:52 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework/fk_sphere.h"
#include "framework/fk_math.h"
#include <stdlib.h>

#define DPI (PI - (PI / 2))

static t_bool	sphere_crossroad(t_ray ray, t_sphere sphere, t_intersect *i)
{
	int				angle;
	t_vector3		eyetocenter;
	t_vector3		vector_a;
	unsigned int	adjacent;

	eyetocenter = (t_vector3) { ray.pos.x - sphere.pos.x,
								ray.pos.y - sphere.pos.y,
								ray.pos.z - sphere.pos.z };
	angle = vector_dotproduct(ray.dir, eyetocenter);
	angle = acos(angle);
	adjacent = vector_magnitude(eyetocenter) * sin(angle);
	adjacent = sqrt(-(SQUARE(sphere.radius) + SQUARE(adjacent)));
	angle = DPI - angle;
	vector_a = (t_vector3) {adjacent * sin(angle), adjacent * cos(angle), 0};
	i->pos = vector_translation(vector_a, sphere.pos);
	//i->dir = (t_vector) {-ray.dir.x, -ray.dir.y, -ray.dir.z};
	return (adjacent > sphere.radius ? FALSE : TRUE);
}


t_bool		intersect_sphere(t_ray ray, t_sphere* obj, t_intersect *inter)
{
	return (sphere_crossroad(ray, *obj, inter));
}

t_sphere		*new_sphere(t_vector3 pos, unsigned int radius)
{
	t_sphere		*newsphere;

	newsphere = malloc(sizeof(t_sphere));
	newsphere->type = SPHERE;
	newsphere->pos = (t_vertex3) {.x = pos.x, .y = pos.y, .z = pos.z};
	newsphere->radius = radius;
	return (newsphere);
}
