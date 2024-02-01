/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khallal <khallal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:12:41 by khallal           #+#    #+#             */
/*   Updated: 2022/12/28 21:47:15 by khallal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	*get_animation(void)
{
	static int	i;

	i++;
	if (i >= 0 && i <= 50)
		return ("diamon1.xpm");
	else if (i > 50 && i <= 100)
		return ("diamon2.xpm");
	else if (i > 100 && i <= 150)
		return ("diamon3.xpm");
	else if (i > 150 && i <= 200)
		return ("diamon4.xpm");
	else if (i > 200 && i <= 250)
		return ("diamon5.xpm");
	else if (i > 250)
		i = 0;
	return ("diamon1.xpm");
}

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
		m->path = get_animation();
	else if (c == '0')
		m->path = "0.xpm";
	else if (c == 'K')
		m->path = "enemy.xpm";
	m->imag = mlx_xpm_file_to_image(m->mlx, m->path, &m->img_width,
			&m->img_height);
	mlx_put_image_to_window(m->mlx, m->win, m->imag, m->line, m->colone);
	mlx_destroy_image(m->mlx, m->imag);
}
