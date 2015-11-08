/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_vertexiel.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 21:18:55 by mbarbari          #+#    #+#             */
/*   Updated: 2015/11/02 23:29:12 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FK_VERTEXIEL_H
# define FK_VERTEXIEL_H

typedef struct	s_vertex3 t_vertex3;

struct			s_vertex3
{
	float x;
	float y;
	float z;
};

t_vertex3		vertex_new(float x1, float y1, float z1);
t_vertex3		vertex_sum(t_vertex3 u, unsigned int magnitude);
unsigned int	lenght_segment(t_vertex3 u, t_vertex3 v);

#endif
