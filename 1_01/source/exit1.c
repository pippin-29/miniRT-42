/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:05:04 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/18 18:42:06 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_v8	exit_program(t_program *program)
{
	free_program(program);
	exit(0);
}