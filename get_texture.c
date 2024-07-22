/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasamad <rasamad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 17:26:49 by rasamad           #+#    #+#             */
/*   Updated: 2024/07/22 19:16:59 by rasamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_get_no(t_data *data, char *gnl)
{
	int	i;

	i = 0;
	if (gnl[0] == 'N' && gnl[1] == 'O' && gnl[2] == ' ')
	{
		while(gnl[i] && gnl[i] != '.')
			i++;
		if (data->textures[0].path)
			return (printf("Error\nDoublon texture\n"), -2);
		data->textures[0].path = ft_strdup_cub(gnl + i, 2);
		if (!data->textures[0].path)
			return (printf("Error\nMalloc failed\n"), -1);
		data->nb_param = data->nb_param + 1;
	}
	return (0);
}

int	ft_get_so(t_data *data, char *gnl)
{
	int	i;

	i = 0;
    if (gnl[0] == 'S' && gnl[1] == 'O' && gnl[2] == ' ')
	{
		while(gnl[i] && gnl[i] != '.')
			i++;
		if (data->textures[1].path)
			return (printf("Error\nDoublon texture\n"), -2);
		data->textures[1].path = ft_strdup_cub(gnl + i, 2);
		if (!data->textures[1].path)
			return (printf("Error\nMalloc failed\n"), -1);
		data->nb_param = data->nb_param + 1;
	}
	return (0);
}

int	ft_get_we(t_data *data, char *gnl)
{
	int	i;

	i = 0;
	if (gnl[0] == 'W' && gnl[1] == 'E' && gnl[2] == ' ')
	{
		while(gnl[i] && gnl[i] != '.')
			i++;
		if (data->textures[2].path)
			return (printf("Error\nDoublon texture\n"), -2);
		data->textures[2].path = ft_strdup_cub(gnl + i, 2);
		if (!data->textures[2].path)
			return (printf("Error\nMalloc failed\n"), -1);
		data->nb_param = data->nb_param + 1;
	}
	return (0);
}

int	ft_get_ea(t_data *data, char *gnl)
{
	int	i;

	i = 0;
	if (gnl[0] == 'E' && gnl[1] == 'A' && gnl[2] == ' ')
	{
		while(gnl[i] && gnl[i] != '.')
			i++;
		if (data->textures[3].path)
			return (printf("Error\nDoublon texture\n"), -2);
		data->textures[3].path = ft_strdup_cub(gnl + i, 2);
		if (!data->textures[3].path)
			return (printf("Error\nMalloc failed\n"), -1);
		data->nb_param = data->nb_param + 1;
	}
	return (0);
}

//return data->nb_param of texture or -1 for malloc error strdup or doublon
int	ft_get_texture(t_data *data)
{
	char	*gnl;

	data->nb_param = 0;
	gnl = get_next_line(data->fd);
	while (gnl && data->nb_param < 6)
	{
		printf("%s", gnl);
		int tmp_count = data->nb_param;//	2
		if (ft_get_no(data, gnl) != 0 || ft_get_so(data, gnl) != 0)
			return (-1);
		if (ft_get_we(data, gnl) != 0 || ft_get_ea(data, gnl) != 0)
			return (-1);
		if (ft_getF_color(data, gnl) == -1)
			return (-1);
		if (ft_getC_color(data, gnl) == -1)
			return (-1);
		if (tmp_count == data->nb_param && gnl[0] != '\n')
			return(printf("Error\nInvalid charatere in .cub\n"), -1);
		gnl = get_next_line(data->fd);
	}
	if (data->nb_param < 6)
		printf("Error\nAll texture not find\n");
	return (data->nb_param);
}