/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:58:40 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/18 12:17:12 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int		keypress(int keycode, void *param)
{
	t_program *program;

	program = (t_program *)param;
	if (keycode == ESC_KEY)
		exit_program(program);
	return (0);
}

