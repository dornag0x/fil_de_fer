/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 00:44:35 by hfeufeu           #+#    #+#             */
/*   Updated: 2024/11/09 00:51:04 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	parse(char *file_name)
{
	int		i;
	int		fd;
	int		bytes;
	char	*buffer;

	i = 0;
	buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	fd = open(file_name, O_RDWR);
	bytes = read(fd, buffer, BUFFER_SIZE);
		
}
