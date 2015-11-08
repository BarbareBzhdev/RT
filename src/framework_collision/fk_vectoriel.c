/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectoriel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/31 22:36:16 by mbarbari          #+#    #+#             */
/*   Updated: 2015/11/03 18:01:59 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework/fk_vectoriel.h"
#include "framework/fk_math.h"
#include <math.h>

t_vector3		vector_reverse(t_vector3 u)
{
	return ((t_vector3) {.x = -u.x, .y = -u.y, .z = -u.z});
}

int				vector_dotproduct(t_vector3 u, t_vector3 v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}

unsigned int	vector_magnitude(t_vector3 u)
{
	return (sqrt(SQUARE(u.x) + SQUARE(u.y) + SQUARE(u.z)));
}
