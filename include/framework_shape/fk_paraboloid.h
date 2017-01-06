/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_paraboloid.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 21:31:00 by yderosie          #+#    #+#             */
/*   Updated: 2016/03/31 12:12:07 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FK_PARABOLOID_H
# define FK_PARABOLOID_H

# include "libft.h"
# include "parser/parser.h"
# include "framework_shape/fk_type.h"
# include "framework_shape/fk_ray.h"
# include "framework_collision/fk_intersect.h"
# include "framework_math/fk_vector.h"

typedef struct s_paraboloid	t_paraboloid;
struct				s_paraboloid
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
	float			height;
};

t_bool				intersect_paraboloid(t_ray ray, t_paraboloid *obj,
	float *dist);
void				new_paraboloid(t_value val, t_object *obj);

#endif
