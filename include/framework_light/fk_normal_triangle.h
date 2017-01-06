/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_normal_triangle.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 00:11:59 by yderosie          #+#    #+#             */
/*   Updated: 2016/03/31 00:12:00 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FK_NORMAL_TRIANGLE_H
# define FK_NORMAL_TRIANGLE_H

# include "framework_math/fk_vector.h"
# include "framework_shape/fk_triangle.h"
# include "framework_collision/fk_intersect.h"

void		normal_triangle(t_intersect *inter, t_triangle *obj);

#endif
