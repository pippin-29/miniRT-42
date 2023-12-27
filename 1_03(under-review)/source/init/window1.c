/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:42:25 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/19 05:17:42 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_v8	*create_window(char *title, t_program *program)
{
	t_v8	*out;

	out = mlx_new_window(program->view->mlx, program->view->resolution[X],
			program->view->resolution[Y], title);
	return (out);
}
