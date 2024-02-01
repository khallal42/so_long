/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_enemy_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khallal <khallal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:58:55 by khallal           #+#    #+#             */
/*   Updated: 2022/12/28 21:46:45 by khallal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	enemy(t_khalifa *m)
{
	int	i;
	int	j;

	i = 0;
	while (m->map[i])
	{
		j = 0;
		while (m->map[i][j])
		{
			if (m->map[i][j] == 'K')
			{
				m->e.x = j;
				m->e.y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}
