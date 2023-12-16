/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:43:51 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/17 08:44:47 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

float	load_brightness_ratio(char *line, t_program *p)
{
	float	out;
	char 	*temp;
	int		q;

	q = 0;
	temp = malloc(sizeof(char) * 32);
	while (line[p->i])
	{
		while(line[p->i] == ' ' || line[p->i] == '	')
			p->i++;
		printf("lbr line[%d] = %c\n", p->i, line[p->i]);
		if (!ft_isdigit(line[p->i]) && line[p->i] != '.')
			error_parse("Brightness Ratio ( Input NAN )");
		temp[q++] = line[p->i++];
		if (line[p->i] == ' ' || line[p->i] == '	')
			break ;
	}
	out = atof(temp);
	printf("lbr = %f\n", out);
	if (out < 0.0 || out > 1.0)
		error_parse("Brightness Ratio Range ( 0.0 - 1.0 )");
	free(temp);
	return (out);
}

float	*load_normal_vector(char *line, t_program *p)
{
	float	*out;
	char	*temp;
	int		q;
	int		l;

	q = 0;
	l = 0;
	out = malloc(sizeof(float) * 3);
	temp = malloc(sizeof(char) * 32);
	while (line[p->i])
	{
		q = 0;
		while (line[p->i] != ',' || line[p->i] != ' ')
		{
			if (!ft_isdigit(line[p->i]) || line[p->i] != '.')
				error_parse("Normallized Vector ( Input NAN )");
			temp[q] = line[p->i];
			q++;
			p->i++;
		}
		out[l] = atof(temp);
		if (out[l] < 0.0 || out[l] > 1.0)
			error_parse("Normallized Vector Range ( 0.0 - 1.0 )");
		l++;
	}
	if (l != 3)
		error_parse("Normalized Vector Coordinate Count Invalid ( 0.0,0.0,0.0 )");
	free(temp);
	return (out);
}

float	load_dimension(char *line, t_program *p)
{
	float	out;
	char 	*temp;

	temp = malloc(sizeof(char) * 32);
	while (line[p->i] || line[p->i] != ' ')
	{
		if (!ft_isdigit(line[p->i]) || line[p->i] != '.')
			error_parse("Dimension ( Input NAN )");
		temp[p->i] = line[p->i];
		p->i++;
	}
	out = atof(temp);
	free(temp);
	return (out);
}

float	*load_coordinates(char *line, t_program *p)
{
	float	*out;
	char	*temp;
	int		q;
	int		l;

	q = 0;
	l = 0;
	out = malloc(sizeof(float) * 3);
	temp = malloc(sizeof(char) * 32);
	while (line[p->i])
	{
		q = 0;
		while (line[p->i] != ',' || line[p->i] != ' ')
		{
			if (!ft_isdigit(line[p->i]) || line[p->i] != '.')
				error_parse("Coordinates ( Input NAN )");
			temp[q] = line[p->i];
			q++;
			p->i++;
		}
		out[l] = atof(temp);
		l++;
	}
	if (l != 3)
		error_parse("Coordinate value count invalid ( 0.0,0.0,0.0 )");
	free(temp);
	return (out);
}

t_u32	*load_rgb_values(char *line, t_program *p)
{
	char	*temp;
	t_u32	*out;
	int		q;
	int		l;

	l = 0;
	q = 0;
	temp = malloc(sizeof(char) * 4);
	out = malloc(sizeof(t_u32) * 3);
	while (line[p->i])
	{
		
		while(line[p->i] == ' ' || line[p->i] == '	')
			p->i++;
		if (!ft_isdigit(line[p->i]))
			error_parse("RGB ( Input NAN )");
		printf("lrgbv line[%d] = %c\n", p->i, line[p->i]);
		temp[q++] = line[p->i++];
		if (line[p->i] == ',' || q == 3)
		{
			temp[q] = '\0';
			printf("temp_string = %s\n", temp);
			out[l] = ft_atoi(temp);
			printf("out[%d] = %u\n", l, out[l]);
			l++;
			p->i++;
			q = 0;
		}
		if (line[p->i] == ' ' || line[p->i] == '	' || (line[p->i] == ',' && l == 3))
			break ;
	}
	if (l != 3)
		error_parse("RGB Value Count Invalid ( 0,0,0 )");
	free(temp);
	return (out);
}
