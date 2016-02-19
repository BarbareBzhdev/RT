/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_light.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 18:32:26 by mbarbari          #+#    #+#             */
/*   Updated: 2016/02/17 10:14:05 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FK_LIGHT_H
# define FK_LIGHT_H

# include "parser.h"
# include "framework_shape/fk_type.h"
# include "framework_math/fk_vector.h"
# include "framework_collision/fk_collision.h"

typedef struct s_spotlight		t_spotlight;
struct				s_spotlight
{
	t_type			type;
	t_color3		color;
	float			reflection_index;
	float			diffuse;
	float			refraction;
	float			refraction_index;
	t_vertex3		pos;
	t_vector3		dir;
	float			intensity;
};

t_color3				iter_light(t_intersect inter, t_spotlight *light);
void					new_spotlight(t_value val, t_object *obj);
#endif
