/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <hfeufeu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:24:18 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/02/24 19:35:52 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	hooking(int key, void *mlx)
{
	if (key == 41)
		mlx_loop_end(mlx);
	return (0);
}

int	valid_step(int d)
{
	if (d < 0)
		return (-1);
	return (1);
}

char	*ft_substrc(char const *s, unsigned int start, size_t len)
{
	unsigned int	j;
	char			*des;

	j = 0;
	if (!s)
		return (NULL);
	if ((start + len) > ft_strlen(s))
		len = (ft_strlen(s) - start);
	if (start >= ft_strlen(s) || s == NULL)
		return (ft_strdup(""));
	des = malloc(sizeof(char) * (len) + 1);
	if (!des)
		return (NULL);
	while (s[start] != '\0' && j < len)
	{
		des[j] = s[start];
		j++;
		start++;
	}
	des[j] = '\0';
	return (des);
}
