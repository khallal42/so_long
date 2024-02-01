/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khallal <khallal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:52:26 by khallal           #+#    #+#             */
/*   Updated: 2022/12/28 18:17:59 by khallal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	wall(t_khalifa *m, char c)
{
	if (c == '1')
		m->path = "wall.xpm";
	else if (c == 'E')
	{
		if (m->coin != 0)
			m->path = "exit1.xpm";
		else if (m->coin == 0)
			m->path = "exitf.xpm";
	}
	else if (c == 'P')
		m->path = "player1.xpm";
	else if (c == 'C')
		m->path = "diamon1.xpm";
	else if (c == '0')
		m->path = "0.xpm";
	m->imag = mlx_xpm_file_to_image(m->mlx, m->path, &m->img_width,
			&m->img_height);
	mlx_put_image_to_window(m->mlx, m->win, m->imag, m->line, m->colone);
	mlx_destroy_image(m->mlx, m->imag);
}
