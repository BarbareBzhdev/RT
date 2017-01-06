/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_normal_cone.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 14:29:23 by yderosie          #+#    #+#             */
/*   Updated: 2016/02/01 11:18:31 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FK_NORMAL_CONE_H
# define FK_NORMAL_CONE_H

# include "framework_math/fk_vector.h"
# include "framework_shape/fk_cone.h"
# include "framework_collision/fk_intersect.h"

void		normal_cone(t_intersect *inter, t_cone *obj);

#endif
