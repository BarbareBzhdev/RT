/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_normal_plane.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 20:02:06 by mbarbari          #+#    #+#             */
/*   Updated: 2016/02/17 10:08:05 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FK_NORMAL_PLANE_H
# define FK_NORMAL_PLANE_H

# include "framework_math/fk_vector.h"
# include "framework_shape/fk_plane.h"

t_vector3		normal_plane(t_ray ray, t_vector3 inter, t_plane *obj);

#endif
