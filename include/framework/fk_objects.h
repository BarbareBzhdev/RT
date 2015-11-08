/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_objects.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 12:32:17 by mbarbari          #+#    #+#             */
/*   Updated: 2015/11/03 17:58:56 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FK_OBJECTS_H
# define FK_OBJECTS_H

#include "framework/fk_type.h"

typedef struct		s_object t_object;
typedef struct		s_material t_material;

struct				s_object
{
	t_type			type;
	char			stuff[128];
};

#include "framework/fk_sphere.h"
#include "framework/fk_collision.h"

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
