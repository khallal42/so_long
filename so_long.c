/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khallal <khallal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:26:10 by khallal           #+#    #+#             */
/*   Updated: 2023/01/08 11:43:21 by khallal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	putstr(char *k)
{
	int	i;

	i = 0;
	while (k[i])
	{
		write(1, &k[i], 1);
		i++;
	}
}

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
	putstr(key);
	putstr("\n");
	free(key);
	return (1);
}

int	close_win(t_khalifa *m)
{
	write(1, "you close the window", 21);
	mlx_destroy_window(m->mlx, m->win);
	exit(0);
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
	creat_map(m);
	mlx_hook(m->win, 2, 0, key_hook, m);
	mlx_hook(m->win, 17, 0, close_win, m);
	mlx_loop(m->mlx);
}
