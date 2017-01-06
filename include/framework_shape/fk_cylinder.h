/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_cylinder.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 16:40:50 by mbarbari          #+#    #+#             */
/*   Updated: 2016/03/31 12:13:24 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FK_CYLINDER_H
# define FK_CYLINDER_H

# include "libft.h"
# include "parser/parser.h"
# include "framework_shape/fk_type.h"
# include "framework_shape/fk_ray.h"
# include "framework_collision/fk_intersect.h"
# include "framework_math/fk_vector.h"

typedef struct s_cylinder	t_cylinder;
struct				s_cylinder
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
	float			radius;
};

t_bool				intersect_cylinder(t_ray ray, t_cylinder *obj, float *dist);
void				new_cylinder(t_value val, t_object *obj);

#endif
