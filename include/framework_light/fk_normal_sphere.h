/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_normal_sphere.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 21:44:39 by mbarbari          #+#    #+#             */
/*   Updated: 2016/02/01 11:18:02 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FK_NORMAL_SPHERE_H
# define FK_NORMAL_SPHERE_H

# include "framework_math/fk_vector.h"
# include "framework_shape/fk_sphere.h"
# include "framework_collision/fk_intersect.h"

void		normal_sphere(t_intersect *inter, t_sphere *obj);

#endif
