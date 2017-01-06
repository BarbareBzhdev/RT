/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_vcolor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare <barbare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 11:33:40 by barbare           #+#    #+#             */
/*   Updated: 2016/03/23 14:16:32 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_math/fk_vector.h"
#include "framework_shape/fk_objects.h"

t_color3		color_new(float r, float g, float b)
{
	t_color3	color;

	color = (t_color3) {.r = (r / 255.), .g = (g / 255.), .b = (b / 255.)};
	return (color);
}
