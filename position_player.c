/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khallal <khallal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:10:14 by khallal           #+#    #+#             */
/*   Updated: 2022/12/28 18:10:15 by khallal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	position(t_khalifa *m)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (m->map[i])
	{
		j = 0;
		while (m->map[i][j])
		{
			if (m->map[i][j] == 'P')
			{
				m->k.y = i;
				m->k.x = j;
				return ;
			}
			j++;
		}
		i++;
	}
}
