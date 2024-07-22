/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasamad <rasamad@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:13:59 by rasamad           #+#    #+#             */
/*   Updated: 2024/04/11 15:10:42 by rasamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
int main()
{
	char str[] = "ABCD";
	int i = 1;
	while (str[i] != '\0')
	{
		printf("%c", ft_tolower(str[i]));
		i++;
	}
	
}