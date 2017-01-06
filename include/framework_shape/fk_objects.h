/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_objects.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 12:32:17 by mbarbari          #+#    #+#             */
/*   Updated: 2016/03/25 15:42:24 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FK_OBJECTS_H
# define FK_OBJECTS_H

# include "libft.h"
# include "framework_shape/fk_type.h"
# include "framework_math/fk_vector.h"

typedef struct s_object	t_object;
typedef struct s_material	t_material;

struct				s_material
{
	t_color3		color1;
	t_color3		color2;
	t_color3		color3;
	char			*texture;
	float			v0;
	float			v1;
	float			v2;
};

struct				s_object
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
	char			stuff[128];
};

t_material			material_new(t_color3 c1, t_color3 c2, t_color3 c3,
	char *t);

#endif
