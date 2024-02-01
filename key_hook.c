/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khallal <khallal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:01:14 by khallal           #+#    #+#             */
/*   Updated: 2022/12/29 10:32:09 by khallal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_down(t_khalifa *m)
{
	position(m);
	if (m->map[m->k.y + 1][m->k.x] == '1')
		return ;
	if (m->map[m->k.y + 1][m->k.x] == '0')
	{
		m->map[m->k.y][m->k.x] = '0';
		m->map[m->k.y + 1][m->k.x] = 'P';
	}
	if (m->map[m->k.y + 1][m->k.x] == 'C')
	{
		m->map[m->k.y][m->k.x] = '0';
		m->map[m->k.y + 1][m->k.x] = 'P';
		m->coin--;
	}
	if (m->map[m->k.y + 1][m->k.x] == 'E' && coin(m))
		exit(0);
	m->step++;
	m->k.y++;
	mlx_clear_window(m->mlx, m->win);
	creat_map(m);
}

void	key_left(t_khalifa *m)
{
	position(m);
	if (m->map[m->k.y][m->k.x - 1] == '1')
		return ;
	if (m->map[m->k.y][m->k.x - 1] == '0')
	{
		m->map[m->k.y][m->k.x] = '0';
		m->map[m->k.y][m->k.x - 1] = 'P';
	}
	if (m->map[m->k.y][m->k.x - 1] == 'C')
	{
		m->map[m->k.y][m->k.x] = '0';
		m->map[m->k.y][m->k.x - 1] = 'P';
		m->coin--;
	}
	if (m->map[m->k.y][m->k.x - 1] == 'E' && coin(m))
		exit(0);
	m->step++;
	m->k.x--;
	mlx_clear_window(m->mlx, m->win);
	creat_map(m);
}

void	key_right(t_khalifa *m)
{
	position(m);
	if (m->map[m->k.y][m->k.x + 1] == '1')
		return ;
	if (m->map[m->k.y][m->k.x + 1] == '0')
	{
		m->map[m->k.y][m->k.x] = '0';
		m->map[m->k.y][m->k.x + 1] = 'P';
	}
	if (m->map[m->k.y][m->k.x + 1] == 'C')
	{
		m->map[m->k.y][m->k.x] = '0';
		m->map[m->k.y][m->k.x + 1] = 'P';
		m->coin--;
	}
	if (m->map[m->k.y][m->k.x + 1] == 'E' && coin(m))
		exit(0);
	m->step++;
	m->k.x++;
	mlx_clear_window(m->mlx, m->win);
	creat_map(m);
}

void	key_up(t_khalifa *m)
{
	position(m);
	if (m->map[m->k.y - 1][m->k.x] == '1')
		return ;
	if (m->map[m->k.y - 1][m->k.x] == '0')
	{
		m->map[m->k.y][m->k.x] = '0';
		m->map[m->k.y - 1][m->k.x] = 'P';
	}
	if (m->map[m->k.y - 1][m->k.x] == 'C')
	{
		m->map[m->k.y][m->k.x] = '0';
		m->map[m->k.y - 1][m->k.x] = 'P';
		m->coin--;
	}
	if (m->map[m->k.y - 1][m->k.x] == 'E' && coin(m))
		exit(0);
	m->step++;
	m->k.y--;
	mlx_clear_window(m->mlx, m->win);
	creat_map(m);
}

int	key_hook(int keycode, t_khalifa *m)
{
	if (keycode == 0 || keycode == 123)
		key_left(m);
	else if (keycode == 1 || keycode == 125)
		key_down(m);
	else if (keycode == 2 || keycode == 124)
		key_right(m);
	else if (keycode == 13 || keycode == 126)
		key_up(m);
	else if (keycode == 53)
		exit(0);
	return (0);
}
