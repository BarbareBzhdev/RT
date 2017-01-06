/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fk_type.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblabla <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/02 22:59:59 by roblabla          #+#    #+#             */
/*   Updated: 2015/11/27 22:15:27 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FK_TYPE_H
# define FK_TYPE_H

typedef enum		e_type
{
	SPHERE,
	PLANE,
	CYLINDER,
	CONE,
	PARABOLOID,
	TRIANGLE,
	DEFAULT
}					t_type;

#endif
