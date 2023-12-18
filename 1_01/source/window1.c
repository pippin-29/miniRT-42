/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:42:25 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/18 11:47:10 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	*create_window(char *title, t_program *program)
{
	void	*out;

	out = mlx_new_window(program->view->mlx, program->view->resolution[X],
			program->view->resolution[Y], title);
	return (out);
}