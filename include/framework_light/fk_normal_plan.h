/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_normal_plan.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 20:02:06 by mbarbari          #+#    #+#             */
/*   Updated: 2016/02/01 11:18:17 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FK_NORMAL_PLAN_H
# define FK_NORMAL_PLAN_H

# include "framework_math/fk_vector.h"
# include "framework_shape/fk_plan.h"
# include "framework_collision/fk_intersect.h"

void		normal_plan(t_intersect *inter, t_plan *obj);

#endif
