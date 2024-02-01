/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khallal <khallal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:11:22 by khallal           #+#    #+#             */
/*   Updated: 2023/01/08 11:33:49 by khallal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check(char *p)
{
	int	i;

	i = 0;
	while (p[i])
	{
		if (p[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	only_5_char(char *p)
{
	int	i;

	i = 0;
	while (p[i])
	{
		if (p[i] != '1' && p[i] != '0' && p[i] != 'E' && p[i] != 'C'
			&& p[i] != 'P' && p[i] != 'K' && p[i] != '\n')
		{
			write(2, "Error\nonly 6 char", 18);
			exit(1);
		}
		i++;
	}
	free(p);
	return (1);
}

int	ft_check1_lent(char **p)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(p[0]) - 1;
	while (p[i])
	{
		if (p[i][0] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (p[++i])
	{
		if (p[i][j] != '1')
			return (0);
	}
	i = 0;
	while (p[i + 1])
	{
		if (ft_strlen(p[i]) != ft_strlen(p[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

t_khalifa	*check2(char *k, t_khalifa *size)
{
	int	i;

	size->coin = 0;
	size->player = 0;
	size->exit = 0;
	i = 0;
	while (k[i])
	{
		if (k[i] == 'C')
			size->coin++;
		else if (k[i] == 'P')
			size->player++;
		else if (k[i] == 'E')
			size->exit++;
		i++;
	}
	return (size);
}

char	**check_map(int fd, t_khalifa *f)
{
	char	*k;
	char	**sp;

	k = get_next_line(fd);
	empty_map(k[0]);
	f = check2(k, f);
	empty_line(k);
	f->n_line = number_line(k);
	f->flod = ft_split(k, '\n');
	f->flode = ft_split(k, '\n');
	sp = ft_split(k, '\n');
	f->lent_line = ft_strlen(sp[0]);
	only_5_char(k);
	if (!check(sp[0]) || !check(sp[f->n_line]) || !ft_check1_lent(sp)
		|| f->lent_line == f->n_line + 1)
	{
		write(2, "Error\nSIDES NOT 1 or map not RECTANGULAR", 18);
		exit(1);
	}
	if (f->coin == 0 || f->exit != 1 || f->player != 1)
	{
		write(2, "Error\nwe need 1 player & 1 exit & (1 coin or more)", 51);
		exit(1);
	}
	return (sp);
}
