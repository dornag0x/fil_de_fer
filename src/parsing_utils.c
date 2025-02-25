/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <hfeufeu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:53:07 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/02/25 14:24:14 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void	process_newline(int *count, int *current_row, t_points *points)
{
	(*count)++;
	if (points->rows == 0)
		points->rows = *current_row;
	*current_row = 0;
}

static void	process_number(size_t *i, int *current_row, size_t size, char *str)
{
	(*current_row)++;
	while (*i < size && str[*i] != ' ' && str[*i] != '\n' && str[*i] != ',')
		(*i)++;
	if (*i < size && str[*i] == ',')
		while (*i < size && str[*i] != ' ' && str[*i] != '\n')
			(*i)++;
}

static void	count_rows_and_elements(char *str, size_t size, t_points *points,
		int *current_row)
{
	size_t	i;
	int		count;
	int		elem;

	i = 0;
	count = 0;
	elem = 0;
	*current_row = 0;
	while (i < size)
	{
		while (i < size && str[i] == ' ')
			i++;
		if (i < size && (str[i] == '-' || (str[i] >= '0' && str[i] <= '9')))
		{
			process_number(&i, current_row, size, str);
			elem++;
		}
		if (i < size && str[i] == '\n')
			process_newline(&count, current_row, points);
		if (i < size)
			i++;
	}
	points->cols = count;
	points->size = elem;
}

void	get_dimensions(char *str, size_t size, t_points *points)
{
	int	current_row;

	count_rows_and_elements(str, size, points, &current_row);
	if (current_row > 0)
		points->cols++;
}
