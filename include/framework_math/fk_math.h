/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 21:18:55 by mbarbari          #+#    #+#             */
/*   Updated: 2016/03/31 11:52:19 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FK_MATH_H
# define FK_MATH_H

# include <math.h>
# include <float.h>

# ifndef PI
#  define PI M_PI
# endif

# ifndef FLT_MAX
#  define FLT_MAX 3.40282347e+38F
# endif

# define SQUARE(x) ((x) * (x))
# define DPI (PI - (PI / 2))
# define RAD_TO_DEGREES(X) (((X) * 180) / PI)
# define ABS(X) (X) < 0 ? -(X) : (X)

float	fk_isqrt(float nbr);

#endif
