/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 09:22:51 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/18 10:43:59 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minirt.h"

void	free_camera(t_program *program)
{
	if (program->camera->coord)
		free(program->camera->coord);
	if (program->camera->normal_vector)
		free(program->camera->normal_vector);
	free(program->camera);
}

void	free_light(t_program *program)
{
	if (program->light->coord)
		free(program->light->coord);
	free(program->light);
}

void	free_amb_light(t_program *program)
{
	if (program->amb_light->rgb)
		free(program->amb_light->rgb);
	free(program->amb_light);
}