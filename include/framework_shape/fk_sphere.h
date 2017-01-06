/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sphere.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 21:18:55 by mbarbari          #+#    #+#             */
/*   Updated: 2016/03/31 12:13:01 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FK_SPHERE_H
# define FK_SPHERE_H

# include "libft.h"
# include "parser/parser.h"
# include "framework_shape/fk_type.h"
# include "framework_shape/fk_ray.h"
# include "framework_collision/fk_intersect.h"
# include "framework_math/fk_vector.h"

typedef struct s_sphere	t_sphere;
struct				s_sphere
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

t_bool				intersect_sphere(t_ray ray, t_sphere *obj, float *dist);
void				new_sphere(t_value val, t_object *obj);

#endif
