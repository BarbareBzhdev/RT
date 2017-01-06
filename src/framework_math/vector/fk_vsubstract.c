/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_vector_substract.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 18:42:25 by mbarbari          #+#    #+#             */
/*   Updated: 2015/12/07 18:42:42 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_math/fk_vector.h"

t_vector3		vector_substract(t_vector3 u, t_vector3 v)
{
	return ((t_vector3) {.x = u.x - v.x, .y = u.y - v.y, .z = u.z - v.z});
}
