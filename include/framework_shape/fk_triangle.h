/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_triangle.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 00:12:29 by yderosie          #+#    #+#             */
/*   Updated: 2016/03/31 12:12:20 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FK_TRIANGLE_H
# define FK_TRIANGLE_H

# include "libft.h"
# include "parser/parser.h"
# include "framework_shape/fk_type.h"
# include "framework_shape/fk_ray.h"
# include "framework_collision/fk_intersect.h"
# include "framework_math/fk_vector.h"

typedef struct s_triangle	t_triangle;
struct				s_triangle
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
	t_vertex3		pos2;
	t_vertex3		pos3;
};

typedef struct s_tri	t_tri;
struct				s_tri
{
	t_vector3		e1;
	t_vector3		e2;
	t_vector3		p;
	t_vector3		t;
	t_vector3		q;
	float			u;
	float			det;
	float			v;
};

t_bool				intersect_triangle(t_ray ray, t_triangle *obj, float *dist);
void				new_triangle(t_value val, t_object *obj);

#endif
