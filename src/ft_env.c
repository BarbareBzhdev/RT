/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/01 21:12:58 by mbarbari          #+#    #+#             */
/*   Updated: 2016/02/17 10:07:18 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_env.h"
#include "framework_shape/fk_listobj.h"
#include "framework_light/fk_normal.h"
#include "framework_light/fk_normal_plane.h"
#include "framework_light/fk_normal_sphere.h"
#include "framework_light/fk_normal_cylinder.h"
#include "framework_light/fk_normal_cone.h"

void		ft_setup_inter(t_fctinter inter[DEFAULT])
{
	inter[SPHERE] = (t_fctinter)&intersect_sphere;
	inter[PLANE] = (t_fctinter)&intersect_plane;
	inter[CYLINDER] = (t_fctinter)&intersect_cylinder;
	inter[CONE] = (t_fctinter)&intersect_cone;
	inter[DEFAULT] = NULL;
}

void		ft_setup_normal(t_fctnormal normal[DEFAULT])
{
	normal[SPHERE] = (t_fctnormal)&normal_sphere;
	normal[PLANE] = (t_fctnormal)&normal_plane;
	normal[CYLINDER] = (t_fctnormal)&normal_cylinder;
	normal[CONE] = (t_fctnormal)&normal_cone;
	normal[DEFAULT] = NULL;
}
