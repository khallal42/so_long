/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khallal <khallal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:55:03 by khallal           #+#    #+#             */
/*   Updated: 2022/12/28 17:55:04 by khallal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill(t_khalifa *m, char **map, int y, int x)
{
	if (x < 0 || x >= m->lent_line || y < 0 || y >= m->n_line
		|| map[y][x] == 'E' || map[y][x] == '1')
		return ;
	map[y][x] = '1';
	fill(m, map, y - 1, x);
	fill(m, map, y + 1, x);
	fill(m, map, y, x - 1);
	fill(m, map, y, x + 1);
}

void	fille(t_khalifa *m, char **map, int y, int x)
{
	if (x < 0 || x >= m->lent_line || y < 0 || y >= m->n_line
		|| map[y][x] == '1')
		return ;
	map[y][x] = '1';
	fille(m, map, y - 1, x);
	fille(m, map, y + 1, x);
	fille(m, map, y, x - 1);
	fille(m, map, y, x + 1);
}

void	flood_fill(t_khalifa *m)
{
	position(m);
	fill(m, m->flod, m->k.y, m->k.x);
	fille(m, m->flode, m->k.y, m->k.x);
}

void	path(t_khalifa *m)
{	
	int	i;
	int	j;

	flood_fill(m);
	i = 0;
	while (m->flod[i] && m->flode[i])
	{
		j = 0;
		while (m->flod[i][j] && m->flode[i][j])
		{
			if (m->flod[i][j] == 'C' || m->flode[i][j] == 'E')
			{
				write(1, "Eroor\ninvalide path", 20);
				exit(1);
			}
			j++;
		}
		i++;
	}
}
