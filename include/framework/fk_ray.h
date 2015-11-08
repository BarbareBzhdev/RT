/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_ray.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblabla <robinlambertz+dev@gmail.c>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 13:20:23 by roblabla          #+#    #+#             */
/*   Updated: 2015/11/03 13:21:15 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FK_RAY_H
# define FK_RAY_H

#include "framework/fk_vertexiel.h"
#include "framework/fk_vectoriel.h"

typedef struct		s_ray t_ray;

struct				s_ray
{
	t_vertex3		pos;
	t_vector3		dir;
};

#endif
