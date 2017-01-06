/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_ray.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblabla <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 13:20:23 by roblabla          #+#    #+#             */
/*   Updated: 2015/12/17 17:48:41 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FK_RAY_H
# define FK_RAY_H

# include "framework_math/fk_vector.h"

typedef struct s_ray	t_ray;

struct				s_ray
{
	t_vertex3		pos;
	t_vector3		dir;
	unsigned int	refracted;
};

#endif
