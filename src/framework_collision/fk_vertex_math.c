/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_vertex_math.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/01 19:21:55 by mbarbari          #+#    #+#             */
/*   Updated: 2015/11/02 14:15:11 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework/fk_vertexiel.h"
#include "framework/fk_math.h"

unsigned int		lenght_segment(t_vertex3 u, t_vertex3 v)
{
	return (sqrt(SQUARE(u.x - v.x) + SQUARE(u.y - v.y)  + SQUARE(u.z - v.z) ));
}

t_vertex3			vertex_sum(t_vertex3 u, unsigned int l)
{
	return ((t_vertex3) {.x = u.x + l, .y = u.y + l, .z = u.z + l});
}

t_vertex3		vertex_new(float x1, float y1, float z1)
{
	return ((t_vertex3) {.x = x1, .y = y1, .z = z1});
}
