/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare <barbare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 12:48:34 by mbarbari          #+#    #+#             */
/*   Updated: 2016/04/01 17:29:30 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FK_VECTOR_H
# define FK_VECTOR_H

# include "stuff.t"

typedef union u_vec	t_vec;
typedef t_vec	t_vector3;
typedef t_vec	t_vertex3;
typedef t_vec	t_color3;

union			u_vec
{
	struct		s_noop
	{
		float x;
		float y;
		float z;
	}			noop;
	struct		s_noop
	{
		float r;
		float g;
		float b;
	}			noop;
};

/*
** ****************************************************************************
** fk_vectoriel_transformation.c
** ****************************************************************************
*/
int				vector_check(t_vector3 v, t_vector3 u);
t_vector3		vector_new(float x1, float y1, float z1);
t_vector3		vector_cpy(t_vector3 u);
t_vector3		vector_unit(t_vector3 u);
t_vertex3		vector_translation(t_vector3 u, t_vertex3 v);
t_vector3		vector_mul(t_vector3 u, float r);
t_vector3		vector_div(t_vector3 u, float r);

t_vector3		vector_add(t_vector3 u, float r);
t_vector3		vector_sub(t_vector3 u, float r);
t_vector3		vector_div(t_vector3 u, float r);
t_vector3		vector_mul(t_vector3 u, float f);

/*
** ****************************************************************************
** fk_vectoriel_math.c
** ****************************************************************************
*/
t_vector3		vector_substract(t_vector3 u, t_vector3 v);
t_vector3		vector_product(t_vector3 u, t_vector3 v);
t_vector3		vector_sum(t_vector3 u, t_vector3 v);

/*
** ****************************************************************************
** fk_vectoriel.c
** ****************************************************************************
*/
t_vector3		vector_reverse(t_vector3 u);
float			vector_dotproduct(t_vector3 u, t_vector3 v);
float			vector_magnitude(t_vector3 u);

/*
** ****************************************************************************
** fk_color.c
** ****************************************************************************
*/
t_color3		color_new(float x1, float y1, float z1);

#endif
