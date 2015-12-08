/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_objects.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 12:32:17 by mbarbari          #+#    #+#             */
/*   Updated: 2015/12/08 11:41:03 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FK_OBJECTS_H
# define FK_OBJECTS_H

#include "framework_shape/fk_type.h"
#include "framework_rgb/fk_rgb.h"

typedef struct		s_object t_object;
typedef struct		s_material t_material;

struct				s_object
{
	t_type			type;
	t_rgba			color;
	char			stuff[128];
};

#include "framework_shape/fk_sphere.h"
#include "framework_shape/fk_plan.h"
#include "framework_collision/fk_collision.h"

typedef float		*(*t_fctinter)(t_ray ray, void *obj, t_intersect *inter);

struct				s_material
{
	char			*tile;
};

struct				s_cone
{
	t_type			type;
	t_material		material;
	t_vertex3		position;
	t_vector3		height;
	float			radius;
};

t_bool			intersect_sphere(t_ray ray, t_sphere* obj, t_intersect *inter);

#endif
