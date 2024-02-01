/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khallal <khallal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:11:06 by khallal           #+#    #+#             */
/*   Updated: 2023/01/04 18:45:45 by khallal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_arg(int a)
{
	if (a != 2)
	{
		write(2, "Error\nther are not enough arg", 29);
		exit(1);
	}
}

void	check_fd(int i)
{
	if (i == -1)
	{
		write(1, "Error\nmap not exit", 19);
		exit(0);
	}
}

int	check_map_name(char *p)
{
	int	i;

	i = 0;
	while (p[i])
		i++;
	i--;
	if (i == 3 || p[i] != 'r' || p[i - 1] != 'e' || p[i - 2] != 'b'
		|| p[i - 3] != '.')
	{
		write(1, "Error\nname map not correct", 26);
		exit(0);
	}
	return (1);
}

void	empty_map(char k)
{
	if (k == '\0' || k == '\0')
	{
		write(1, "Error\nempty map or line 1 = new line", 37);
		exit(0);
	}
}

int	empty_line(char *k)
{
	int	x;

	x = 0;
	while (k[x])
	{
		if (k[x] == '\n' && (k[x + 1] == '\n' || k[x + 1] == '\0'))
		{
			write(1, "Error\nline khawi asat", 16);
			exit(0);
		}
		x++;
	}
	return (1);
}
