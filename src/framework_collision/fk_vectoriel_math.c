/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectoriel_math.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/31 22:37:32 by mbarbari          #+#    #+#             */
/*   Updated: 2015/11/06 21:25:53 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework/fk_vectoriel.h"

t_vector3		vector_sum(t_vector3 u, t_vector3 v)
{
	return ((t_vector3) { .x = u.x + v.x, .y = u.y + v.y, .z = u.z + v.z });
}

t_vector3		vector_substract(t_vector3 u, t_vector3 v)
{
	return ((t_vector3) {.x = u.x - v.x, .y = u.y - v.y, .z = u.z - v.z});
}

t_vector3		vector_product(t_vector3 u, t_vector3 v)
{
	return ((t_vector3) {	.x = (u.y * v.z) - (u.z * v.y),
							.y = (u.z * v.x) - (u.x * v.z),
							.z = (u.x * v.y) - (u.y * v.x)});
}
