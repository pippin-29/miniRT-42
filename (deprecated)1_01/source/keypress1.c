/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:58:40 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/18 20:27:28 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

t_s32	keypress(t_s32 keycode, t_v8 *param)
{
	t_program	*program;

	program = (t_program *)param;
	if (keycode == ESC_KEY)
		exit_program(program, SUCCESS);
	return (0);
}
