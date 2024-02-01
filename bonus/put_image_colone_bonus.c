/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image_colone_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khallal <khallal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:12:23 by khallal           #+#    #+#             */
/*   Updated: 2022/12/28 21:46:59 by khallal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_img(t_khalifa *m, char c)
{
	wall(m, '0');
	wall(m, c);
}

void	put_image(t_khalifa *m, int y)
{
	int	x;

	x = -1;
	while (m->map[y][++x])
	{
		if (m->map[y][x] == '1')
			wall(m, '1');
		else if (m->map[y][x] == 'P')
			put_img(m, 'P');
		else if (m->map[y][x] == 'C')
			put_img(m, 'C');
		else if (m->map[y][x] == 'E')
			put_img(m, 'E');
		else if (m->map[y][x] == '0')
			wall(m, '0');
		else if (m->map[y][x] == 'K')
			put_img(m, 'K');
		m->line += 65;
	}
}
