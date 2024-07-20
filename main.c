/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasamad <rasamad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:10:56 by rasamad           #+#    #+#             */
/*   Updated: 2024/07/20 17:52:52 by rasamad          ###   ########.fr       */
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

int ft_check_arg(char *arg_map)
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
	return (0);
}

char	*ft_strdup(char *str, int choice)
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

int	ft_get_no_so(t_data *data, char *gnl, int *p_count)
{
	int	i;

	i = 0;
	if (gnl[0] == 'N' && gnl[1] == 'O' && gnl[2] == ' ')
	{
		while(gnl[i] && gnl[i] != '.')
			i++;
		if (data->textures[0].path)
			return (printf("Error\nDoublon texture\n"), -2);
		data->textures[0].path = ft_strdup(gnl + i, 2);
		if (!data->textures[0].path)
			return (printf("Error\nMalloc failed\n"), -1);
		*p_count = *p_count + 1;
	}
	else if (gnl[0] == 'S' && gnl[1] == 'O' && gnl[2] == ' ')
	{
		while(gnl[i] && gnl[i] != '.')
			i++;
		if (data->textures[1].path)
			return (printf("Error\nDoublon texture\n"), -2);
		data->textures[1].path = ft_strdup(gnl + i, 2);
		if (!data->textures[1].path)
			return (printf("Error\nMalloc failed\n"), -1);
		*p_count = *p_count + 1;
	}
	return (0);
}

int	ft_get_we_ea(t_data *data, char *gnl, int *p_count)
{
	int	i;

	i = 0;
	if (gnl[0] == 'W' && gnl[1] == 'E' && gnl[2] == ' ')
	{
		while(gnl[i] && gnl[i] != '.')
			i++;
		if (data->textures[2].path)
			return (printf("Error\nDoublon texture\n"), -2);
		data->textures[2].path = ft_strdup(gnl + i, 2);
		if (!data->textures[2].path)
			return (printf("Error\nMalloc failed\n"), -1);
		*p_count = *p_count + 1;
	}
	else if (gnl[0] == 'E' && gnl[1] == 'A' && gnl[2] == ' ')
	{
		while(gnl[i] && gnl[i] != '.')
			i++;
		if (data->textures[3].path)
			return (printf("Error\nDoublon texture\n"), -2);
		data->textures[3].path = ft_strdup(gnl + i, 2);
		if (!data->textures[3].path)
			return (printf("Error\nMalloc failed\n"), -1);
		*p_count = *p_count + 1;
	}
	return (0);
}

/*
int	ft_get_colorfc(t_data *data, char *gnl, int *p_count)
{
	int	i;
	char	*r;
	i = 0;
	if (gnl[0] == 'F' && gnl[1] == ' ')
	{
		while(!(gnl[i] >= '0' && gnl[i] <= '9'))
			i++;
		r = ft_strdup(gnl + i, 3);
		if (!data->textures[2].path)
			return (-1);
		*p_count = *p_count + 1;
	}
	else if (gnl[0] == 'C' && gnl[1] == ' ')
	{
		while(gnl[i] && gnl[i] != '.')
			i++;
		data->textures[3].path = ft_strdup(gnl + i, 2);
		if (!data->textures[3].path)
			return (-1);
		*p_count = *p_count + 1;
	}
	return (0);
}*/

//
//return count of texture or -1 for malloc error strdup or doublon
int	ft_get_texture(t_data *data)
{
	char	*gnl;
	int		count;

	data->textures[0].path = NULL;
	data->textures[1].path = NULL;
	data->textures[2].path = NULL;
	data->textures[3].path = NULL;
	count = 0;
	gnl = get_next_line(data->fd);
	while (gnl)
	{
		printf("gnl = %s", gnl);
		if (ft_get_no_so(data, gnl, &count) != 0)
			return (-1);
		if (ft_get_we_ea(data, gnl, &count) != 0)
			return (printf("Error\nMalloc failed\n"), -1);
		//if (ft_get_colorfc(data, gnl, &count) == -1)return (-1);
		if (count >= 6)
		{
			//cpy map
		}
		gnl = get_next_line(data->fd);
	}
	if (count < 4)
		printf("Error\nAll texture not find\n");
	return (count);
}

int main(int ac, char **av)
{
	t_data	data;
	if (ac != 2)
		return (printf("Error\nNombre d'arguments incorrect\n"), 0);
	if (ft_check_arg(av[1]) == 1)
		return (printf("Error\nLe fichier de description de scène doit avoir pour extension .cub\n"), 0);
	data.fd = open(av[1], O_RDONLY);
	if (data.fd == -1)
		return (printf("Error\nOpen failed\n"), 0);
	int get_texture = ft_get_texture(&data);
	if (get_texture < 4)
		return (-1);
	printf("path NO = %s\n", data.textures[0].path);
	printf("path SO = %s\n", data.textures[1].path);
	printf("path WE = %s\n", data.textures[2].path);
	printf("path EA = %s\n", data.textures[3].path);
	
	/*go open le .cub puis gnl le fd,
	puis en fonction de la 1er lettre N S W E C ou F, 
	stock le dans un char * dans la structure,
	puis stock le reste dans char **map,
	une fois fait, verif ce que ta stocker
*/
	return (0);
}