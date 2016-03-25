/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_material.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 14:17:10 by root              #+#    #+#             */
/*   Updated: 2016/03/23 14:17:54 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework_math/fk_vector.h"
#include "framework_shape/fk_objects.h"

t_material		material_new(t_color3 c1, t_color3 c2, t_color3 c3, char *t)
{
	return ((t_material) {c1, c2, c3, t});
}
