/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colection_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khallal <khallal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:11:41 by khallal           #+#    #+#             */
/*   Updated: 2022/12/28 21:46:01 by khallal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	collection(t_khalifa *m)
{
	static int	i;

	if (i == 30)
		m->imag = mlx_xpm_file_to_image(m->mlx, "diamon1", &m->img_width,
				&m->img_height);
	if (i == 60)
		m->imag = mlx_xpm_file_to_image(m->mlx, "diamon2", &m->img_width,
				&m->img_height);
	if (i == 90)
		m->imag = mlx_xpm_file_to_image(m->mlx, "diamon3", &m->img_width,
				&m->img_height);
	if (i == 120)
	{
		m->imag = mlx_xpm_file_to_image(m->mlx, "diamon4", &m->img_width,
				&m->img_height);
		i = 0;
	}
	mlx_put_image_to_window(m->mlx, m->win, m->imag, m->line, m->colone);
	i++;
	return (1);
}
