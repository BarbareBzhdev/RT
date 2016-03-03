/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_cylinder.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 16:40:50 by mbarbari          #+#    #+#             */
/*   Updated: 2016/02/24 16:04:44 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CYLINDER_H
# define FT_CYLINDER_H

# include "libft.h"
# include "parser.h"
# include "framework_shape/fk_type.h"
# include "framework_shape/fk_ray.h"
# include "framework_collision/fk_intersect.h"
# include "framework_math/fk_vector.h"


typedef struct		s_cylinder t_cylinder;
struct				s_cylinder
{
	t_type			type;
	t_color3		color;
	float			reflection_index;
	float			diffuse;
	t_bool			light;
	float			refraction;
	float			refraction_index;
	t_vertex3		pos;
	t_vector3		dir;
	float			radius;
};

t_bool			intersect_cylinder(t_ray ray, t_cylinder* obj, float *dist);
void			new_cylinder(t_value val, t_object *obj);

#endif
