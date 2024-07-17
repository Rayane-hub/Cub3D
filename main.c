/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasamad <rasamad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:10:56 by rasamad           #+#    #+#             */
/*   Updated: 2024/07/17 18:23:19 by rasamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int ft_check_arg(char *arg_map)
{
	int len;

	len = ft_strlen(arg_map);
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

int main(int ac, char **av)
{
	if (ac != 2)
		return (printf("Error\nNombre d'arguments incorrect\n"), 0);
	if (ft_check_arg(av[1]) == 1)
		return (printf("Error\nLe fichier de description de scène doit avoir pour extension .cub\n"), 0);
	/*go open le .cub puis gnl le fd,
	puis en fonction de la 1er lettre N S W E C ou F, 
	stock le dans un char * dans la structure,
	puis stocke le reste dans char **map,
	une fois fait, verif ce que ta stocker
*/
	return (0);
}