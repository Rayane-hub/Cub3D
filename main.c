/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasamad <rasamad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:10:56 by rasamad           #+#    #+#             */
/*   Updated: 2024/07/22 19:38:17 by rasamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_get_map(t_data *data)
{
	char	*gnl;

	printf("map : \n");
	gnl = get_next_line(data->fd);
	while (gnl)
	{
		printf("%s", gnl);
		gnl = get_next_line(data->fd);
		
	}
	return (0);
}

int main(int ac, char **av)
{
	t_data	data;
	if (ac != 2)
		return (printf("Error\nNombre d'arguments incorrect\n"), 0);
	if (ft_check_arg(&data, av[1]) == 1)
		return (printf("Error\nLe fichier de description de scène doit avoir pour extension .cub\n"), 0);
	data.fd = open(av[1], O_RDONLY);
	if (data.fd == -1)
		return (printf("Error\nOpen failed\n"), 0);
	if (ft_get_texture(&data) < 6)
		return (-1);
	if (ft_get_map(&data) != 0)
		return (-1);
		
	/*printf("path NO = %s\n", data.textures[0].path);
	printf("path SO = %s\n", data.textures[1].path);
	printf("path WE = %s\n", data.textures[2].path);
	printf("path EA = %s\n", data.textures[3].path);
	printf("F\tR = |%d|\tG = |%d|\tB = |%d|\n", data.floor.r, data.floor.g, data.floor.b);
	printf("F\tR = |%d|\tG = |%d|\tB = |%d|\n", data.sky.r, data.sky.g, data.sky.b);*/

	/*go open le .cub puis gnl le fd,
	puis en fonction de la 1er lettre N S W E C ou F, 
	stock le dans un char * dans la structure,
	puis stock le reste dans char **map,
	une fois fait, verif ce que ta stocker
*/
	return (0);
}
