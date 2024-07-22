/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasamad <rasamad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:32:15 by rasamad           #+#    #+#             */
/*   Updated: 2024/07/22 18:32:51 by rasamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int ft_strlen_cub(char *s, int choice)
{
	int i;

	i = 0;
	if (choice == 0)
		while (s[i])
			i++;
	else if (choice == 1)//end of numeric
		while (s[i] && !(s[i] >= '0' && s[i] <= '9'))
			i++;
	else if (choice == 2)//jusqua \n
		while (s[i] && s[i] != '\n')
			i++;
	return (i);
}

int ft_check_arg(t_data *data, char *arg_map)
{
	int len;

	len = ft_strlen_cub(arg_map, 0);
	if (len <= 4)
		return (1);
	if (arg_map[len - 4] != '.')
		return (1);
	if (arg_map[len - 3] != 'c')
		return (1);
	if (arg_map[len - 2] != 'u')
		return (1);
	if (arg_map[len - 1] != 'b')
		return (1);
	data->textures[0].path = NULL;
	data->textures[1].path = NULL;
	data->textures[2].path = NULL;
	data->textures[3].path = NULL;
	data->floor.check = false;
	data->sky.check = false;
	return (0);
}

char	*ft_strdup_cub(char *str, int choice)
{
	size_t	i;
	size_t	lensrc;
	char	*tmp;

	i = 0;
	lensrc = ft_strlen_cub(str, choice);
	tmp = malloc(lensrc + 1 * sizeof(char));
	if (tmp == NULL)
		return (tmp);
	while (i < lensrc)
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = 0;
	return (tmp);
}