/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khallal <khallal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:12:33 by khallal           #+#    #+#             */
/*   Updated: 2023/01/08 11:42:52 by khallal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	creat_map(t_khalifa *m)
{
	int		x;
	char	*key;
	int		y;

	x = 0;
	y = 0;
	m->line = 0;
	m->colone = 0;
	while (m->map[y])
	{
		x = 0;
		m->line = 0;
		put_image(m, y);
		m->colone += 65;
		y++;
	}
	key = ft_itoa(m->step);
	mlx_string_put(m->mlx, m->win, 32, 32, 0x00FF0000, key);
	free(key);
	return (1);
}

int	close_win(t_khalifa *m)
{
	write(1, "you close the window", 21);
	mlx_destroy_window(m->mlx, m->win);
	exit(0);
}

int	loop_enemy(t_khalifa *m)
{
	static int	j;

	mlx_clear_window(m->mlx, m->win);
	if (j == 20)
	{
		enemy(m);
		if (m->map[m->e.y][m->e.x - 1] == '0')
		{
			m->map[m->e.y][m->e.x] = '0';
			m->map[m->e.y][m->e.x - 1] = 'K';
		}
		else if (m->map[m->e.y][m->e.x + 1] == '0')
		{
			m->map[m->e.y][m->e.x] = '0';
			m->map[m->e.y][m->e.x + 1] = 'K';
		}
		else if (m->map[m->e.y][m->e.x + 1] == 'P' || m->map[m->e.y][m->e.x
				- 1] == 'P')
			exit(0);
		j = 0;
	}
	j++;
	creat_map(m);
	return (1);
}

int	main(int ac, char **av)
{
	int			fd;
	t_khalifa	*m;

	m = malloc(sizeof(t_khalifa));
	check_arg(ac);
	check_map_name(av[1]);
	fd = open(av[1], O_RDONLY);
	check_fd(fd);
	m->map = check_map(fd, m);
	path(m);
	m->mlx = mlx_init();
	m->win = mlx_new_window(m->mlx, (m->lent_line) * 65, 65 * (m->n_line + 1),
			"so_long");
	mlx_loop_hook(m->mlx, loop_enemy, m);
	mlx_hook(m->win, 2, 0, key_hook, m);
	mlx_hook(m->win, 17, 0, close_win, m);
	mlx_loop(m->mlx);
}
