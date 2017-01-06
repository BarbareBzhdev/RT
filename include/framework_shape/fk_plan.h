/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_plan.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 20:42:15 by mbarbari          #+#    #+#             */
/*   Updated: 2016/03/31 12:11:50 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FK_PLAN_H
# define FK_PLAN_H

# include "libft.h"
# include "parser/parser.h"
# include "framework_shape/fk_type.h"
# include "framework_math/fk_vector.h"
# include "framework_shape/fk_ray.h"
# include "framework_shape/fk_objects.h"

typedef struct s_plan	t_plan;
struct				s_plan
{
	t_type			type;
	t_material		mat;
	float			reflection_index;
	float			refraction_index;
	float			ambient;
	float			diffuse;
	float			specular;
	t_bool			light;
	t_vertex3		pos;
	t_vector3		dir;
};

t_bool				intersect_plan(t_ray ray, t_plan *obj, float *t);
void				new_plane(t_value val, t_object *obj);

#endif
