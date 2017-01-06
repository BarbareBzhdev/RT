/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_intersect.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 20:42:51 by mbarbari          #+#    #+#             */
/*   Updated: 2016/03/25 13:59:18 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FK_INTERSECT_H
# define FK_INTERSECT_H

# include "framework_math/fk_vector.h"
# include "framework_shape/fk_objects.h"
# include "framework_shape/fk_ray.h"

typedef struct s_intersect	t_intersect;

struct				s_intersect
{
	int				water;
	t_vertex3		pos;
	t_vector3		v_normal;
	t_object		*obj;
	t_ray			ray;
	t_color3		color;
};

typedef unsigned int	(*t_fctinter)(t_ray ray, void *obj, float *t);

t_vector3			create_intersect(t_ray ray, float dist);

#endif
