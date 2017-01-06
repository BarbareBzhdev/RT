/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_texture.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 12:04:33 by root              #+#    #+#             */
/*   Updated: 2016/03/23 13:49:09 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FK_TEXTURE_H
# define FK_TEXTURE_H

# include "framework_collision/fk_collision.h"
# include "framework_math/fk_vector.h"
# include "framework_shape/fk_ray.h"
# include "ft_env.h"

typedef struct	s_perlin
{
	int			a;
	int			b;
	int			aa;
	int			ab;
	int			ba;
	int			bb;
	t_vertex3	xyz;
	int			xx;
	int			yy;
	int			zz;
	float		u;
	float		v;
	float		w;
}				t_perlin;

t_color3		fk_perlin(t_intersect inter);
t_color3		fk_checkerboard(t_intersect inter);
float			perlin_noise(float x, float y, float z);

#endif
