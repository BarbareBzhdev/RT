/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 18:07:51 by mbarbari          #+#    #+#             */
/*   Updated: 2015/12/08 13:39:05 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_math/fk_math.h"

float	fk_isqrt(float nbr)
{
	long				i;
	float				x1;
	float				y;

	x1 = nbr * 0.5F;
	y = nbr;
	i = *(long *)&y;
	i = 0x5f375a86 - (i >> 1);
	y = *(float *)&i;
	y = y * (1.5F - (x1 * y * y));
	return (y);
}
