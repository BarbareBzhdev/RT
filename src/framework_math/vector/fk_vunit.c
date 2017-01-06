/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_unit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 18:50:30 by mbarbari          #+#    #+#             */
/*   Updated: 2015/12/07 18:50:51 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_math/fk_vector.h"

t_vector3		vector_unit(t_vector3 u)
{
	t_vector3		unitvector;

	if (u.x == 0 && u.y == 0 && u.z == 0)
	{
		unitvector.x = 0;
		unitvector.y = 0;
		unitvector.z = 0;
		return (unitvector);
	}
	unitvector.x = u.x / vector_magnitude(u);
	unitvector.y = u.y / vector_magnitude(u);
	unitvector.z = u.z / vector_magnitude(u);
	return (unitvector);
}
